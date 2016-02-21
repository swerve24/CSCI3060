#include "Standard.h"

/*
Standard::Standard(int acc_num, float acc_balance, char acc_status, char acc_plan) {
	this->acc_num = acc_num;
	this->acc_balance = acc_balance;
	this->acc_status = acc_status;
	this->acc_plan = acc_plan;
}*/

/*void Standard::login(string acc_holder) {

}*/

void Standard::withdrawal(int acc_num, float amount) {}
void Standard::transfer(int acc_num_f, int acc_num_t, float amount) {}
void Standard::paybill(int acc_num, string company, float amount) {}
void Standard::deposit(int acc_num, float amount) {}
/*
bool Standard::logout(){
	cout << "From Standard class" << endl;
}
*/