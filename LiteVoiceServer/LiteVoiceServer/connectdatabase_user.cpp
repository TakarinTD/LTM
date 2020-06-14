//#include<mysql.h>
//#include "Manage.h"
//#include "User.h"
//#include<vector>
//#include<iostream>
//#include<string>
//
//using namespace std;
//int quser,iuser;
//int qgroup,igroup;
//string nameUser, avta, nameGroup;
//bool nhapUser=true,nhapGroup=true;
//
//int main() {
//	User user;
//	Group group;
//	MYSQL_ROW row;
//	MYSQL_RES *res;
//	Manage::Manage();
//	if (Manage::conn) {
//		puts("Successful connection!");
//		while (nhapUser == true) {
//			getline(cin, nameUser);
//			getline(cin, avta);
//			string insUser = "INSERT INTO user (user_name, user_avt) VALUES ( '" + nameUser + "', '" + avta + "')";
//			const char* i_user = insUser.c_str();
//			iuser = mysql_query(Manage::conn, i_user);
//			nhapUser = false;
//		}
//		string query_user = "SELECT * FROM user";
//		const char* q_user = query_user.c_str();
//		quser = mysql_query(Manage::conn, q_user);
//		
//		if (!quser)
//		{
//			res = mysql_store_result(Manage::conn);
//			while (row = mysql_fetch_row(res))
//			{
//				user.name=row[0];
//				user.avaPath=row[1];
//				Manage::users.push_back(user);
//			}
//		}
//		else
//		{
//			cout << "Query user failed: " << mysql_error(Manage::conn) << endl;
//		}
//		while (nhapGroup == true) {
//			getline(cin, nameGroup);
//			string insGroup = "INSERT INTO lite_voice.group (group_name) VALUES ( '" + nameGroup + "')";
//			const char* i_Group = insGroup.c_str();
//			igroup = mysql_query(Manage::conn, i_Group);
//			nhapGroup = false;
//		}
//		string query_group = "SELECT * FROM lite_voice.group";
//		const char* q_group = query_group.c_str();
//		qgroup = mysql_query(Manage::conn, q_group);
//		if(!qgroup){
//			res = mysql_store_result(Manage::conn);
//			while (row = mysql_fetch_row(res))
//			{
//				group.name = row[0];
//				Manage::groups.push_back(group);
//			}
//		}
//		else
//		{
//			cout << "Query group failed: " << mysql_error(Manage::conn) << endl;
//		}
//	}
//	else {
//		puts("Connection failed!");
//	}
//
//	for (auto it : Manage::users) {
//		printf("userName: %s, userAvt: %s\n", it.name, it.avaPath);
//	}
//	for (auto it : Manage::groups) {
//		printf("groupName: %s\n", it.name);
//	}
//	return 0;
//}