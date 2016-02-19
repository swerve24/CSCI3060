#include "Logout.h"

string Logout::toLower(string &str) {

	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

void Logout::logout(bool& is_logged, string& mode, string& acc_name) {
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