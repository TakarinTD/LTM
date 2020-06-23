#include<mysql.h>
#include "Manage.h"
#include "User.h"
#include<vector>
#include<iostream>
#include<string>
#pragma(disable:4996)

using namespace std;
string nameUser, avta, nameGroup;
bool nhapUser=true,nhapGroup=true;

int main() {
	Manage::Manage();
	if (Manage::conn) {
		puts("Successful connection!");
		while (nhapUser == true) {
			getline(cin, nameUser);
			getline(cin, avta);
			Manage::InsertUser(nameUser, avta);
			nhapUser = false;
		}
		Manage::SelectAllUser();
		while (nhapGroup == true) {
			getline(cin, nameGroup);
			Manage::InsertGroup(nameGroup);
			nhapGroup = false;
		}
		Manage::SelectAllGroup();
	}
	else {
		puts("Connection failed!");
	}

	for (auto it : Manage::users) {
		printf("userName: %s, userAvt: %s\n", it.name, it.avaPath);
	}
	for (auto it : Manage::groups) {
		printf("groupName: %s\n", it.name);
	}
	return 0;
}