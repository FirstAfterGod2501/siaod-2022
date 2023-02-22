cmake_minimum_required(VERSION 3.24)
project(siaod)

set(CMAKE_CXX_STANDARD 20)

add_executable(siaod
        Task1/main.cpp
        utils.h
        Task1/traffic_violation.h
        Task1/arrays/static_array.h
        Task1/tests/static_array_test.h Task1/arrays/dynamic_array.h Task1/tests/dynamic_array_test.h Task1/handler.h Task1/arrays/vector.h Task1/tests/vector_test.h)
