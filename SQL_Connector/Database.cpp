#include "Database.h"

Database *Database::instance = 0;

Database::Database() : driver(get_driver_instance()) {
	connection_properties["hostName"] = DB_HOST;
	connection_properties["port"] = DB_PORT;
	connection_properties["userName"] = DB_USER;
	connection_properties["password"] = DB_PASS;
	connection_properties["OPT_RECONNECT"] = true;
	
	// use database
	try {
		Connection *con = driver->connect(connection_properties);
		try {
			con->setSchema(DB_NAME);
		}
		catch (SQLException &e) {
			Statement *stmt = con->createStatement();
			stmt->execute("CREATE DATABASE IF NOT EXISTS book_store");
			/*con->setSchema(DB_NAME); // switch database
			
			stmt->execute("CREATE TABLE IF NOT EXISTS buildings ( "
				"building_num INT UNSIGNED PRIMARY KEY, "
				"building_name VARCHAR(50), "
				"floors INT, "
				"city VARCHAR(50), "
				"street VARCHAR(50), "
				"street_num INT "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS classrooms("
				"building_num INT UNSIGNED, "
				"class_num INT UNSIGNED, "
				"floor INT, "
				"PRIMARY KEY(class_num, building_num), "
				"FOREIGN KEY(building_num) references buildings(building_num) "
				"ON DELETE RESTRICT "
				"ON UPDATE RESTRICT "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS lecturers ( "
				"id VARCHAR(9) PRIMARY KEY, "
				"firstname VARCHAR(20), "
				"lastname VARCHAR(20), "
				"city VARCHAR(50), "
				"street VARCHAR(50), "
				"street_num INT, "
				"birth_date DATE "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS phones ( "
				"lecturer_id VARCHAR(9), "
				"label VARCHAR(20), "
				"country_code VARCHAR(5), "
				"phone VARCHAR(10), "
				"PRIMARY KEY(phone, country_code), "
				"FOREIGN KEY(lecturer_id) references lecturers(id) "
				"ON DELETE CASCADE "
				"ON UPDATE CASCADE "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS courses ("
				"course_num VARCHAR(20), "
				"course_year ENUM('a', 'b', 'c', 'd'), "
				"course_semester ENUM('winter', 'spring', 'summer'), "
				"course_name VARCHAR(50), "
				"lecturer_id VARCHAR(9), "
				"weekly_hours TINYINT UNSIGNED, "
				"PRIMARY KEY(course_num, course_semester), "
				"FOREIGN KEY(lecturer_id) references lecturers(id) "
				"ON DELETE RESTRICT "
				"ON UPDATE RESTRICT "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS lectures ( "
				"building_num INT UNSIGNED, "
				"class_num INT UNSIGNED, "
				"course_num VARCHAR(20), "
				"course_semester ENUM('winter', 'spring', 'summer'), "
				"start_date DATETIME, "
				"end_date DATETIME, "
				"FOREIGN KEY(building_num, class_num) references classrooms(building_num, class_num) "
				"ON DELETE RESTRICT "
				"ON UPDATE RESTRICT, "
				"FOREIGN KEY(course_num, course_semester) references courses(course_num, course_semester) "
				"ON DELETE RESTRICT "
				"ON UPDATE RESTRICT, "
				"CHECK(end_date > start_date))");
			*/
			delete stmt;
		}

		delete con;
	}
	catch (SQLException &e) {
		cout << e.getErrorCode() << " " << e.what() << " " << e.getSQLState();
	}
}

Database & Database::getInstance() {
	if (Database::instance == 0) {
		instance = new Database();
	}
	return *instance;
}

Connection * Database::getConnection() {
	try {
		Connection *con = driver->connect(connection_properties);
		con->setSchema(DB_NAME);
		return con;
	} catch (SQLException &e) {
		cout << e.what();
	}
	return 0;
}
