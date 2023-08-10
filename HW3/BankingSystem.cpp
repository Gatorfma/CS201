//
// Created by FURKAN MERT on 8.07.2022.
//

#include "BankingSystem.h"
#include "Customer.h"
#include "Accounts.h"

BankingSystem::BankingSystem() {
    sizeC = 0;
    headC = NULL;
    accID = 1;
}
BankingSystem::~BankingSystem() {
}


void BankingSystem::addCustomer(int customerId, string firstName, string lastName) {
    for (Customer::customerNode* cur = headC; cur != NULL; cur = cur->next){
        if(cur->customerId == customerId){
            cout << "Customer " << customerId << " already exists. " << endl;
            return;
        }
        if (cur->firstName == firstName && cur->lastName == lastName){
            cout << "Customer " << firstName << " " << lastName << " already exists!" << endl;
            return;
        }

    }
    Customer::customerNode* temp = new Customer::customerNode;
    if(headC == NULL){
        temp->next = NULL;
        temp->customerId = customerId;
        temp->lastName = lastName;
        temp->firstName = firstName;
        temp->headA = NULL;
        temp->sizeA = 0;
        cout << "Customer " << customerId << " has been added." << endl;
        headC = temp;
        sizeC++;
    } else {
        temp->next = NULL;
        temp->customerId = customerId;
        temp->lastName = lastName;
        temp->firstName = firstName;
        temp->headA = NULL;
        temp->sizeA = 0;

        Customer::customerNode* prev = NULL;
        if (sizeC == 1) {
            sizeC++;
            if (headC->lastName > lastName) {
                temp->next = headC;
                headC = temp;
            } else {
                headC->next = temp;
            }
            cout << "Customer " << customerId << " has been added." << endl;
        } else {
            for (Customer::customerNode* cur = headC; cur != NULL; cur = cur->next) {
                if (cur->lastName > lastName) {
                    temp->next = cur;
                    if (prev == NULL) {
                        headC = temp;
                    }
                    else {
                        prev->next = temp;
                    }
                    cout << "Customer " << customerId << " has been added." << endl;
                    sizeC++;
                    return;
                }
                if (cur->next == NULL) {
                    cur->next = temp;
                    cout << "Customer " << customerId << " has been added." << endl;
                    sizeC++;
                    return;
                }
                prev = cur;
            }
        }
    }
}

void BankingSystem::deleteCustomer(const int customerId) {
    if(sizeC == 1 && customerId == headC->customerId){
        headC->customerId = 0;
        sizeC--;
        cout << "Customer " << customerId << " has been deleted! " << endl;
        return;
    }
    else if(sizeC == 1 && customerId != headC->customerId){
        cout << "Customer " << customerId << " does not exist! " << endl;
    }

    Customer::customerNode* cur = headC;
    if(cur->customerId == customerId){
        headC = headC->next;
        delete cur;
        sizeC--;
        cout << "Customer " << customerId << " has been deleted! " << endl;
        return;
    }

    while (cur->next->next != NULL){
        if(cur->next->customerId == customerId){
            Customer::customerNode* temp = cur->next->next;
            delete cur->next;
            cur->next = temp;
            sizeC--;
            cout << "Customer " << customerId << " has been deleted! " << endl;
            return;
        }
        cur = cur->next;
    }

    if(cur->next->customerId == customerId){
        delete cur->next;
        cur->next = NULL;
        sizeC--;
        cout << "Customer " << customerId << " has been deleted! " << endl;
        return;
    }

    cout << "Customer " << customerId << " does not exist! " << endl;
}

int BankingSystem::addAccount(const int customerId, const double amount) {

    //temp->balance = 0;
    bool checkCustID = false;
    Customer::customerNode* cur;
    for (cur = headC; cur != NULL; cur = cur->next) {
        if (cur->customerId == customerId) {
            checkCustID = true;
            break;
        }
    }
    if (checkCustID) {
        if (cur->headA == NULL) {
            Accounts::accountNode* temp = new Accounts::accountNode;
            temp->balance = amount;
            temp->id = accID;
            temp->next = NULL;
            cout << "Account " << accID << " added for customer " << customerId << endl;
            cur->headA = temp;
            cur->sizeA++;
            accID++;
        } else {
            for (Accounts::accountNode* curA = cur->headA; curA != NULL; curA = curA->next) {
                if ( curA->next == NULL){
                    Accounts::accountNode* temp = new Accounts::accountNode;
                    temp->balance = amount;
                    temp->id = accID;
                    temp->next = NULL;
                    cout << "Account " << accID << " added for customer " << customerId << endl;
                    curA->next = temp;
                    cur->sizeA++;
                    accID++;
                    break;
                }
            }
        }
        return accID;
    }
    cout << "Customer " << customerId << " does not exist" << endl;
    return -1;
}

void BankingSystem::deleteAccount(const int accountId) {
    bool found = false;
    Customer::customerNode* cur;
    Customer::customerNode* curF;
    Accounts::accountNode* curA;

    int i = 0;
    for (curF = headC; curF != NULL; curF = curF->next){
        Accounts::accountNode* prev = NULL;
        for (curA = curF->headA; curA != NULL;curA = curA->next){
            if(curA->id == accountId){
                found = true;
                cur = curF;
                if(found){
                    if(curA->id == accountId) {
                        curF->sizeA--;
                        if (curA == curF->headA) {
                            curA = curF->headA;
                            curF->headA = curF->headA->next;
                        } else {
                            curA = prev->next;
                            prev->next = curA->next;
                        }
                        cout << "Account " << accountId << " has been deleted!" <<endl;
                        curA->next = NULL;
                        delete curA;
                        curA = NULL;
                    }
                }
                break;
            }
            prev = curA;
        }
    }
    if(!found)
        cout << "Account " << accountId << " does not exist!" << endl;
}

void BankingSystem::showAllAccounts() {
    cout << "Account ID" << "       " << "Customer ID" << "    " << "Customer Name" << "       " << "Balance" << endl;
    for (Customer::customerNode* cur = headC; cur != NULL; cur = cur->next){
        if (cur->sizeA == 0){
            cout << "There are no accounts! " << endl;
        }
        else{
            for (Accounts::accountNode* curA = cur->headA; curA != NULL; curA = curA->next){
                cout << curA->id << "               " << cur->customerId << "              " << cur->firstName<< " " << cur->lastName << "     " << curA->balance << endl;
                break;
            }
        }
    }
}

void BankingSystem::showAllCustomers() {
    if(sizeC == 0){
        cout << "There are no customers! " << endl;
    }
    else{
        cout << "Customer ID" << "      " << "Customer Name" << endl;
        for (Customer::customerNode* cur = headC; cur != NULL; cur = cur->next){
            cout << cur->customerId << "            " << cur->firstName << " " << cur->lastName << endl;
            return;
        }
    }
}

void BankingSystem::showCustomer(const int customerId) {
    for (Customer::customerNode* cur = headC; cur != NULL; cur = cur->next){
        if(cur->customerId == customerId){
            cout << "Customer ID: " << cur->customerId << "      " << " Customer Name: " << " " << cur->firstName << " " << cur->lastName << "       " << " Number of Accounts: " << cur->sizeA << endl;
        }
    }
    for (Customer::customerNode* cur = headC; cur != NULL; cur = cur->next){
        for (Accounts::accountNode* curA = cur->headA; curA != NULL; curA = curA->next){
            if (cur->customerId == customerId){
                cout << "Accounts of this customer: " << endl;
                cout << "Account ID " << "     " << "Balance" << endl;
                cout << curA->id << "               " << curA->balance << endl;
                return;
            }
        }
    }
    cout << "Customer " << customerId << " does not exists!" << endl;
}
