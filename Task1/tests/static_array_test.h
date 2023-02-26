//
// Created by first on 17.02.23.
//
#include "../arrays/static_array.h"
#include "../traffic_violation.h"
#include <iostream>

namespace test {
    void test_static_array() {
        arrays::static_array<100> arr {};
        traffic_violation violation {}, violation1 {};
        violation = arr.read(violation);
        violation1 = arr.read(violation1);
        arr.append(violation);
        arr.append(violation1);
        arr.print_array(std::cout);
    }
}
