#include "Manage.h"

MYSQL* Manage::conn = NULL;
MYSQL_ROW Manage::row = {};
MYSQL_RES* Manage::res = NULL;
vector<User> Manage::users = {};
vector<Group> Manage::groups = {};
vector<Message> messages = {};
vector<MemberGroup> Mgs = {};
vector<Friend> friends = {};
vector<MemberGroup> Gms = {};

Manage::Manage() {
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "root", "lite_voice", 3306, NULL, 0);
}

vector<User> Manage::SelectUser(string name) {
	User user;
	puts("Successful connection!");
	string query_user = "SELECT * FROM user WHERE user.name_user LIKE\"";
	query_user += name + "%\"";
	const char* q_user = query_user.c_str();
	int quser = mysql_query(Manage::conn, q_user);
	if (!quser)
	{
		Manage::res = mysql_store_result(Manage::conn);
		while (Manage::row = mysql_fetch_row(Manage::res))
		{
			user.name = Manage::row[0];
			user.avaPath = Manage::row[1];
			Manage::users.push_back(user);
		}
	}
	else
	{
		cout << "Query user failed: " << mysql_error(Manage::conn) << endl;
	}

	return Manage::users;
}
vector<User> Manage::SelectAllUser() {
	User user;
	puts("Successful connection!");
	string query_user = "SELECT * FROM user";
	const char* q_user = query_user.c_str();
	int quser = mysql_query(Manage::conn, q_user);
	if (!quser)
	{
		Manage::res = mysql_store_result(Manage::conn);
		while (Manage::row = mysql_fetch_row(Manage::res))
		{
			user.name = Manage::row[0];
			user.avaPath = Manage::row[1];
			Manage::users.push_back(user);
		}
	}
	else
	{
		cout << "Query user failed: " << mysql_error(Manage::conn) << endl;
	}

	return Manage::users;
}
vector<Group> Manage::SelectGroup(string group) {
	Group groupp;
	string query_group = "SELECT * FROM lite_voice.group WHERE group.name_group LIKE\"";
	query_group += group + "%\"";
	const char* q_group = query_group.c_str();
	int qgroup = mysql_query(Manage::conn, q_group);
	if (!qgroup)
	{
		Manage::res = mysql_store_result(Manage::conn);
		while (Manage::row = mysql_fetch_row(Manage::res))
		{
			groupp.name= Manage::row[0];
			Manage::groups.push_back(groupp);
		}
	}
	else
	{
		cout << "Query user failed: " << mysql_error(Manage::conn) << endl;
	}
	return Manage::groups;
}
vector<Group> Manage::SelectAllGroup() {
	Group group;
	string query_group = "SELECT * FROM lite_voice.group";
	const char* q_group = query_group.c_str();
	int qgroup = mysql_query(Manage::conn, q_group);
	if (!qgroup)
	{
		Manage::res = mysql_store_result(Manage::conn);
		while (Manage::row = mysql_fetch_row(Manage::res))
		{
			group.name = Manage::row[0];
			Manage::groups.push_back(group);
		}
	}
	else
	{
		cout << "Query user failed: " << mysql_error(Manage::conn) << endl;
	}
	return Manage::groups;
}

vector<Friend> Manage::SelectFriend(string name) {
	Friend Friend;
	puts("Successful connection!");
	string query_user = "SELECT * FROM friend WHERE friend.name_user1 LIKE\"";
	query_user += name + "%\"";
	const char* q_user = query_user.c_str();
	int quser = mysql_query(Manage::conn, q_user);
	if (!quser)
	{
		Manage::res = mysql_store_result(Manage::conn);
		while (Manage::row = mysql_fetch_row(Manage::res))
		{
			Friend.name_user2 = Manage::row[1];
			Friend.blockStatus = (int)Manage::row[2];
			Manage::friends.push_back(Friend);
		}
	}
	else
	{
		cout << "Query user failed: " << mysql_error(Manage::conn) << endl;
	}

	return Manage::friends;
}
vector<MemberGroup> Manage::SelectMemberGroup(string user) {
	MemberGroup mgs;
	puts("Successful connection!");
	string query_user = "SELECT * FROM member WHERE (member.user_name LIKE '" + user + "')";
	const char* q_user = query_user.c_str();
	int quser = mysql_query(Manage::conn, q_user);
	if (!quser)
	{
		Manage::res = mysql_store_result(Manage::conn);
		while (Manage::row = mysql_fetch_row(Manage::res))
		{
			mgs.group_name = Manage::row[0];
			mgs.user_name= Manage::row[1];
			Manage::Mgs.push_back(mgs);
		}
	}
	else
	{
		cout << "Query user failed: " << mysql_error(Manage::conn) << endl;
	}

	return Manage::Mgs;
}
vector<MemberGroup> Manage::SelectGroupMember(string group) {
	MemberGroup Gms;
	puts("Successful connection!");
	string query_user = "SELECT * FROM member WHERE member.group LIKE\"";
	query_user += group + "%\"";
	const char* q_user = query_user.c_str();
	int quser = mysql_query(Manage::conn, q_user);
	if (!quser)
	{
		Manage::res = mysql_store_result(Manage::conn);
		while (Manage::row = mysql_fetch_row(Manage::res))
		{
			Gms.group_name = Manage::row[0];
			Gms.user_name = Manage::row[1];
			Manage::Gms.push_back(Gms);
		}
	}
	else
	{
		cout << "Query user failed: " << mysql_error(Manage::conn) << endl;
	}

	return Manage::Gms;
}
vector<Message> Manage::SelectMessage(string send, string receive) {
	Message message;
	puts("Successful connection!");
	string query_user = "SELECT * FROM message WHERE (message.send LIKE '" + send + "') AND (message.receive LIKE '" + receive + "')";
	const char* q_user = query_user.c_str();
	int quser = mysql_query(Manage::conn, q_user);
	if (!quser)
	{
		Manage::res = mysql_store_result(Manage::conn);
		while (Manage::row = mysql_fetch_row(Manage::res))
		{
			message.send = Manage::row[0];
			message.receive = Manage::row[1];
			message.content = Manage::row[2];
			message.time = Manage::row[3];
			Manage::messages.push_back(message);
		}
	}
	else
	{
		cout << "Query user failed: " << mysql_error(Manage::conn) << endl;
	}

	return Manage::messages;
}

void Manage::InsertUser(string name, string avt) {
	string insUser = "INSERT INTO user (user_name, user_avt) VALUES ( '" + name + "', '" + avt + "')";
	const char* i_user = insUser.c_str();
	int iuser = mysql_query(Manage::conn, i_user);
	if (!iuser) cout << "Insert success!" << endl;
	else cout << "Insert failed: " << mysql_error(Manage::conn) << endl;

}
void Manage::InsertGroup(string name) {
	string insGroup = "INSERT INTO lite_voice.group (group_name) VALUES ( '" + name + "')";
	const char* i_group = insGroup.c_str();
	int igroup = mysql_query(Manage::conn, i_group);
	if (!igroup) cout << "Insert success!" << endl;
	else cout << "Insert failed: " << mysql_error(Manage::conn) << endl;

}
void Manage::InsertFriend(string name1, string name2) {
	string insUser = "INSERT INTO friend (name_user1, name_user2) VALUES ( '" + name1 + "', '" + name2 + "')";
	const char* i_user = insUser.c_str();
	int iuser = mysql_query(Manage::conn, i_user);
	if (!iuser) cout << "Insert success!" << endl;
	else cout << "Insert failed: " << mysql_error(Manage::conn) << endl;
}
void Manage::InsertMess(string send, string receive, string content, string time) {
	string insUser = "INSERT INTO message (send, rêcive) VALUES ( '" + send + "', '" + receive + "','" + content + "','" + time + "')";
	const char* i_user = insUser.c_str();
	int iuser = mysql_query(Manage::conn, i_user);
	if (!iuser) cout << "Insert success!" << endl;
	else cout << "Insert failed: " << mysql_error(Manage::conn) << endl;
}
void Manage::InsertUserGroup(string g,string u) {
	string insGroup = "INSERT INTO member (group_name,user_name) VALUES ( '" + g + "','" + u + "')";
	const char* i_group = insGroup.c_str();
	int igroup = mysql_query(Manage::conn, i_group);
	if (!igroup) cout << "Insert success!" << endl;
	else cout << "Insert failed: " << mysql_error(Manage::conn) << endl;

}