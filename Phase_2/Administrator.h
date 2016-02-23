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

		void Create();
		void Deleted(int acc_num);
		void Disable(int acc_num);
		void Enable(int acc_num);
		void Changeplan(int acc_num);

		void Withdrawal(int acc_num, float amount);
		void Transfer(int acc_num_f, int acc_num_t, float amount);
		void Paybill(int acc_num, string company, float amount);
		void Deposit(int acc_num, float amount);
	//	bool logout();
};

#endif