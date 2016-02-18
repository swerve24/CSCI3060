#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "User.cpp"

using namespace std;

vector<User> users;

void getAccounts() {

	ifstream infile("current_bank_accounts_file.txt");

	string name;
	string status;
	string plan;
	int acc_num;
	float balance;

	while (!infile.eof()) {

		string line;

		infile >> acc_num >> name >> status >> balance >> plan;
		User u(name, status, plan, acc_num, balance);
		users.push_back(u);

		getline(infile, line);
	}

	infile.close();
}

void printWelcomeMessage() {
	cout << "Welcome to Watermelon Banking System" << endl;
	cout << "Please log in to begin or type in \"help\" for more information." << endl;
}

void printHelp() {

	ifstream infile("help.txt");
	string line;

	while ( getline (infile,line) ) {
		cout << line << endl;
	}

	infile.close();
}

int main (int argc, char *argv[]) {

	getAccounts();
	printWelcomeMessage();

	if (argc == 1) { // for command line inputs only

		string command;
		string mode;
		bool logged = false;

		while(true) {

			cout << "Enter a command." << endl;
			cin >> command;

			if (command.compare("login") == 0) {
				if (!logged) {

					cout << "Enter mode in which you wish to log in as: ";
					cin >> mode;

					if (mode.compare("admin") == 0) {
						mode = "admin";
						logged = true;
						cout << "You are currently logged in as an administrator." << endl;

					} else if (mode.compare("standard") == 0) {

						cout << "Enter account holder's name: ";

					} else {
						cerr << "ERROR: Invalid account mode." << endl;
					}

				} else {
					cerr << "ERROR: There is a session running. Please log out and try again." << endl;
				}
			} else if (command.compare("logout") == 0) {
				if (logged) {
					logged = false;
				} else {
					cerr << "ERROR: You are not currently logged into an account." << endl;
				}
			} else if (command.compare("create") == 0) {
				if (logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (command.compare("delete") == 0) {
				if (logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (command.compare("disable") == 0) {
				if (logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (command.compare("enable") == 0) {
				if (logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (command.compare("deposit") == 0) {
				if (logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (command.compare("withdrawal") == 0) {
				if (logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (command.compare("transfer") == 0) {
				if (logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (command.compare("paybill") == 0) {
				if (logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (command.compare("changeplan") == 0) {
				if (logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (command.compare("help") == 0) {
				printHelp();
			} else if (command.compare("quit") == 0) {
				if (!logged) {
					return 1;
				} else {
					cerr << "ERROR: You may not quit while logged in." << endl;
				}
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