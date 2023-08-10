//
// Created by FURKAN MERT on 8.07.2022.
//

#ifndef HW3_CUSTOMER_H
#define HW3_CUSTOMER_H
#include "string"
#include "iostream"
using namespace std;
#include "Accounts.h"


class Customer {
public:
    Customer();
    Customer(string firstName, string lastName, int customerId);
    Customer(const Customer& c);
    ~Customer();
    struct customerNode{
        customerNode *next;
        string firstName;
        string lastName;
        int customerId;
        Accounts::accountNode *headA;
        int sizeA;
    };

    customerNode *headC;



};


#endif //HW3_CUSTOMER_H
