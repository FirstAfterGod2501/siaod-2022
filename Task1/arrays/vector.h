//
// Created by first on 22.02.23.
//

#ifndef SIAOD_VECTOR_H
#define SIAOD_VECTOR_H

#include <vector>
#include <iterator>
#include "../traffic_violation.h"

namespace arrays{
    struct vector_wrapper {
    private:

        std::vector<traffic_violation> array;

    public :
        int size = 0;

        void append(const traffic_violation &element) {
            array.push_back(element);
        }

        void erase(const traffic_violation &element) {
            std::remove_if(array.begin(), array.end(), [&](const traffic_violation &violation) {
                return violation.car_number == element.car_number;
            });
        }

        void print_array(std::ostream &out) {
            std::for_each(array.begin(), array.end(), [&](traffic_violation violation) {
                out << violation.Get_information_about_violation();
            });
        }

        traffic_violation read(traffic_violation violation) {
            violation.Add_traffic_violation();
            return violation;
        }

        void sort() {
            std::sort(array.begin(),array.end(),[&](traffic_violation left, traffic_violation right){
                return left.car_number < right.car_number;
            });
        }
        traffic_violation &operator[](std::int32_t index) noexcept {
            return array[index];
        }
    };
}

#endif //SIAOD_VECTOR_H
