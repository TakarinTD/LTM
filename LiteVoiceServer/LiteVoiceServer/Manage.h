#pragma once
#include<mysql.h>
#include <vector>
#include "User.h"
#include "Group.h"
#include "Message.h"
#include "Member_group.h"
#include"Friend.h"
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
class Manage
{
public:
	static vector<User> users;
	static vector<Group> groups;
	static vector<Message> messages;
	static vector<MemberGroup> Mgs;
	static vector<MemberGroup> Gms;
	static vector<Friend> friends;
	static MYSQL* conn;
	static MYSQL_ROW row;
	static MYSQL_RES *res;
	Manage();
	static vector<User> SelectUser(string name);
	static vector<Friend> SelectFriend(string name);
	static vector<Message> SelectMessage(string send, string receive);
	static vector<User> SelectAllUser();
	static vector<Group> SelectGroup(string group);
	static vector<MemberGroup> SelectMemberGroup(string user);
	static vector<MemberGroup> SelectGroupMember(string group);
	static vector<Group> SelectAllGroup();
	static void InsertUser(string name, string avt);
	static void InsertGroup(string name);
	static void InsertFriend(string name_user1, string name_user2);
	static void InsertMess(string send, string receive,string content,string time);
	static void InsertUserGroup(string group,string user);
};

