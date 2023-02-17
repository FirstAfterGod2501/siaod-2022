//
// Created by first on 17.02.23.
//
#include "static_array.h"
#include "traffic_violation.h"
#include <iostream>

namespace test {
    void test_static_array() {
        auto *arr = new static_array(100);
        auto *vi = new traffic_violation;
        vi->Add_traffic_violation();
        arr->append(*vi);
        auto *v2 = new traffic_violation;
        arr->read(*v2);
        arr->append(*v2);
        arr->print_array(std::cout);
        arr->erase(0, arr->size, *vi);
        arr->erase(0, arr->size, *v2);
        delete (vi);
        delete (v2);
    }
}
