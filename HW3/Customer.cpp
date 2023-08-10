//
// Created by FURKAN MERT on 8.07.2022.
//

#include "Customer.h"
#include "Accounts.h"

Customer::Customer() {
    headC->sizeA = 0;
    headC->headA = NULL;
}

Customer::Customer(const Customer &c) {

}


Customer::Customer(string firstName, string lastName, int customerId) {
    headC->sizeA = 1;
    headC = new customerNode;
    headC->firstName = firstName;
    headC->lastName = lastName;
    headC->customerId = customerId;
    headC->next = NULL;

}

Customer::~Customer() {
}






