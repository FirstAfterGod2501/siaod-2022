//
// Created by first on 18.02.2023.
//

#ifndef SIAOD_DYNAMIC_ARRAY_TEST_H
#define SIAOD_DYNAMIC_ARRAY_TEST_H

#include "../dynamic_array.h"
#include "../traffic_violation.h"
#include <iostream>

namespace test {
    void test_dynamic_array() {
        auto arr = new dynamic_array<100>;
        traffic_violation violation,violation1;
        violation = arr->read(violation);
        violation1 = arr->read(violation1);
        arr->append(violation);
        arr->append(violation1);
        arr->print_array(std::cout);
    }
}

#endif //SIAOD_DYNAMIC_ARRAY_TEST_H
