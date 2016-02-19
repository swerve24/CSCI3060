#ifndef LOGOUT_H
#define LOGOUT_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "User.h"

using namespace std;

class Logout {

	public:
		string toLower(string &str);
		void logout(bool& is_logged, string& mode, string& acc_name);
};

#endif