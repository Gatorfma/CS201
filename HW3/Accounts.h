
//
// Created by FURKAN MERT on 8.07.2022.
//

#ifndef HW3_ACCOUNTS_H
#define HW3_ACCOUNTS_H

#include <iostream>
using namespace std;

class Accounts {
public:
    Accounts();
    Accounts(int accountId, int balance);
    Accounts(const Accounts& a);
    ~Accounts();
    struct accountNode{
        int id;
        int balance;
        accountNode *next;
    };
    accountNode *headA;
};


#endif //HW3_ACCOUNTS_H