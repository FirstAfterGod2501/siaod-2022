//
// Created by first on 08.03.23.
//

#ifndef TASK3_CALCULATE_PREFIX_EXPRESSION_H
#define TASK3_CALCULATE_PREFIX_EXPRESSION_H
#include <iostream>
#include <stack>
#include "stack_by_list.h"
struct calculator {
    double evaluatePrefix(std::string exprsn) {
        stack<double> Stack;
        for (int j = static_cast<int>(exprsn.size()) - 1; j >= 0; j--) {
            if (isdigit(exprsn[j]))
                Stack.push(exprsn[j] - '0');
            else {
                double o1 = Stack.top();
                Stack.pop();
                double o2 = Stack.top();
                Stack.pop();
                switch (exprsn[j]) {
                    case '+':
                        Stack.push(o1 + o2);
                        break;
                    case '-':
                        Stack.push(o1 - o2);
                        break;
                    case '*':
                        Stack.push(o1 * o2);
                        break;
                    case '/':
                        Stack.push(o1 / o2);
                        break;
                }
            }
        }
        return Stack.top();
    }
};
#endif
