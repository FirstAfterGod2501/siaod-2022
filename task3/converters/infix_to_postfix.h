//
// Created by first on 07.03.23.
//

#ifndef TASK3_INFIX_TO_POSTFIX_H
#define TASK3_INFIX_TO_POSTFIX_H

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "algorithm"

struct infix_to_postfix {
    int priority(char alpha) {
        if (alpha == '+' || alpha == '-')
            return 1;

        if (alpha == '*' || alpha == '/')
            return 2;

        if (alpha == '^')
            return 3;


        return 0;
    }

    std::string convert(std::string infix) {
        int i = 0;
        std::string postfix;
        std::stack<char> s;

        while (infix[i] != '\0') {
            if (infix[i] >= 'a' && infix[i] <= 'z') {
                postfix += infix[i];
                i++;
            }
            else if (infix[i] == '(') {
                s.push(infix[i]);
                i++;
            }
            else if (infix[i] == ')') {
                while (s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                s.pop();
                i++;
            } else {
                while (!s.empty() && priority(infix[i]) <= priority(s.top())) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(infix[i]);
                i++;
            }
        }
        while (!s.empty()) {
            postfix += s.top();
            s.pop();
        }
        std::cout << "Postfix is : " << postfix;
        return postfix;
    }
};
#endif
