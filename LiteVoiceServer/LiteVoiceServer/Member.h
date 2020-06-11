#pragma once
#include "Message.h"
#include <vector>

using namespace std;

class Message;

class Member
{
public:
	vector <Message> messages;
	char* name;
	char* avaPath;
};
