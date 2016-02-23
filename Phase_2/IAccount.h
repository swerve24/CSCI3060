#ifndef IACCOUNT_H
#define IACCOUNT_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class IAccount {
 public:
  virtual ~IAccount() {}
  virtual void Withdrawal(int acc_num, float amount) = 0;
  virtual void Transfer(int acc_num_f, int acc_num_t, float amount) = 0;
  virtual void Paybill(int acc_num, string company, float amount) = 0;
  virtual void Deposit(int acc_num, float amount) = 0;
};

#endif