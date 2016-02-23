#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "User.h"
#include "TransactionHelper.h"
#include "Standard.h"
#include "Administrator.h"

using namespace std;

// Used to call the different functions for each case
Standard s;
Administrator a;

int main (int argc, char *argv[]) {

	transactions.loadAccounts();
	transactions.printWelcomeMessage();

	string command;
	is_logged = false;

	if (argc == 1) { // for command line inputs only

		while(true) {

			cin >> command;

			// If command is LOGIN
			if (transactions.toLower(command).compare("login") == 0)
				if (!is_logged) {
					cout << "Enter mode in which you wish to log in as: ";
					cin >> mode;

					if (transactions.toLower(mode).compare("admin") == 0) {
						mode = "admin";
						is_logged = true;
						cout << "You are currently logged in as an administrator." << endl;
					} else if (transactions.toLower(mode).compare("standard") == 0) {
						transactions.login();
					} else {
						cerr << "ERROR: Invalid account mode." << endl;
					}
				} else {
					cerr << "ERROR: There is a session running. Please log out and try again." << endl;
				}

			// If command is LOGOUT
			else if (transactions.toLower(command).compare("logout") == 0)
				transactions.logout();

			// If command is CREATE (Privileged)
			else if (transactions.toLower(command).compare("create") == 0)
				if (is_logged) {
					if (transactions.isAdmin()) 
						a.create(users);
					else
						cerr << "ERROR: You need to be an administrator to create a new account." << endl;
				} else 
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;

			// If command is DELETE (Privileged)
			else if (transactions.toLower(command).compare("delete") == 0)
				cout << "delete" << endl;
				//deleted();

			// If command is DISABLE (Privileged)
			else if (transactions.toLower(command).compare("disable") == 0)
				cout << "disable" << endl;
				//disable();

			// If command is ENABLE (Privileged)
			else if (transactions.toLower(command).compare("enable") == 0)
				cout << "enable" << endl;
				//enable();

			// If command is DEPOSIT
			else if (transactions.toLower(command).compare("deposit") == 0)
				cout << "deposit()" << endl;
				//deposit();

			// If command is WITHDRAWAL
			else if (transactions.toLower(command).compare("withdrawal") == 0)
				cout << "withdrawal()" << endl;
				//withdrawal();

			// If command is TRANSFER
			else if (transactions.toLower(command).compare("transfer") == 0)
				cout << "transfer()" << endl;
				//transfer();

			// If command is PAYBILL
			else if (transactions.toLower(command).compare("paybill") == 0)
				cout << "paybill()" << endl;
				//paybill();

			// If command is CHANGEPLAN
			else if (transactions.toLower(command).compare("changeplan") == 0)
				cout << "changeplan()" << endl;
				//changeplan();

			// If command is HELP
			else if (transactions.toLower(command).compare("help") == 0)
				transactions.printHelp();

			// If command is QUIT
			else if (transactions.toLower(command).compare("quit") == 0) {
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