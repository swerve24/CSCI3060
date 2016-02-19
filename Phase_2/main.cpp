#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "User.h"

using namespace std;

vector<User> users;

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

	ifstream infile(file_name.c_str());

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

void login(bool& is_logged, string& acc_name, string& mode, vector<User> users) {
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

void logout(bool& is_logged, string& mode, string& acc_name) {
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

	ifstream infile(file_name.c_str());

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
		string mode;
		string acc_name;
		bool is_logged = false;

		while(true) {

			getline(cin, command);

			if (toLower(command).compare("login") == 0) {
				login(is_logged, acc_name, mode, users);
			} else if (toLower(command).compare("logout") == 0) {
				logout(is_logged, mode, acc_name);
			} else if (toLower(command).compare("create") == 0) {
				if (is_logged) {
					if (toLower(mode).compare("admin") == 0) {
						
					} else {
						cerr << "ERROR: " << endl;
					}
				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (toLower(command).compare("delete") == 0) {
				if (is_logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (toLower(command).compare("disable") == 0) {
				if (is_logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (toLower(command).compare("enable") == 0) {
				if (is_logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (toLower(command).compare("deposit") == 0) {
				if (is_logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (toLower(command).compare("withdrawal") == 0) {
				if (is_logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (toLower(command).compare("transfer") == 0) {
				if (is_logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (toLower(command).compare("paybill") == 0) {
				if (is_logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (toLower(command).compare("changeplan") == 0) {
				if (is_logged) {

				} else {
					cerr << "ERROR: Must be logged in before invoking any other commands." << endl;
				}
			} else if (toLower(command).compare("help") == 0) {
				printHelp();
			} else if (toLower(command).compare("quit") == 0) {
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