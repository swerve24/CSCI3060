#ifndef USER_H
#define USER_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <regex>
#include "Standard.h"

using namespace std;

class User {
	private:
		string acc_holder;

	protected:
		Standard std_acc;

	public:
		User(){};
	//	User(string acc_holder, int acc_num, float acc_balance, char acc_status, char acc_plan);
		~User(){};
		
		string getName() {return acc_holder;}
		int getNum() {return std_acc.getNum();}
		float getBalance() {return std_acc.getBalance();}
		char getStatus() {return std_acc.getStatus();}
		char getPlan() {return std_acc.getPlan();}

		void setName(string name) {acc_holder = name;}
		void setNum(int num) {std_acc.setNum(num);}
		void setBalance(float balance) {std_acc.setBalance(balance);}
		void setStatus(char status) {std_acc.setStatus(status);}
		void setPlan(char plan) {std_acc.setPlan(plan);}

		void withdrawal(int acc_num, float amount) {std_acc.withdrawal(acc_num, amount);}
		void transfer(int acc_num_f, int acc_num_t, float amount) {std_acc.transfer(acc_num_f, acc_num_t, amount);}
		void paybill(int acc_num, string company, float amount) {std_acc.paybill(acc_num, company, amount);}
		void deposit(int acc_num, float amount) {std_acc.deposit(acc_num, amount);}
};
#endif