#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef USER_H
#define USER_H

class User {
	public:
		User();
		User(string name, string status, string plan, int acc_num, float balance);

		string name;
		string status;
		string plan;
		int acc_num;
		float balance;
};

#endif