#include "Login.h"

string Login::toLower(string &str) {

	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

void Login::login(bool& is_logged, string& acc_name, string& mode, vector<User> users) {
	if (!is_logged) {

		cout << "Enter mode in which you wish to log in as: ";
		getline(cin, mode);

		if (toLower(mode).compare("admin") == 0) {
			mode = "admin";
			is_logged = true;
			cout << "You are currently logged in as an administrator." << endl;

		} else if (toLower(mode).compare("standard") == 0) {

			string curr_name;
			bool is_found = false;

			cout << "Enter account holder's name: ";
			getline(cin, curr_name);

			User curr_user;

			for (int i = 0; i < users.size(); i++) {
				if (users.at(i).getName().compare(curr_name) == 0) {
					is_found = true;
					curr_user = users.at(i);
				}
			}

			if (is_found == true) {
				is_logged = true;
				acc_name = curr_name;
				mode = "standard"; 
				cout << "You are currently logged in as " << acc_name << "." << endl;
				cout << "Bank Account Number: " << curr_user.getAccNum() << endl;
				cout << "Balance: " << curr_user.getBalance() << endl;
				cout << "Transaction Payment Plan: " << curr_user.getPlan() << endl;
				cout << "Status: " << curr_user.getStatus() << endl;
			} else {
				cerr << "ERROR: This name is invalid." << endl;
			}

		} else {
			cerr << "ERROR: Invalid account mode." << endl;
		}

	} else {
		cerr << "ERROR: There is a session running. Please log out and try again." << endl;
	}
}