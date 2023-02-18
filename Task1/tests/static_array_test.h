//
// Created by first on 17.02.23.
//
#include "../static_array.h"
#include "../traffic_violation.h"
#include <iostream>

namespace test {
    void test_static_array() {
        static_array<100> arr;
        traffic_violation violation;
        traffic_violation violation_2;
        violation = arr.read(violation);
        violation_2 = arr.read(violation_2);
        arr.append(violation);
        arr.append(violation_2);
        arr.print_array(std::cout);
        arr.print_array(std::cout);
    }
}
