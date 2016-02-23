#include "Standard.h"

void Standard::withdrawal(int acc_num, float amount) {
	cout << "Funds have successfully been withdrawn from your account." << endl;
	cout << "New balance: " << endl;
}

void Standard::transfer(int acc_num_f, int acc_num_t, float amount) {
	cout << "Funds have been successfully transfered from your account to account " << acc_num_t << "." <<endl;
	cout << "New balance: " << endl;
}

void Standard::paybill(int acc_num, string company, float amount) {
	cout << "You have successfully paid a bill of $" << amount << " to " << company << "." <<endl;
	cout << "New balance: " << endl;
}

void Standard::deposit(int acc_num, float amount) {
	cout << "Funds have been successfully added to your account." << endl;
	cout << "New balance: " << endl;
}