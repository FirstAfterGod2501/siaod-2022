//
// Created by first on 22.02.23.
//

#ifndef SIAOD_VECTOR_TEST_H
#define SIAOD_VECTOR_TEST_H

#include "../arrays/vector.h"
#include "../traffic_violation.h"
#include <iostream>

namespace test {
    void vector_test() {
        arrays::vector_wrapper arr;
        traffic_violation violation,violation1;
        violation = arrays::vector_wrapper::read(violation);
        violation1 = arrays::vector_wrapper::read(violation1);
        arr.append(violation);
        arr.append(violation1);
        arr.print_array(std::cout);
        arr.erase(violation1);
        arr.print_array(std::cout);

    }
}

#endif //SIAOD_VECTOR_TEST_H
