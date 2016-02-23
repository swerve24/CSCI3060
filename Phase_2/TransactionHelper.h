#ifndef TRANSACTIONHELPER_H
#define TRANSACTIONHELPER_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

class User;
class TransactionHelper;

extern User curr_user;
extern vector<User> users;
extern vector<string> transaction_file;
extern string mode;
extern string acc_holder;
extern bool is_logged;
extern TransactionHelper transactions;

class TransactionHelper {

	public:

	/* To compare user input - should accept variations
	 * (e.g. "Standard", "standard", "STANDARD", etc)
	 */
	string toLower(string str);

	// Check if the curret user is an administrator
	bool isAdmin();

	// Check if the account holder name inputed exists in the "database"
	bool holderExists(string name);

	/* Check that the new account holder name entered follows the
	 * required constraints. Done using regex.
	 */
	bool isNameValid(string name);

	// Checks that both arguments correspond to eachother
	bool matches(string name, int acc_num);

	/* Checks that the amound of funds entered is valid
	 * (e.g. formatting). Done using regex.
	 */
	bool isAmountValid(float amount);

	// Checks if the account provided is active or disabled
	bool isDisabled(int acc_num);

	/* Checks if the user's transaction payment plan
	 * (student or non-student)
	 */
	bool isStudent(int acc_num);

	// Outputs the transaction_file vector into a file
	void writeTransferFile();

	/* Loads all accounts' information from the
	 * current_bank_accounts_file.txt file (provided by the back end)
	 */
	void loadAccounts();

	void printWelcomeMessage();

	// Allows the users to log in as a STANDARD user
	void login();

	// Logs user out from either account - administrator or standard
	void logout();

	void printHelp();
};

#endif