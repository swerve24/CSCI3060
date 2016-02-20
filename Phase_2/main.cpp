#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <regex>
#include "User.h"

using namespace std;

vector<User> users;
string mode;
string acc_name;
bool is_logged;

// To compare user input - should accept variations
// (e.g. "Standard", "standard", "STANDARD", etc)
string toLower(string &str) {

	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

void loadAccounts() {

	string file_name = "current_bank_accounts_file.txt";

	ifstream infile(file_name);

	string name, status, plan;
	int acc_num;
	float balance;

	if (infile) {
		while (!infile.eof()) {

			string line;

			infile >> acc_num >> name >> status >> balance >> plan;
			User u(name, status, plan, acc_num, balance);
			users.push_back(u);

			getline(infile, line);
		}
		infile.close();
	} else {
		cerr << "ERROR: File \"" << file_name << "\" was not found." << endl;
		exit(-1);
	}
}

void login() {
	if (!is_logged) {

		cout << "Enter mode in which you wish to log in as: ";
		//getline(cin, mode);
		cin >> mode;

		if (toLower(mode).compare("admin") == 0) {
			mode = "admin";
			is_logged = true;
			cout << "You are currently logged in as an administrator." << endl;

		} else if (toLower(mode).compare("standard") == 0) {

			string curr_name;
			bool is_found = false;

			cout << "Enter account holder's name: ";
			cin.ignore();
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

void logout() {
	if (is_logged) {
		if (toLower(mode).compare("admin") == 0) {
			cout << "You have successfully logged out of the administrator account." << endl;
		} else {
			cout << "You have successfully logged out of your account." << endl;
		}

		is_logged = false;
		mode = "";
		acc_name = "";
	} else {
		cerr << "ERROR: You are not currently logged into an account." << endl;
	}
}

void create() {

	if (is_logged) {

		string new_name;
		string result;

		bool existing = false;

		if (mode.compare("admin") == 0) {
			cout << "Enter new account holder's name: ";
			//cin >> new_name;
			cin.ignore();
			getline(cin, new_name);

			if (new_name.length() > 20) {
				new_name = new_name.substr(0, 20);
				cout << "Your account holder name has been truncated to: " << new_name << endl;
			}

			for (int i = 0; i < users.size(); i++) {
				if (users.at(i).getName().compare(new_name) == 0) {
					existing = true;
				}
			}

			if (existing == false) {

				try {
				  	regex re("[a-zA-Z0-9 -]+");

				  	if (regex_match(new_name, re)) {
			 			cout << "integer" << endl;
			 		} else {
			 			cout << "Invalid input" << endl;
			 		}
				} catch (regex_error& e) {
				  cerr << "ERROR: Invalid regular expression." << endl;
				}

			} else {
				cerr << "ERROR: This account name is already in use. Please pick a different one." << endl;
			}
		} else {
			cerr << "ERROR: You need to be an administrator to create a new account." << endl;
		}
	} else {
		cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
	}
}

void deleted() {
	if (is_logged) {

	} else {
		cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
	}
}

void disable() {
	if (is_logged) {

	} else {
		cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
	}
}

void enable() {
	if (is_logged) {

	} else {
		cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
	}
}

void deposit() {
	if (is_logged) {

	} else {
		cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
	}
}

void withdrawal() {
	if (is_logged) {

	} else {
		cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
	}
}

void transfer() {
	if (is_logged) {

	} else {
		cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
	}
}

void paybill() {
	if (is_logged) {

	} else {
		cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
	}
}

void changeplan() {
	if (is_logged) {

	} else {
		cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
	}
}

void printWelcomeMessage() {

/*	
	cout << " _    _  ___ _____ ______________  ________ _     _____ _   _ " << endl;
	cout << "| |  | |/ _ |_   _|  ___| ___ |  \\/  |  ___| |   |  _  | \\ | |" << endl;
	cout << "| |  | / /_\\ \\| | | |__ | |_/ | .  . | |__ | |   | | | |  \\| |" << endl;
	cout << "| |/\\| |  _  || | |  __||    /| |\\/| |  __|| |   | | | | . ` |" << endl;
	cout << "\\  /\\  | | | || | | |___| |\\ \\| |  | | |___| |___\\ \\_/ | |\\  |" << endl;
 	cout << " \\/  \\/\\_| |_/\\_/ \\____/\\_| \\_\\_|  |_\\____/\\_____/\\___/\\_| \\_/" << endl << endl;
*/
                                                              
    cout << "Welcome to Watermelon Banking System" << endl;
	cout << "Please log in to begin or type in \"help\" for more information." << endl;
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

int main (int argc, char *argv[]) {

	loadAccounts();
	printWelcomeMessage();

	if (argc == 1) { // for command line inputs only

		string command;
		is_logged = false;

		while(true) {

			//getline(cin, command);
			cin >> command;

			if (toLower(command).compare("login") == 0)
				login();
			else if (toLower(command).compare("logout") == 0)
				logout();
			else if (toLower(command).compare("create") == 0)
				create();
			else if (toLower(command).compare("delete") == 0)
				deleted();
			else if (toLower(command).compare("disable") == 0)
				disable();
			else if (toLower(command).compare("enable") == 0)
				enable();
			else if (toLower(command).compare("deposit") == 0)
				deposit();
			else if (toLower(command).compare("withdrawal") == 0)
				withdrawal();
			else if (toLower(command).compare("transfer") == 0)
				transfer();
			else if (toLower(command).compare("paybill") == 0)
				paybill();
			else if (toLower(command).compare("changeplan") == 0)
				changeplan();
			else if (toLower(command).compare("help") == 0)
				printHelp();
			else if (toLower(command).compare("quit") == 0) {
				if (!is_logged) {
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