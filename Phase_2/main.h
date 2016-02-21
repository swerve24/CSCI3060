#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>
#include "User.h"
#include "Standard.h"
#include "Administrator.h"

string toLower(string str);
bool isAdmin();
bool holderExists(string acc_holder);
bool isNameValid(string acc_holder);
bool matches(string acc_holder, int acc_num);
bool isAmountValid(float amount);
bool isDisabled(int acc_num);
bool isStudent(int acc_num);
void loadAccounts();
void printWelcomeMessage();
void printHelp();
void writeTransferFile();

void login();
void logout();