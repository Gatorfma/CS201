//
// Created by FURKAN MERT on 28.07.2022.
//

#ifndef HW4_ALGEBRAICEXPRESSION_H
#define HW4_ALGEBRAICEXPRESSION_H
#include "string"
#include "iostream"
using namespace std;

string infix2postfix(const string exp );
double evaluatePostfix( const string exp );
int precedence(char c);



#endif //HW4_ALGEBRAICEXPRESSION_H
