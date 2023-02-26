//
// Created by first on 18.02.2023.
//

#ifndef SIAOD_DYNAMIC_ARRAY_TEST_H
#define SIAOD_DYNAMIC_ARRAY_TEST_H

#include "../arrays/dynamic_array.h"
#include "../traffic_violation.h"
#include <iostream>

namespace test {
    void test_dynamic_array() {
        auto arr = arrays::dynamic_array(1);
        traffic_violation violation1 {}, violation2 {};
        arrays::dynamic_array::read(violation1);
        arrays::dynamic_array::read(violation2);
        arr.append(violation1);
        arr.append(violation2);
        arr.print_array(std::cout);
        arr.erase(violation1);
        arr.print_array(std::cout);
    }
}

#endif //SIAOD_DYNAMIC_ARRAY_TEST_H
