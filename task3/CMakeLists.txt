cmake_minimum_required(VERSION 3.24)
project(task3)

set(CMAKE_CXX_STANDARD 14)

add_executable(task3
        main.cpp converters/infix_to_postfix.h converters/postfix_to_infix.h converters/infix_to_prefix.h calculate_prefix_expression.h stack_by_list.h)
