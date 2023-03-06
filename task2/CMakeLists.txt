cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)


project(task2)
add_executable(task2
        main.cpp
        tests/tests.h modified_list.h)
target_link_libraries(task2 gtest_main gmock_main)

