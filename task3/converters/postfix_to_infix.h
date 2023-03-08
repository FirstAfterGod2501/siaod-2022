//
// Created by first on 08.03.23.
//
#include <stack>
#include <iostream>
struct postfix_to_infix {
    bool isOperand(char x) {
        return (x >= 'a' && x <= 'z') ||
               (x >= 'A' && x <= 'Z');
    }

    std::string getInfix(std::string exp) {
        std::stack<std::string> s;

        for (int i = 0; exp[i] != '\0'; i++) {
            if (isOperand(exp[i])) {
                std::string op(1, exp[i]);
                s.push(op);
            } else {
                std::string op1 = s.top();
                s.pop();
                std::string op2 = s.top();
                s.pop();
                s.push("(" + op2 + exp[i] +
                       op1 + ")");
            }
        }
        return s.top();
    }
};
