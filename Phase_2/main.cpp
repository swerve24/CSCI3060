#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

using namespace std;

int main (int argc, char *argv[]) {

	User u("Bob", "active", "non-student", 00001, 00500.00);

	if (argc == 0) { // for command line inputs only

	} else  if (argc == 0) { // argc should be 1 for correct execution with text inputs
    	// argv[0] would be the first argument - <filename>

 	} else {

	}
}