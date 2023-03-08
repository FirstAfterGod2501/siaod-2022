//
// Created by first on 08.03.23.
//

#ifndef TASK3_INFIX_TO_PREFIX_H
#define TASK3_INFIX_TO_PREFIX_H
#include <iostream>
#include <stack>
#include <algorithm>

struct infix_to_prefix {
    std::string infixToPostfix(std::string infix) {
        auto isOperator = [](char ch){
            return (!isalpha(ch) && !isdigit(ch));
        };
        auto getPriority = [](char ch){
            if (ch == '-' || ch == '+') {
                return 1;
            }
            else if (ch == '*' || ch == '/') {
                return 2;
            }
            else if (ch == '^') {
                return 3;
            }
            return 0;
        };


        infix = '(' + infix + ')';
        int l = static_cast<int>(infix.size());
        std::stack<char> char_stack;
        std::string output;

        for (int i = 0; i < l; i++) {
            if (isalpha(infix[i]) || isdigit(infix[i])) {
                output += infix[i];
            }
            else if (infix[i] == '('){
                char_stack.push('(');
                }
            else if (infix[i] == ')') {
                while (char_stack.top() != '(') {
                    output += char_stack.top();
                    char_stack.pop();
                }
                char_stack.pop();
            } else {
                if (isOperator(char_stack.top())) {
                    if (infix[i] == '^') {
                        while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
                            output += char_stack.top();
                            char_stack.pop();
                        }

                    } else {
                        while (getPriority(infix[i]) < getPriority(char_stack.top())) {
                            output += char_stack.top();
                            char_stack.pop();
                        }

                    }
                    char_stack.push(infix[i]);
                }
            }
        }
        while (!char_stack.empty()) {
            output += char_stack.top();
            char_stack.pop();
        }
        return output;
    }

    std::string infixToPrefix(std::string infix) {
        int l = static_cast<int>(infix.size());
        std::reverse(infix.begin(), infix.end());
        for (int i = 0; i < l; i++) {

            if (infix[i] == '(') {
                infix[i] = ')';
            } else if (infix[i] == ')') {
                infix[i] = '(';
            }
        }
        std::string prefix = infixToPostfix(infix);
        reverse(prefix.begin(), prefix.end());
        return prefix;
    }
};
#endif
