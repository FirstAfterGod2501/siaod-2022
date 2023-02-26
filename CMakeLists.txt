cmake_minimum_required(VERSION 3.24)
project(siaod)

set(CMAKE_CXX_STANDARD 20)

add_executable(siaod
        src/main.cpp
        utils.h
        src/traffic_violation.h
        src/arrays/static_array.h
        src/tests/static_array_test.h src/arrays/dynamic_array.h src/tests/dynamic_array_test.h src/handler.h src/arrays/vector.h src/tests/vector_test.h)
