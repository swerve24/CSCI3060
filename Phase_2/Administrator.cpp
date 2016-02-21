#include "Administrator.h"
#include "main.h"

void Administrator::withdrawal(int acc_num, float amount) {}
void Administrator::transfer(int acc_num_f, int acc_num_t, float amount) {}
void Administrator::paybill(int acc_num, string company, float amount) {}
void Administrator::deposit(int acc_num, float amount) {}
/*
bool Administrator::logout(){
	cout << "From Administrator class" << endl;
}
*/

void Administrator::create(vector<User>& users) {

	string new_name;
	
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
	if (!holderExists(new_name) && new_name.compare("admin") != 0
		&& isNameValid(new_name)) {
		// Assign new account number here using
		// Then create new User and add it to the users vector
	} else {
		cerr << "ERROR: This account name is already in use. Please pick a different one." << endl;
	}
}

void Administrator::deleted(int acc_num) {}
void Administrator::disable(int acc_num) {}
void Administrator::enable(int acc_num) {}
void Administrator::changeplan(int acc_num) {}