//
// Created by first on 01.03.23.
//

#ifndef TASK2_TESTS_H
#define TASK2_TESTS_H

#include <gtest/gtest.h>
#include <iostream>
#include "../modified_list.h"

namespace test {
    TEST(ListTesting, Sort_test_1) {
        modified_list list;
        list.push_back('4');
        list.push_back('3');
        list.push_back('2');
        list.push_back('1');
        list.sort();
        for (int i = 0; i < list.size-1; ++i) {
            ASSERT_FALSE((list[i] - '0') > list[i + 1] - '0');
        }
        ASSERT_TRUE(1==1);
    }

    TEST(ListTesting, Sort_test_2) {
        modified_list list;
        list.push_back('2');
        list.push_back('2');
        list.push_back('2');
        list.push_back('2');
        list.sort();
        for (int i = 0; i < list.size-1; ++i) {
            ASSERT_FALSE((list[i] - '0') > list[i + 1] - '0');
        }
        ASSERT_TRUE(1==1);
    }

    //push_back tests
    TEST(ListTesting, push_back_test_1) {
        modified_list list;
        list.push_back('a');
        ASSERT_TRUE(list[0] == 'a');
    }

    TEST(ListTesting, push_back_test_2) {
        modified_list list;
        list.push_back('a');
        list.push_back('b');
        ASSERT_TRUE(list[1] == 'b');
    }


    //push_fron tests
    TEST(ListTesting, push_front_test_1) {
        modified_list list;
        list.push_front('a');
        list.push_front('b');
        ASSERT_TRUE(list[0] == 'b');
        ASSERT_TRUE(list[1] == 'a');
    }

    TEST(ListTesting, push_front_test_2) {
        modified_list list;
        list.push_back('a');
        list.push_back('b');
        list.push_front('c');
        ASSERT_TRUE(list[0] == 'c');
    }

    //erase tests
    TEST(ListTesting, erase_test_1) {
        modified_list list;
        list.push_back('a');
        list.push_back('b');
        list.push_front('c');
        list.erase(list.listptr->begin(),list.listptr->end(),[](char element){
            return element == 'c';
        });
        for (int i = 0; i < list.size; ++i) {
            ASSERT_FALSE(list[i] == 'c');
        }
    }

    TEST(ListTesting, erase_test_2) {
        modified_list list;
        list.push_back('a');
        list.push_back('c');
        list.push_front('c');
        list.erase(list.listptr->begin(),list.listptr->end(),[](char element){
            return element == 'c';
        });
        for (int i = 0; i < list.size; ++i) {
            ASSERT_FALSE(list[i] == 'c');
        }
    }

    TEST(ListTesting, find_test_1) {
        modified_list list;
        list.push_back('a');
        list.push_back('c');
        list.push_front('c');
        ASSERT_TRUE(modified_list::find(list.listptr->begin(),list.listptr->end(),'c'));
    }

    TEST(ListTesting, find_test_2) {
        modified_list list;
        list.push_back('a');
        list.push_back('4');
        list.push_front('q');
        ASSERT_FALSE(modified_list::find(list.listptr->begin(),list.listptr->end(),'c'));
    }
}
#endif //TASK2_TESTS_H
