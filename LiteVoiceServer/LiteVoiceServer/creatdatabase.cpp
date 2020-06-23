//#include<mysql.h>
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//#include<iostream>
//using namespace std;
//int main() {
//	try {
//		sql::Driver *driver;
//		sql::Connection *con;
//		sql::Statement *stmt;
//		sql::ResultSet *res;
//
//		/* Create a connection */
//		driver = get_driver_instance();
//		con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
//		/* Connect to the MySQL test database */
//		con->setSchema("lite");
//		stmt = con->createStatement();
//		stmt->execute("USE lite_voice");
//		stmt->execute("CREATE TABLE friend(user_name1 VARCHAR(255), user_name2 VARCHAR(255), isblock INT");
//		stmt->execute("CREATE TABLE group(group_name VARCHAR(255)");
//		stmt->execute("CREATE TABLE member(group_name VARCHAR(255),user_name VARCHAR(255)");
//		stmt->execute("CREATE TABLE user(user_name VARCHAR(255),user_avt VARCHAR(455),password VARCHAR(45)");
//		stmt->execute("CREATE TABLE message_user(user_send VARCHAR(255), user_receive VARCHAR(255), content VARCHAR(2048),time VARCHAR(45)");
//		stmt->execute("CREATE TABLE message_user(user_send VARCHAR(255), group_receive VARCHAR(255), content VARCHAR(2048),time VARCHAR(45)");
//	}
//	catch (sql::SQLException &e) {
//		cout << "# ERR: SQLException in " << __FILE__;
//		cout << "(" << __FUNCTION__ << ") on line "<< __LINE__ << endl;
//		cout << "# ERR: " << e.what();
//		cout << " (MySQL error code: " << e.getErrorCode();
//		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//	}
//
//}