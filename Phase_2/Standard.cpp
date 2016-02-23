#include "Standard.h"

void Standard::Withdrawal(int acc_num_, float amount) {
  cout << "Funds have successfully been withdrawn from your account." << endl;
  cout << "New balance: " << endl;
}

void Standard::Transfer(int acc_num_f, int acc_num_t, float amount) {
  cout << "Funds have been successfully transfered from your account to account " <<
           acc_num_t << "." <<endl;
  cout << "New balance: " << endl;
}

void Standard::Paybill(int acc_num_, string company, float amount) {
  cout << "You have successfully paid a bill of $" << amount << " to " <<
           company << "." << endl;
  cout << "New balance: " << endl;
}

void Standard::Deposit(int acc_num_, float amount) {
  cout << "Funds have been successfully added to your account." << endl;
  cout << "New balance: " << endl;
}