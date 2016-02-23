#include "TransactionHelper.h"
#include "User.h"

/* To compare user input - should accept variations
 * (e.g. "Standard", "standard", "STANDARD", etc)
 */
string TransactionHelper::to_Lower(string str) {

  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}

// Check if the curret user is an administrator
bool TransactionHelper::is_Admin() {
  if (mode.compare("admin") == 0)
    return true;
  return false;
}

// Check if the account holder name inputed exists in the "database"
bool TransactionHelper::HolderExists(string name) {

  bool ret = false;

  for (int i = 0; i < users.size(); i++) {
    if (users.at(i).GetName().compare(name) == 0) {			
      ret = true;
      break;
    }
  }

  return ret;
}

/* Check that the new account holder name entered follows the
 * required constraints. Done using regex.
 */
bool TransactionHelper::is_Name_Valid(string name) {
	
  regex re("[a-zA-Z0-9 -]+");

  if (regex_match(name, re))
    return true;
  else
    return false;
}

// Checks that both arguments correspond to eachother
bool TransactionHelper::Matches(string name, int acc_num) {
  return true;
}

/* Checks that the amound of funds entered is valid
 * (e.g. formatting). Done using regex.
 */
bool TransactionHelper::is_Amount_Valid(float amount) {
  return true;
}

// Checks if the account provided is active or disabled
bool TransactionHelper::is_Disabled(int acc_num) {
  return true;
}

/* Checks if the user's transaction payment plan
 * (student or non-student)
 */
bool TransactionHelper::is_Student(int acc_num) {
  return true;
}

// Outputs the transaction_file vector into a file
void TransactionHelper::WriteTransferFile() {

}

/* Loads all accounts' information from the
 * current_bank_accounts_file.txt file (provided by the back end)
 */
void TransactionHelper::LoadAccounts() {

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
      u.SetName(acc_holder);
      u.SetNum(acc_num);
      u.SetBalance(acc_balance);
      u.SetStatus(acc_status);
      u.SetPlan(acc_plan);
      users.push_back(u);
    }
    infile.close();
  } else {
    cerr << "ERROR: File \"" << file_name << "\" was not found." << endl;
  exit(-1);
  }
}

void TransactionHelper::PrintWelcomeMessage() {
                                                              
  cout << "Welcome to Watermelon Banking System" << endl;
  cout << "Please log in to begin or type in \"help\" for more information." << endl;
}

// Allows the users to log in as a STANDARD user
void TransactionHelper::Login() {
	
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
  if (HolderExists(acc_holder) && acc_holder != "END_OF_FILE") {

    is_logged = true;

    for (int i = 0; i < users.size(); i++)
      if (users.at(i).GetName().compare(acc_holder) == 0) {
        curr_user = users.at(i);
      }

    // Output the accounts' information in a user-friendly/readable way
    cout << "You are currently logged in as " << curr_user.GetName() << "." << endl;
    cout << "Bank Account Number: " << curr_user.GetNum() << endl;
    cout << "Balance: " << curr_user.GetBalance() << endl;
    if (curr_user.GetPlan() == 'S')
      cout << "Transaction Payment Plan: Student" << endl;
    else if (curr_user.GetPlan() == 'N')
      cout << "Transaction Payment Plan: Non-student" << endl;
    else 
      cerr << "ERROR: Could not get payment plan information." << endl;			
		
    if (curr_user.GetStatus() == 'D')
      cout << "Status: Disabled" << endl;
    else if (curr_user.GetStatus() == 'A')
      cout << "Status: Active" << endl;
    else
      cerr << "ERROR: Could not get status information." << endl;			

  } else {
    // The name is not found in the "database"
    cerr << "ERROR: This name is invalid." << endl;
  }
}

// Logs user out from either account - administrator or standard
void TransactionHelper::Logout() {

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

void TransactionHelper::PrintHelp() {

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