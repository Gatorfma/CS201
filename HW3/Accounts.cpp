//
// Created by FURKAN MERT on 8.07.2022.
//

#include "Accounts.h"

Accounts::Accounts() {
    headA = NULL;
}

Accounts::Accounts(int accountId, int balance) {
    headA = new accountNode;
    headA->id = accountId;
    headA->balance = balance;
    headA->next = NULL;
}

Accounts::~Accounts() {

}

Accounts::Accounts(const Accounts &a) {

}

