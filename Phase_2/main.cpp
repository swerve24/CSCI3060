#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "User.cpp"

using namespace std;

int main (int argc, char *argv[]) {

	User u("Bob", "Active", "Non-student", 00001, 00500.00);

	cout << u.getName() << endl;
	cout << u.getStatus() << endl;
	cout << u.getPlan() << endl;
	cout << u.getAccNum() << endl;
	cout << u.getBalance() << endl;

	if (argc == 0) { // for command line inputs only

	} else  if (argc == 0) { // argc should be 1 for correct execution with text inputs
    	// argv[0] would be the first argument - <filename>

 	} else {

	}
}