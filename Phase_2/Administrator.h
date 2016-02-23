#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "IAccount.h"
#include "User.h"
#include "Standard.h"
#include "TransactionHelper.h"

using namespace std;

class Administrator: public virtual IAccount {

	public:
		Administrator() {};
		~Administrator() {}

		void create(vector<User>& users);
		void deleted(int acc_num);
		void disable(int acc_num);
		void enable(int acc_num);
		void changeplan(int acc_num);

		void withdrawal(int acc_num, float amount);
		void transfer(int acc_num_f, int acc_num_t, float amount);
		void paybill(int acc_num, string company, float amount);
		void deposit(int acc_num, float amount);
	//	bool logout();
};

#endif