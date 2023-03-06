//
// Created by first on 04.03.23.
//

#ifndef TASK2_MODIFIED_LIST_H
#define TASK2_MODIFIED_LIST_H
#include <iostream>
#include <list>
#include <algorithm>


struct modified_list{

    int size = 0;

    std::list<char> *listptr;

    modified_list(){
        listptr = new std::list<char>;
    }

    void sort() const{
        listptr->sort();
    }

    void push_back(char a){
        listptr->push_back(a);
        ++size;
    }

    void push_front(char a){
        listptr->push_front(a);
        ++size;
    }

    void erase(int begin,int end) const {
        for (int i = begin; i < end; ++i) {
            listptr->erase(std::find_if(listptr->begin(), listptr->end(),
                                        [&](auto a) { return a == get_char_by_index(i); }));
        }
    }

    template<typename Predicate>
    void erase(std::list<char>::iterator begin,std::list<char>::iterator end, Predicate predicate){
        for (auto it = begin; it != end;) {
            if (predicate(*it)) {
                it = listptr->erase(it);
            } else {
                ++it;
            }
        }
    }

    static bool find(std::list<char>::iterator begin,std::list<char>::iterator end,char predicate){
        for(auto  it = begin; it!= end;) {
            if (predicate == *it) {
                return true;
            } else {
                it++;
            }
        }
        return false;
    }

    template<typename Predicate>
    static bool find(std::list<char>::iterator begin,std::list<char>::iterator end,Predicate predicate){
        for(auto  it = begin; it!= end;) {
            if (predicate == *it) {
                return true;
            } else {
                it++;
            }
        }
        return false;
    }

    void print() const{
        for (char i : *listptr) {
            std::cout << i << " ";
        }
        std::cout << '\n';

    }

    ~modified_list(){
        delete listptr;
    }

    char get_char_by_index(int index) const{
        int counter = 0;
        for (char element : *listptr) {
            if(counter == index){
                return element;
            }
            ++counter;
        }
        return 0;
    }

    char operator[](int idx) const  {
        int counter = 0;
        for (char element : *listptr) {
            if(counter == idx){
                return element;
            }
            ++counter;
        }
        return 0;
    }
};

#endif //TASK2_MODIFIED_LIST_H
