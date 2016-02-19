#include "User.h"

User::User() {

}

User::User(string name, string status, string plan, int acc_num, float balance) {
	this->name = name;
	this->status = status;
	this->plan = plan;
	this->acc_num = acc_num;
	this->balance = balance;
}