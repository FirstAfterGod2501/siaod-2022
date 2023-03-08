//
// Created by first on 08.03.23.
//

#ifndef TASK3_STACK_BY_LIST_H
#define TASK3_STACK_BY_LIST_H
#include <list>
#include <iostream>

template<typename Type>
struct Node {
public:

    Type data;

    Node *link;

    explicit Node(int n) {
        this->data = n;
        this->link = NULL;
    };
};
template<typename Type>
class stack {
private:
    Node<Type> *stack_by_list;
public:
    stack() { stack_by_list = NULL; }

    void push(int data) {
        auto temp = new Node<Type>(data);
        temp->data = data;
        temp->link = stack_by_list;
        stack_by_list = temp;
    }

    bool isEmpty() {
        return stack_by_list == NULL;
    }

    int top() {
        if (!isEmpty())
            return stack_by_list->data;
        }

    void pop() {
        Node<Type> *temp;
        if (stack_by_list == NULL) {
            std::cout << "\nStack Underflow" << std::endl;
        } else {
            temp = stack_by_list;
            stack_by_list = stack_by_list->link;
            free(temp);
        }
    }

    void display() {
        Node<Type> *temp;

        // Check for stack underflow
        if (stack_by_list == NULL) {
            std::cout << "\nStack Underflow";
            exit(1);
        } else {
            temp = stack_by_list;
            while (temp != NULL) {
                std::cout << temp->data;
                temp = temp->link;
                if (temp != NULL)
                    std::cout << " -> ";
            }
        }
    }
};
#endif
