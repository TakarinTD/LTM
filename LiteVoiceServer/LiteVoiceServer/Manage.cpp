#include "Manage.h"

MYSQL* Manage::conn = NULL;
vector<User> Manage::users = {};
vector<Group> Manage::groups = {};

Manage::Manage() {
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "root", "lite_voice", 3306, NULL, 0);
}