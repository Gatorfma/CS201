//
// Created by FURKAN MERT on 28.07.2022.
//

#ifndef HW4_STACK_H
#define HW4_STACK_H
#include "string"
#include "iostream"
using namespace std;
const int MAX_STACK =100;
typedef char StackItemType;

class Stack {

public:
    Stack();

    bool isEmpty();
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop);

private:
    StackItemType items[MAX_STACK];
    int top;
};


#endif //HW41_STACK_H
