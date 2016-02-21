#ifndef USER_H
#define USER_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Standard.h"

using namespace std;

class User {
	private:
		string acc_holder;

	public:
		Standard std_acc;
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
};
#endif