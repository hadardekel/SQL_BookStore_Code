// SQL_Connector.cpp : Defines the entry point for the console application.
// Hadar Dekel, 200480051

#include "Database.h"
#include <string>
#include <iostream>
#include <stdio.h>


using namespace std;

void printStartMenu(void);
void query1(Database& db, Connection *con, Statement *stmt);
void query2(Database& db, Connection *con, Statement *stmt);
void query3(Database& db, Connection *con, Statement *stmt);
void query4(Database& db, Connection *con, Statement *stmt);
void query5(Database& db, Connection *con, Statement *stmt);
void query6(Database& db, Connection *con, Statement *stmt);
void query7(Database& db, Connection *con, Statement *stmt);
void query8(Database& db, Connection *con, Statement *stmt);
void query9(Database& db, Connection *con, Statement *stmt);
void query10(Database& db, Connection *con, Statement *stmt);
void query11(Database& db, Connection *con, Statement *stmt);
void query12(Database& db, Connection *con, Statement *stmt);
void query13(Database& db, Connection *con, Statement *stmt);
void query14(Database& db, Connection *con, Statement *stmt);
void query15(Database& db, Connection *con, Statement *stmt);
void query16(Database& db, Connection *con, Statement *stmt);
void query17(Database& db, Connection *con, Statement *stmt);
void query18(Database& db, Connection *con, Statement *stmt);
void query19(Database& db, Connection *con, Statement *stmt);
void query20(Database& db, Connection *con, Statement *stmt);


int main()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	con->setSchema("book_store");
	Statement *stmt = con->createStatement();
	int menu;
	bool fContinue = true;

	printStartMenu();

	do {
		cout << "please enter your choice: " << endl;
		cin >> menu;

		switch (menu)
		{
		case(1):
			query1(db, con, stmt);
			break;
		case(2):
			query2(db, con, stmt);
			break;
		case(3):
			query3(db, con, stmt);
			break;
		case(4):
			query4(db, con, stmt);
			break;
		case(5):
			query5(db, con, stmt);
			break;
		case(6):
			query6(db, con, stmt);
			break;
		case(7):
			query7(db, con, stmt);
			break;
		case(8):
			query8(db, con, stmt);
			break;
		case(9):
			query9(db, con, stmt);
			break;
		case(10):
			query10(db, con, stmt);
			break;
		case(11):
			query11(db, con, stmt);
			break;
		case(12):
			query12(db, con, stmt);
			break;
		case(13):
			query13(db, con, stmt);
			break;
		case(14):
			query14(db, con, stmt);
			break;
		case(15):
			query15(db, con, stmt);
			break;
		case(16):
			query16(db, con, stmt);
			break;
		case(17):
			query17(db, con, stmt);
			break;
		case(18):
			query18(db, con, stmt);
			break;
		case(19):
			query19(db, con, stmt);
			break;
		case(20):
			query20(db, con, stmt);
			break;
		case(98):
			printStartMenu();
			break;
		case(99):
			cout << "\nGoodBye, hope to see you soon :) \n";
			fContinue = false;
			break;
		default:
			cout << "invalid option\n";
			break;
		}
	} while (fContinue);
	
	delete con;
	delete stmt;
    return 0;
}


void printStartMenu(void)
{
	cout << "------------------------------\n";
	cout << "Welcome to HADAR's book store!\n";
	cout << "------------------------------\n";
	cout << "  1 --> Show Books in Stock\n";
	cout << "  2 --> Show Open Orders\n";
	cout << "  3 --> Show Customer List\n";
	cout << "  4 --> Show Supplier List\n";
	cout << "  5 --> Show Purchases between Selected Dates\n";
	cout << "  6 --> Show Books with Disount\n";
	cout << "  7 --> Check Stock\n";
	cout << "  8 --> Check Book's Suplliers\n";
	cout << "  9 --> Check Book's Purchases\n";
	cout << " 10 --> Check Customer Purchases\n";
	cout << " 11 --> Show the Best Customer\n";
	cout << " 12 --> Show the Best Supplier\n";
	cout << " 13 --> Count Orders\n";
	cout << " 14 --> Count Purchases from Orders\n";
	cout << " 15 --> Show Discount for Customer\n";
	cout << " 16 --> Show Sales per Quarter\n";
	cout << " 17 --> Count New Customers\n";
	cout << " 18 --> Purchases from Supplier\n";
	cout << " 19 --> Purchases for Employee\n";
	cout << " 20 --> Top 10 Sellers\n";
	cout << " 98 --> Show Menu\n";
	cout << " 99 --> Exit\n";
	cout << "------------------------------\n";
}

void query1(Database& db, Connection *con, Statement *stmt)
{
	int i1, i2;
	string s1, s2;
	ResultSet *rset = NULL;

	rset = stmt->executeQuery("SELECT STOCK.book_id, BOOK.book_name, BOOK.author, STOCK.quantity FROM STOCK inner join BOOK on(STOCK.book_id = BOOK.book_id)");
	cout << "all the books in stock" << endl;
	cout << "----------------------" << endl;
	rset->beforeFirst();
	while (rset->next()) {
		i1 = rset->getInt("book_id");
		s1 = rset->getString("book_name");
		s2 = rset->getString("author");
		i2 = rset->getInt("quantity");
		cout << "id: " << i1 << ", name: " << s1 << ", author: " << s2 << ", quantity: " << i2 << endl;
	}
	cout << endl;

	delete rset;
}


void query2(Database& db, Connection *con, Statement *stmt)
{
	int i1, i2;
	string s1, s2, s3, s4, s5, s6;
	ResultSet *rset = NULL;

	rset = stmt->executeQuery("SELECT o.order_date, os.order_status_name, b.book_id, b.book_name, b.author, c.cust_name, c.cust_phone FROM ORDERS o	inner join BOOK b on(o.book_id = b.book_id)	inner join CUSTOMER c on(o.cust_id = c.cust_id) inner join ORDER_STATUS os on(o.order_status_id = os.order_status_id) where os.order_status_id <> 4");
	cout << "all the open orders" << endl;
	cout << "-------------------" << endl;
	rset->beforeFirst();
	while (rset->next()) {
		s1 = rset->getString("order_date");
		s2 = rset->getString("order_status_name");
		i1 = rset->getInt("book_id");
		s3 = rset->getString("book_name");
		s4 = rset->getString("author");
		s5 = rset->getString("cust_name");
		s6 = rset->getString("cust_phone");
		cout << "order date: " << s1 << ", status: " << s2 << ", book id: " << i1 << ", book name: " << s3 << ", author: " << s4 << ", customer: " << s5 << ", phone: " << s6 << endl;
	}
	cout << endl;

	delete rset;
}

void query3(Database& db, Connection *con, Statement *stmt)
{
	int i1;
	string s1, s2, s3;
	ResultSet *rset = NULL;

	rset = stmt->executeQuery("SELECT cust_id, cust_name, cust_creation_date, cust_phone FROM CUSTOMER where had_purchased = 1");
	cout << "our customers" << endl;
	cout << "-------------" << endl;
	rset->beforeFirst();
	while (rset->next()) {
		i1 = rset->getInt("cust_id");
		s1 = rset->getString("cust_name");
		s2 = rset->getString("cust_creation_date");
		s3 = rset->getString("cust_phone");
		cout << "id: " << i1 << ", name: " << s1 << ", phone: " << s3 << ", creation date: " << s2 << endl;
	}
	cout << endl;

	delete rset;
}


void query4(Database& db, Connection *con, Statement *stmt)
{
	int i1;
	string s1;
	ResultSet *rset = NULL;

	rset = stmt->executeQuery("SELECT supp_id, supp_name FROM SUPPLIER");
	cout << "our suppliers" << endl;
	cout << "-------------" << endl;
	rset->beforeFirst();
	while (rset->next()) {
		i1 = rset->getInt("supp_id");
		s1 = rset->getString("supp_name");
		cout << "id: " << i1 << ", name: " << s1 << endl;
	}
	cout << endl;

	delete rset;
}

void query5(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int check, i1, i2;
	string s1, s2, s3, s4, s5, start_year, start_month, start_day, start_date, end_year, end_month, end_day, end_date;

	cout << "please enter start date in this format: year month day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";

	cout << "please enter end date in this format: year month day" << endl;
	cin >> end_year >> end_month >> end_day;
	if (end_month.length() < 2)
		end_month = "0" + end_month;
	if (end_day.length() < 2)
		end_day = "0" + end_day;
	end_date = end_year + "-" + end_month + "-" + end_day + " 00:00:00";

	pstmt = con->prepareStatement("SELECT p.PURCHASE_ID,p.purchase_date, ps.purchase_status_name, p.purchase_amount,b.book_name, c.cust_name, e.emp_name FROM PURCHASES p inner join PURCHASE_STATUS ps	on(p.purchase_status_id = ps.purchase_status_id) inner join book b on(p.book_id = b.book_id) inner join CUSTOMER c on(p.cust_id = c.cust_id) inner join EMPLOYEE e on(p.emp_id = e.emp_id) WHERE p.purchase_date between ? and ?");
	pstmt->setString(1, start_date);
	pstmt->setString(2, end_date);
	rset = pstmt->executeQuery();
	rset->beforeFirst();
	cout << "all purchases between selected dates" << endl;
	cout << "------------------------------------" << endl;
	while (rset->next()) {
		i1 = rset->getInt("purchase_id");
		s1 = rset->getString("purchase_date");
		s2 = rset->getString("purchase_status_name");
		i2 = rset->getInt("purchase_amount");
		s3 = rset->getString("book_name");
		s4 = rset->getString("cust_name");
		s5 = rset->getString("emp_name");
		cout << "id: " << i1 << ", date: " << s1 << ", status: " << s2 << ", amount: " << i2 << ", book: " << s3 << ", customer: " << s4 << ", employee: " << s5 << endl;
	}
	cout << endl;

	delete pstmt;
	delete rset;
}


void query6(Database& db, Connection *con, Statement *stmt)
{
	int i1, i2;
	string s1, s2;
	ResultSet *rset = NULL;

	rset = stmt->executeQuery("SELECT b.book_id, b.book_name, b.author, s.global_discount FROM STOCK s inner join book b on(s.book_id = b.book_id)	WHERE s.global_discount > 0");
	cout << "books with discount" << endl;
	cout << "-------------------" << endl;
	rset->beforeFirst();
	while (rset->next()) {
		i1 = rset->getInt("book_id");
		s1 = rset->getString("book_name");
		s2 = rset->getString("author");
		i2 = rset->getInt("global_discount");
		cout << "id: " << i1 << ", name: " << s1 << ", author: " << s2 << ", discount:" << i2 << "%" << endl;
	}
	cout << endl;

	delete rset;
}

void query7(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1, i2, check;
	string s1, s2;
	char name[100];

	cin.ignore();
	cout << "please enter author or name of book" << endl;
	cin.getline(name, 100);
	i2 = 0;
	check = 0;
	pstmt = con->prepareStatement("SELECT b.book_id, b.book_name, b.author, s.quantity FROM BOOK b left join STOCK s on (b.book_id = s.book_id) WHERE b.author = ? OR b.book_name = ?");
	pstmt->setString(1, name);
	pstmt->setString(2, name);
	rset = pstmt->executeQuery();
	rset->beforeFirst();
	cout << "is book in stock" << endl;
	cout << "----------------" << endl;
	while (rset->next()) {
		i1 = rset->getInt("book_id");
		s1 = rset->getString("book_name");
		s2 = rset->getString("author");
		i2 = rset->getInt("quantity");
		if (i2 == 0)
			cout << s1 << " by " << s2 << ": not in stock" << endl;
		else
			cout << s1 << " by " << s2 << ": in stock" << endl;
		check++;
	}
	if (check == 0)
		cout << "could not find book" << endl;
	cout << endl;

	delete pstmt;
	delete rset;
}


void query8(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1, i2, check;
	string s1, s2, s3;
	char name[100];

	cin.ignore();
	cout << "please enter author or name of book" << endl;
	cin.getline(name, 100);
	check = 0;
	pstmt = con->prepareStatement("SELECT b.book_name, b.author, s.supp_id, s.supp_name FROM BOOK b left join CAN_SUPPLY cs on(cs.book_id = b.book_id) left join SUPPLIER s on(cs.supp_id = s.supp_id)	WHERE b.author = ? OR b.book_name = ?");
	pstmt->setString(1, name);
	pstmt->setString(2, name);
	rset = pstmt->executeQuery();
	rset->beforeFirst();
	cout << "list of suppliers" << endl;
	cout << "-----------------" << endl;
	while (rset->next()) {
		s1 = rset->getString("book_name");
		s2 = rset->getString("author");
		i2 = rset->getInt("supp_id");
		s3 = rset->getString("supp_name");
		cout << s1 << " by " << s2 << ": " << i2 << "-" << s3 << endl;
		check++;
	}
	if (check == 0)
		cout << "could not find book" << endl;
	cout << endl;


	delete pstmt;
	delete rset;
}


void query9(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1, check;
	string s1, s2, start_year, start_month, start_day, start_date;
	char name[100];

	cin.ignore();
	cout << "please enter author or name of book" << endl;
	cin.getline(name, 100);
	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";
	i1 = 0;
	check = 0;

	pstmt = con->prepareStatement("SELECT b.book_name, b.author, count(distinct p.purchase_id) purchases_count FROM BOOK b left join PURCHASES p on(p.book_id = b.book_id and p.purchase_date > ?) WHERE b.book_name = ? or b.author = ?");
	pstmt->setString(1, start_date);
	pstmt->setString(2, name);
	pstmt->setString(3, name);
	rset = pstmt->executeQuery();
	rset->beforeFirst();
	cout << "purchases from " << start_date << endl;
	cout << "----------------------------------" << endl;
	while (rset->next()) {
		s1 = rset->getString("book_name");
		s2 = rset->getString("author");
		i1 = rset->getInt("purchases_count");
		cout << i1;
		if (i1 > 1)
			cout << " copies of ";
		else
			cout << " copy of ";
		cout<< s1 << " by " << s2 << endl;
		check++;
	}
	if (check == 0)
		cout << "could not find book" << endl;
	cout << endl;

	delete pstmt;
	delete rset;
}

void query10(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1, i2, check;
	string s1, s2, start_year, start_month, start_day, start_date;
	char name[100];

	cin.ignore();
	cout << "please enter customer details" << endl;
	cin.getline(name, 100);
	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";
	i2 = 0;
	check = 0;

	pstmt = con->prepareStatement("SELECT c.cust_id, c.cust_name, c.cust_phone, count(distinct p.purchase_id) purchases_count FROM CUSTOMER c left join PURCHASES p on(c.cust_id = p.cust_id and p.purchase_date > ?) WHERE c.cust_name = ? or c.cust_id = ? or c.cust_phone = ? GROUP BY c.cust_id, c.cust_name, c.cust_phone");
	pstmt->setString(1, start_date);
	pstmt->setString(2, name);
	pstmt->setString(3, name);
	pstmt->setString(4, name);
	rset = pstmt->executeQuery();
	cout << "purchases by customer" << endl;
	cout << "---------------------" << endl;
	if (rset->rowsCount() == 1) {
		rset->first();
		i1 = rset->getInt("cust_id");
		s1 = rset->getString("cust_name");
		s2 = rset->getString("cust_phone");
		i2 = rset->getInt("purchases_count");
		cout << s1 << " bought " << i2 << " books" << endl;
		check++;
	}
	if (check == 0)
		cout << "could not find customer" << endl;
	cout << endl;

	delete pstmt;
	delete rset;
}


void query11(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1, i2;
	string s1, s2, start_year, start_month, start_day, start_date;

	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";
	i2 = 0;

	pstmt = con->prepareStatement("SELECT c.cust_id, c.cust_name, c.cust_phone, count(distinct p.purchase_id) purchases_count FROM CUSTOMER c join PURCHASES p on(c.cust_id = p.cust_id) WHERE p.purchase_date > ? GROUP BY c.cust_id, c.cust_name, c.cust_phone ORDER BY purchases_count DESC LIMIT 1");
	pstmt->setString(1, start_date);
	rset = pstmt->executeQuery();
	cout << "the best customer" << endl;
	cout << "-----------------" << endl;
	if (rset->rowsCount() == 1) {
		rset->first();
		i1 = rset->getInt("cust_id");
		s1 = rset->getString("cust_name");
		s2 = rset->getString("cust_phone");
		i2 = rset->getInt("purchases_count");
		cout << i1 << "-" << s1 << ", phone:" << s2 << " bought " << i2 << " books" << endl;
	}
	cout << endl;

	delete pstmt;
	delete rset;
}

void query12(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1, i2;
	string s1, s2, start_year, start_month, start_day, start_date;
	
	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";
	i2 = 0;

	pstmt = con->prepareStatement("SELECT s.supp_id, s.supp_name, sum(sp.quantity) quantity_count FROM SUPPLIER s join SUPPLIES sp on(s.supp_id = sp.supp_id) WHERE	sp.supply_date > ? GROUP BY s.supp_id, s.supp_name ORDER BY quantity DESC LIMIT 1");
	pstmt->setString(1, start_date);
	rset = pstmt->executeQuery();
	cout << "the supplier who supplied the biggest amount of books" << endl;
	cout << "-----------------------------------------------------" << endl;
	if (rset->rowsCount() == 1) {
		rset->first();
		i1 = rset->getInt("supp_id");
		s1 = rset->getString("supp_name");
		i2 = rset->getInt("quantity_count");
		cout << i1 << "-" << s1 << " supplied " << i2 << " books" << endl;
	}
	cout << endl;


	delete pstmt;
	delete rset;
}

void query13(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1, i2;
	string s1, s2, start_year, start_month, start_day, start_date, end_year, end_month, end_day, end_date;

	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";

	cout << "please enter end date in this format: year, month, day" << endl;
	cin >> end_year >> end_month >> end_day;
	if (end_month.length() < 2)
		end_month = "0" + end_month;
	if (end_day.length() < 2)
		end_day = "0" + end_day;
	end_date = end_year + "-" + end_month + "-" + end_day + " 00:00:00";
	i1 = 0;

	pstmt = con->prepareStatement("SELECT count(order_id) order_count FROM ORDERS WHERE	order_date between ? and ?");
	pstmt->setString(1, start_date);
	pstmt->setString(2, end_date);
	rset = pstmt->executeQuery();
	cout << "orders count" << endl;
	cout << "------------" << endl;
	if (rset->rowsCount() == 1) {
		rset->first();
		i1 = rset->getInt("order_count");
		cout << i1 << endl;
	}
	cout << endl;

	delete pstmt;
	delete rset;
}

void query14(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1;
	string start_year, start_month, start_day, start_date, end_year, end_month, end_day, end_date;

	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";

	cout << "please enter end date in this format: year, month, day" << endl;
	cin >> end_year >> end_month >> end_day;
	if (end_month.length() < 2)
		end_month = "0" + end_month;
	if (end_day.length() < 2)
		end_day = "0" + end_day;
	end_date = end_year + "-" + end_month + "-" + end_day + " 00:00:00";
	i1 = 0;

	pstmt = con->prepareStatement("SELECT count(order_id) order_count FROM ORDERS WHERE	order_status_id = 4 and order_date between ? and ?");
	pstmt->setString(1, start_date);
	pstmt->setString(2, end_date);
	rset = pstmt->executeQuery();
	cout << "purchases from orders count" << endl;
	cout << "---------------------------" << endl;
	if (rset->rowsCount() == 1) {
		rset->first();
		i1 = rset->getInt("order_count");
		cout << i1 << endl;
	}
	cout << endl;

	delete pstmt;
	delete rset;
}

void query15(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int check;
	double i1;
	string start_year, start_month, start_day, start_date;
	char name[100];

	cin.ignore();
	cout << "please enter customer details" << endl;
	cin.getline(name, 100);
	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";
	i1 = 0.0;
	check = 0;

	pstmt = con->prepareStatement("SELECT sum(p.purchase_amount*p.cust_discount/100) discount_amount FROM PURCHASES p join CUSTOMER c on(p.cust_id = c.cust_id)	WHERE p.cust_discount > 0 and p.purchase_date >= ? and (c.cust_name = ? or c.cust_id = ? or c.cust_phone = ?)");
	pstmt->setString(1, start_date);
	pstmt->setString(2, name);
	pstmt->setString(3, name);
	pstmt->setString(4, name);
	rset = pstmt->executeQuery();
	cout << "discount amount for customer" << endl;
	cout << "----------------------------" << endl;
	if (rset->rowsCount() == 1) {
		rset->first();
		i1 = rset->getDouble("discount_amount");
		cout << i1 << " ILS" << endl;
		check++;
	}
	if (check == 0)
		cout << "could not find customer" << endl;
	cout << endl;

	delete pstmt;
	delete rset;
}

void query16(Database& db, Connection *con, Statement *stmt)
{
	int i1;
	double i2;
	ResultSet *rset = NULL;	

	rset = stmt->executeQuery("SELECT purchase_quarter, sum(amount_after_dis) amount FROM(SELECT p.purchase_date, year(p.purchase_date) * 100 + quarter(p.purchase_date) purchase_quarter,p.purchase_amount, p.cust_discount, p.purchase_amount*(100 - p.cust_discount) / 100 amount_after_dis FROM	PURCHASES p WHERE p.purchase_status_id = 1) t GROUP BY purchase_quarter ORDER BY 1");
	cout << "sales for each quarter" << endl;
	cout << "----------------------" << endl;
	rset->beforeFirst();
	while (rset->next()) {
		i1 = rset->getInt("purchase_quarter");
		i2 = rset->getDouble("amount");
		cout << i1 << ": " << i2 << " ILS" << endl;
	}
	cout << endl;

	delete rset;
}

void query17(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1, check;
	string start_year, start_month, start_day, start_date;

	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";
	i1 = 0;

	pstmt = con->prepareStatement("SELECT count(cust_id) cust_count FROM CUSTOMER WHERE cust_creation_date >= ?");
	pstmt->setString(1, start_date);
	rset = pstmt->executeQuery();
	cout << "new customer count" << endl;
	cout << "------------------" << endl;
	if (rset->rowsCount() == 1) {
		rset->first();
		i1 = rset->getInt("cust_count");
		cout << i1 << endl;
	}
	cout << endl;

	delete pstmt;
	delete rset;
}

void query18(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1;
	string s1, start_year, start_month, start_day, start_date, end_year, end_month, end_day, end_date;

	cout << "please enter supplier id" << endl;
	cin >> s1;

	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";

	cout << "please enter end date in this format: year, month, day" << endl;
	cin >> end_year >> end_month >> end_day;
	if (end_month.length() < 2)
		end_month = "0" + end_month;
	if (end_day.length() < 2)
		end_day = "0" + end_day;
	end_date = end_year + "-" + end_month + "-" + end_day + " 00:00:00";
	i1 = 0;

	pstmt = con->prepareStatement("SELECT sum(total) amount FROM(SELECT sp.book_id, sp.quantity, cs.price, sp.quantity*cs.price total FROM SUPPLIES sp inner join SUPPLIER s on(sp.supp_id = s.supp_id) left join CAN_SUPPLY cs	on(sp.supp_id = cs.supp_id and sp.book_id = cs.book_id)	WHERE sp.supply_date between ? and ? and s.supp_id = ?) t");
	pstmt->setString(1, start_date);
	pstmt->setString(2, end_date);
	pstmt->setString(3, s1);
	rset = pstmt->executeQuery();
	cout << "purchases from supplier" << endl;
	cout << "-----------------------" << endl;
	if (rset->rowsCount() == 1) {
		rset->first();
		i1 = rset->getInt("amount");
		cout << i1 << " ILS" << endl;
	}
	else 
		cout << "could not find supplier" << endl;
	cout << endl;

	delete pstmt;
	delete rset;
}


void query19(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int check, i1;
	string start_year, start_month, start_day, start_date, end_year, end_month, end_day, end_date;
	char name[100];

	cin.ignore();
	cout << "please enter employee id or name" << endl;
	cin.getline(name, 100);

	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";

	cout << "please enter end date in this format: year, month, day" << endl;
	cin >> end_year >> end_month >> end_day;
	if (end_month.length() < 2)
		end_month = "0" + end_month;
	if (end_day.length() < 2)
		end_day = "0" + end_day;
	end_date = end_year + "-" + end_month + "-" + end_day + " 00:00:00";
	i1 = 0;

	pstmt = con->prepareStatement("SELECT count(distinct p.purchase_id) purchase_count FROM PURCHASES p	inner join EMPLOYEE e on(p.emp_id = e.emp_id) WHERE	p.purchase_date between ? and ? and (e.emp_id = ? or e.emp_name = ?)");
	pstmt->setString(1, start_date);
	pstmt->setString(2, end_date);
	pstmt->setString(3, name);
	pstmt->setString(4, name);
	rset = pstmt->executeQuery();
	cout << "employee sales" << endl;
	cout << "--------------" << endl;
	if (rset->rowsCount() == 1) {
		rset->first();
		i1 = rset->getInt("purchase_count");
		cout << i1 << " sales" << endl;
	}
	else {
		cout << "0 sales" << endl;
	}
	cout << endl;

	delete pstmt;
	delete rset;
}

void query20(Database& db, Connection *con, Statement *stmt)
{
	ResultSet *rset = NULL;
	PreparedStatement *pstmt = NULL;
	int i1, i2, i3;
	string s1, s2, start_year, start_month, start_day, start_date, end_year, end_month, end_day, end_date;

	cout << "please enter start date in this format: year, month, day" << endl;
	cin >> start_year >> start_month >> start_day;
	if (start_month.length() < 2)
		start_month = "0" + start_month;
	if (start_day.length() < 2)
		start_day = "0" + start_day;
	start_date = start_year + "-" + start_month + "-" + start_day + " 00:00:00";

	cout << "please enter end date in this format: year, month, day" << endl;
	cin >> end_year >> end_month >> end_day;
	if (end_month.length() < 2)
		end_month = "0" + end_month;
	if (end_day.length() < 2)
		end_day = "0" + end_day;
	end_date = end_year + "-" + end_month + "-" + end_day + " 00:00:00";

	pstmt = con->prepareStatement("SELECT b.book_id, b.book_name, b.author, count(distinct p.purchase_id) purchase_count FROM BOOK b join PURCHASES p on (b.book_id = p.book_id) WHERE p.purchase_date between ? and ? GROUP BY b.book_id, b.book_name, b.author ORDER BY 4 DESC LIMIT 10");
	pstmt->setString(1, start_date);
	pstmt->setString(2, end_date);
	rset = pstmt->executeQuery();
	cout << "top sellers" << endl;
	cout << "-----------" << endl;
	rset->beforeFirst();
	i3 = 1;
	while (rset->next()) {
		i1 = rset->getInt("book_id");
		s1 = rset->getString("book_name");
		s2 = rset->getString("author");
		i2 = rset->getInt("purchase_count");
		cout << i3 << ") " << i1 << "-" << s1 << " by " << s2 << ": " << i2;
		if (i2 > 1)
			cout << " copies" << endl;
		else
			cout << " copy" << endl;
		i3++;
	}
	cout << endl;

	delete pstmt;
	delete rset;
}