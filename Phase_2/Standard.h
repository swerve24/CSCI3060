#ifndef STANDARD_H
#define STANDARD_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <regex>
#include "IAccount.h"
//#include "Administrator.h"
#include "TransactionHelper.h"

using namespace std;

class Standard: public virtual IAccount {

	private:
		int acc_num_;
		float acc_balance_;
		char acc_status_;
		char acc_plan_;

	public:

		Standard() {};
	//	Standard(int acc_num, float acc_balance, char acc_status, char acc_plan);
		~Standard() {} // MAYBE THIS COULD BE PART OF THE DELETE FUNCTION - SAME JOB
		
		int GetNum() {return acc_num_;}
		float GetBalance() {return acc_balance_;}
		char GetStatus() {return acc_status_;}
		char GetPlan() {return acc_plan_;}

		void SetNum(int num) {acc_num_ = num;}
		void SetBalance(float balance) {acc_balance_ = balance;}
		void SetStatus(char status) {acc_status_ = status;}
		void SetPlan(char plan) {acc_plan_ = plan;}

	//	void login(string acc_holder);
		void Withdrawal(int acc_num_, float amount);
		void Transfer(int acc_num_f, int acc_num_t, float amount);
		void Paybill(int acc_num_, string company, float amount);
		void Deposit(int acc_num_, float amount);
	//	bool logout();
};
#endif