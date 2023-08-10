//
// Created by FURKAN MERT on 28.07.2022.
//

#include "Stack.h"

Stack::Stack(): top(-1) {

}

bool Stack::isEmpty() {
    return top < 0 ;
}

bool Stack::push(StackItemType newItem) {
    if (top >= MAX_STACK-1)
        return false;
    else{
        ++top;
        items[top] = newItem;
        return true;
    }
}


bool Stack::pop() {
    if (isEmpty())
        return false;
    else{
        --top;
        return true;
    }
}

bool Stack::pop(StackItemType &stackTop) {
    if (isEmpty())
        return false;
    else{
        stackTop = items[top];
        --top;
        return true;
    }
}

bool Stack::getTop(StackItemType& stackTop) {
    if (isEmpty())
        return false;
    else{
        stackTop = items[top];
        return true;

    }
}
