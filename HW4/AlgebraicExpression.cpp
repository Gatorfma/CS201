//
// Created by FURKAN MERT on 28.07.2022.
//

#include "AlgebraicExpression.h"
#include <string>
using namespace std;
#include "Stack.h"


double evaluatePostfix(const string exp) {
    Stack s;
    char c;
    double result;
    for (int i = 0; i < MAX_STACK; ++i) {
        if (isdigit(exp[i]))
            s.push(exp[i] - '0');

        else{
            int op = s.getTop(c);
            s.pop();

            int op2 = s.getTop(c);
            s.pop();

            if (exp[i] == '+')
                s.push(op+op2);
            else if (exp[i] == '-')
                s.push(op-op2);
            else if (exp[i] == '*')
                s.push(op*op2);
            else if (exp[i] == '/')
                s.push(op/op2);
        }
    }
    result = s.getTop(c);
    return result;
}

string infix2postfix(const string exp) {
    Stack st;
    string result;
    char c;
    for (int i = 0; i < MAX_STACK; ++i) {
        char c = exp[i];
        if((c>='a' && c<= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if(c == '(')
            st.push('(');
        else if(c == ')') {
            st.getTop(c);
            while (c != '(') {
                st.getTop(c);
                result += c;
                st.pop();
            }
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    while (!st.isEmpty()){
        st.getTop(c);
        result += c;
        st.pop();
    }
    return result;
}

int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
