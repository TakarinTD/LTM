#pragma once
#include "Member.h"
#include "User.h"
#include "Message.h"
#include <vector>

using namespace std;

using namespace std;
class Friend :
	public Member
{
public:
	char* name_user2;
	int blockStatus;
	Friend();
};
