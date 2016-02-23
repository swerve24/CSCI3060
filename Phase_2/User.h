#ifndef USER_H
#define USER_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <regex>
#include "Standard.h"

using namespace std;

class User {
 private:
  string acc_holder_;

 protected:
  Standard std_acc_;

 public:
  User(){};
  //	User(string acc_holder, int acc_num, float acc_balance, char acc_status, char acc_plan);
  ~User(){};
		
  string GetName() {return acc_holder_;}
  int GetNum() {return std_acc_.GetNum();}
  float GetBalance() {return std_acc_.GetBalance();}
  char GetStatus() {return std_acc_.GetStatus();}
  char GetPlan() {return std_acc_.GetPlan();}

  void SetName(string name) {acc_holder_ = name;}
  void SetNum(int num) {std_acc_.SetNum(num);}
  void SetBalance(float balance) {std_acc_.SetBalance(balance);}
  void SetStatus(char status) {std_acc_.SetStatus(status);}
  void SetPlan(char plan) {std_acc_.SetPlan(plan);}

  void Withdrawal(int acc_num_, float amount) {
    std_acc_.Withdrawal(acc_num_, amount);}
  void Transfer(int acc_num_f, int acc_num_t, float amount) {
    std_acc_.Transfer(acc_num_f, acc_num_t, amount);}
  void Paybill(int acc_num_, string company, float amount) {
    std_acc_.Paybill(acc_num_, company, amount);}
  void Deposit(int acc_num_, float amount) {std_acc_.Deposit(acc_num_, amount);}
};

#endif