#ifndef STANDARD_H
#define STANDARD_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "IAccount.h"

using namespace std;

class Standard: public virtual IAccount {

	private:
		int acc_num;
		float acc_balance;
		char acc_status;
		char acc_plan;

	public:

		Standard() {};
	//	Standard(int acc_num, float acc_balance, char acc_status, char acc_plan);
		~Standard() {} // MAYBE THIS COULD BE PART OF THE DELETE FUNCTION - SAME JOB
		
		int getNum() {return acc_num;}
		float getBalance() {return acc_balance;}
		char getStatus() {return acc_status;}
		char getPlan() {return acc_plan;}

		void setNum(int num) {acc_num = num;}
		void setBalance(float balance) {acc_balance = balance;}
		void setStatus(char status) {acc_status = status;}
		void setPlan(char plan) {acc_plan = plan;}

	//	void login(string acc_holder);
		bool logout();
};
#endif