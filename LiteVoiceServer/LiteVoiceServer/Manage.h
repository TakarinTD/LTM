#pragma once
#include<mysql.h>
#include <vector>
#include "User.h"
#include "Group.h"
#include<iostream>
using namespace std;
class Manage
{
public:
	static vector<User> users;
	static vector<Group> groups;
	static MYSQL* conn;
	void in();
	Manage();
};

