#pragma once
#include "Member.h"
#include "User.h"
#include "Message.h"
#include <vector>

using namespace std;
class Group :
	public Member
{
public:
	vector <User> usersList;
	int numUsers;
	Group();

};

