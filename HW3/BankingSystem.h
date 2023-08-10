//
// Created by FURKAN MERT on 8.07.2022.
//
#ifndef HW3_BANKINGSYSTEM_H
#define HW3_BANKINGSYSTEM_H
#include "string"
#include "iostream"
#include "Accounts.h"
#include "Customer.h"
using namespace std;

class BankingSystem {
public :
    Customer::customerNode *headC;
    int sizeC;
    int accID;
    BankingSystem ();
    ~ BankingSystem ();
    void addCustomer (int customerId , string firstName , string lastName );
    void deleteCustomer ( int customerId );
    int addAccount ( int customerId , double amount );
    void deleteAccount ( int accountId );
    void showAllAccounts ();
    void showAllCustomers ();
    void showCustomer ( int customerId );
};


#endif //HW3_BANKINGSYSTEM_H
