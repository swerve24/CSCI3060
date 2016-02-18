#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef USER_H
#define USER_H

class User {
	private:
		string name;
		string status;
		string plan;
		int acc_num;
		float balance;

	public:
		User();
		User(string name, string status, string plan, int acc_num, float balance);
		string getName() {return name;}
		string getStatus() {return status;}
		string getPlan() {return plan;}
		int getAccNum() {return acc_num;}
		float getBalance() {return balance;}
};

#endif