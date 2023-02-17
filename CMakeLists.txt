cmake_minimum_required(VERSION 3.24)
project(siaod)

set(CMAKE_CXX_STANDARD 20)

add_executable(siaod
        Task1/main.cpp
        utils.h
        Task1/traffic_violation.h
        Task1/static_array.h
        Task1/static_array_test.h)
