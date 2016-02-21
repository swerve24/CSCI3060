#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <regex>
#include "main.h"
#include "User.h"
#include "Standard.h"
#include "Administrator.h"

using namespace std;

User curr_user;
vector<User> users;
vector<string> transaction_file;
string mode;
string acc_holder;
bool is_logged;

int main (int argc, char *argv[]) {

	loadAccounts();
	printWelcomeMessage();

	string command;
	is_logged = false;

	// Used to call the different functions for each case
	Standard s;
	Administrator a;

	if (argc == 1) { // for command line inputs only

		while(true) {

			cin >> command;

			// If command is LOGIN
			if (toLower(command).compare("login") == 0)
				if (!is_logged) {
					cout << "Enter mode in which you wish to log in as: ";
					cin >> mode;

					if (toLower(mode).compare("admin") == 0) {
						mode = "admin";
						is_logged = true;
						cout << "You are currently logged in as an administrator." << endl;
					} else if (toLower(mode).compare("standard") == 0) {
						login();
					} else {
						cerr << "ERROR: Invalid account mode." << endl;
					}
				} else {
					cerr << "ERROR: There is a session running. Please log out and try again." << endl;
				}

			// If command is LOGOUT
			else if (toLower(command).compare("logout") == 0)
				logout();

			// If command is CREATE (Privileged)
			else if (toLower(command).compare("create") == 0)
				if (is_logged) {
					if (isAdmin()) 
						a.create(users);
					else
						cerr << "ERROR: You need to be an administrator to create a new account." << endl;
				} else 
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;

			// If command is DELETE (Privileged)
			else if (toLower(command).compare("delete") == 0)
				cout << "delete" << endl;
				//deleted();

			// If command is DISABLE (Privileged)
			else if (toLower(command).compare("disable") == 0)
				cout << "disable" << endl;
				//disable();

			// If command is ENABLE (Privileged)
			else if (toLower(command).compare("enable") == 0)
				cout << "enable" << endl;
				//enable();

			// If command is DEPOSIT
			else if (toLower(command).compare("deposit") == 0)
				cout << "deposit()" << endl;
				//deposit();

			// If command is WITHDRAWAL
			else if (toLower(command).compare("withdrawal") == 0)
				cout << "withdrawal()" << endl;
				//withdrawal();

			// If command is TRANSFER
			else if (toLower(command).compare("transfer") == 0)
				cout << "transfer()" << endl;
				//transfer();

			// If command is PAYBILL
			else if (toLower(command).compare("paybill") == 0)
				cout << "paybill()" << endl;
				//paybill();

			// If command is CHANGEPLAN
			else if (toLower(command).compare("changeplan") == 0)
				cout << "changeplan()" << endl;
				//changeplan();

			// If command is HELP
			else if (toLower(command).compare("help") == 0)
				printHelp();

			// If command is QUIT
			else if (toLower(command).compare("quit") == 0) {
				if (!is_logged)
					return 1;
				else
					cerr << "ERROR: You may not quit while logged in." << endl;
			} else {
				cerr << "ERROR: Invalid command." << endl;
			}
		}

	} else  if (argc == 2) { // argc should be 1 for correct execution with text inputs
    	// argv[0] would be the first argument - <filename>

 	} else {
 		cerr << "ERROR: Too many arguments." << endl;
 		return -1;
	}
}

/* To compare user input - should accept variations
 * (e.g. "Standard", "standard", "STANDARD", etc)
 */
string toLower(string str) {

	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

// Check if the curret user is an administrator
bool isAdmin() {
	if (mode.compare("admin") == 0)
		return true;
	return false;
}

// Check if the account holder name inputed exists in the "database"
bool holderExists(string acc_holder) {

	bool ret;

	for (int i = 0; i < users.size(); i++) {
		if (users.at(i).getName().compare(acc_holder) == 0)
			ret = true;
		else ret = false;	
	}

	return ret;
}

/* Check that the new account holder name entered follows the
 * required constraints. Done using regex.
 */
bool isNameValid(string acc_holder) {
	
	regex re("[a-zA-Z0-9 -]+");

  	if (regex_match(acc_holder, re))
  		return true;
	else
		return false;
}

// Checks that both arguments correspond to eachother
bool matches(string acc_holder, int acc_num) {
	return true;
}

/* Checks that the amound of funds entered is valid
 * (e.g. formatting). Done using regex.
 */
bool isAmountValid(float amount) {
	return true;
}

// Checks if the account provided is active or disabled
bool isDisabled(int acc_num) {
	return true;
}

/* Checks if the user's transaction payment plan
 * (student or non-student)
 */
bool isStudent(int acc_num) {
	return true;
}

// Outputs the transaction_file vector into a file
void writeTransferFile() {

}

/* Loads all accounts' information from the
 * current_bank_accounts_file.txt file (provided by the back end)
 */
void loadAccounts() {

	string file_name = "current_bank_accounts_file.txt";

	ifstream infile(file_name);

	string acc_holder;
	char acc_status, acc_plan;
	int acc_num;
	float acc_balance;

	if (infile) {
		while (!infile.eof()) {

			string line;

			infile >> acc_num >> acc_holder >> acc_status >> acc_balance >> acc_plan;
			User u;
		//	User u(acc_holder, acc_num, acc_balance, acc_status, acc_plan);
			u.setName(acc_holder);
			u.setNum(acc_num);
			u.setBalance(acc_balance);
			u.setStatus(acc_status);
			u.setPlan(acc_plan);
			users.push_back(u);

			getline(infile, line);
		}
		infile.close();
	} else {
		cerr << "ERROR: File \"" << file_name << "\" was not found." << endl;
		exit(-1);
	}
}

void printWelcomeMessage() {
                                                              
    cout << "Welcome to Watermelon Banking System" << endl;
	cout << "Please log in to begin or type in \"help\" for more information." << endl;
}

// Allows the users to log in as a STANDARD user
void login() {
	
	string acc_holder;
	mode = "standard"; 

	// Save the account holder's name
	cout << "Enter account holder's name: ";
	cin.ignore();
	getline(cin, acc_holder);

	/* If the name stored is found in the users vector, then
	 * update the curr_user User object with the new curr_user
	 * information for future transactions
	 */
	if (holderExists(acc_holder)) {

		is_logged = true;

		for (int i = 0; i < users.size(); i++)
			if (users.at(i).getName().compare(acc_holder) == 0) {
				curr_user = users.at(i);
			}

		// Output the accounts' information in a user-friendly/readable way
		cout << "You are currently logged in as " << curr_user.getName() << "." << endl;
		cout << "Bank Account Number: " << curr_user.getNum() << endl;
		cout << "Balance: " << curr_user.getBalance() << endl;
		if (curr_user.getPlan() == 'S')
			cout << "Transaction Payment Plan: Student" << endl;
		else if (curr_user.getPlan() == 'N')
			cout << "Transaction Payment Plan: Non-student" << endl;
		else 
			cerr << "ERROR: Could not get payment plan information." << endl;			
		
		if (curr_user.getStatus() == 'D')
			cout << "Status: Disabled" << endl;
		else if (curr_user.getStatus() == 'A')
			cout << "Status: Active" << endl;
		else
			cerr << "ERROR: Could not get status information." << endl;			

	} else {
		// The name is not found in the "database"
		cerr << "ERROR: This name is invalid." << endl;
	}
}

// Logs user out from either account - administrator or standard
void logout() {

	if (is_logged) {
		if (mode.compare("admin") == 0) {
			cout << "You have successfully logged out of the administrator account." << endl;
		} else {
			cout << "You have successfully logged out of your account." << endl;
		}

		// Resets all variables for next user
		is_logged = false;
		mode = "";
		acc_holder = "";
	} else {
		// There is no running session to be logged out of
		cerr << "ERROR: You are not currently logged into an account." << endl;
	}
}

void printHelp() {

	string file_name = "help.txt";
	string line;

	ifstream infile(file_name);

	if (infile) {
		while (getline (infile,line)) {
			cout << line << endl;
		}
		infile.close();
	} else {
		cerr << "ERROR: File \"" << file_name << "\" was not found." << endl;
		exit(-1);
	}
}