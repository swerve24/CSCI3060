#ifndef LOGIN_H
#define LOGIN_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "User.h"

using namespace std;

class Login {

	public:
		string toLower(string &str);
		void login(bool& is_logged, string& acc_name, string& mode, vector<User> users);
};

#endif