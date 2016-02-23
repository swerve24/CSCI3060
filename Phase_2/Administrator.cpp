#include "Administrator.h"

void Administrator::Withdrawal(int acc_num, float amount) {
	cout << "Funds have successfully been withdrawn from the account " << acc_num << "." << endl;
	cout << "New balance: " << endl;
}

void Administrator::Transfer(int acc_num_f, int acc_num_t, float amount) {
	cout << "Funds have been successfully transfered from account " <<  acc_num_f <<  " to account " << acc_num_t << "." <<endl;
	cout << "New balance: " << endl;
}

void Administrator::Paybill(int acc_num, string company, float amount) {
	cout << "You have successfully paid a bill of $" << amount << " from account " << acc_num << " to " << company << "." << endl;
	cout << "New balance: " << endl;
}

void Administrator::Deposit(int acc_num, float amount) {
	cout << "Funds have been successfully added to the account " << acc_num << "." <<endl;
	cout << "New balance: " << endl;
}

void Administrator::Create() {

	string new_name;
	float init_balance;
	
	cout << "Enter new account holder's name: ";
	//cin >> new_name;
	cin.ignore();
	getline(cin, new_name);

	/* If the new account holder name enter happens to be longer
	 * than 20 characters, truncate it to fit the requirements
	 */
	if (new_name.length() > 20) {
		new_name = new_name.substr(0, 20);
		cout << "Your account holder name has been truncated to: " << new_name << endl;
	}

	/* If the name does not exist (e.g. is unique) then 
	 * check if it fits the format required
	 */
	if (!transactions.HolderExists(new_name) && new_name.compare("admin") != 0
		&& transactions.is_Name_Valid(new_name)) {
		// Assign new account number here using
		// Prompt for initial balance and check it's valid
		// Then create new User and add it to the users vector
		cout << "Enter the initial balance: " << endl;
		cin >> init_balance;
		cout << "You have successfully created a new account." << endl;
		cout << "Account number: " << endl;
		cout << "Account holder's name: " << new_name << endl;
		cout << "Account balance: " << init_balance << endl;
	} else {
		cerr << "ERROR: This account name is already in use. Please pick a different one." << endl;
	}
}

void Administrator::Deleted(int acc_num) {
	string choice;
	cout << "Are you sure you want to delete " << acc_holder << "\'s account " << acc_num << " (yes/no)? ";
	cin >> choice;
	if (choice.compare("yes") == 0)
		cout << "The account " << acc_num <<  " has been deleted successfully." << endl;
	else if (choice.compare("no") == 0)
		cout << "The deletion of account " << acc_num << " has been aborted." << endl;
	else
		cerr << "ERROR: This is not a valid input." << endl;
}

void Administrator::Disable(int acc_num) {
	cout << "The account " << acc_num <<  " has been disabled successfully." << endl;
}

void Administrator::Enable(int acc_num) {
	cout << "The account " << acc_num <<  " has been enabled successfully." << endl;
}

void Administrator::Changeplan(int acc_num) {
	string plan = "Student";
	cout << "The transaction payment plan for account " << acc_num << " has been successfully changed to " << plan << endl;
}