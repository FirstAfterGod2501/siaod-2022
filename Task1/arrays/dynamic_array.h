//
// Created by first on 18.02.2023.
//

#ifndef SIAOD_DYNAMIC_ARRAY_H
#define SIAOD_DYNAMIC_ARRAY_H

#include <cassert>
#include <cstring>
#include <iostream>
#include <utility>
#include <algorithm>
#include "../traffic_violation.h"

namespace arrays {
    template<int Size>
    struct dynamic_array {
    private:
        int maxsize;
        traffic_violation *array = new traffic_violation[Size];

        static void shift(traffic_violation *array, int i, int j) {
            while (i < j) {
                traffic_violation tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                i++;
                j--;
            }
        }

    public:

        int size = 0;

        dynamic_array() {
            this->maxsize = 0;
            this->array = new traffic_violation[size + 1];
        }

        void append(traffic_violation &element) {
            if (size + 1 >= maxsize) {
                auto *new_array = new traffic_violation[size + 1];
                std::memcpy(new_array, array, (size) * sizeof(traffic_violation));
                delete[] array;
                new_array[size] = element;
                array = new_array;
                ++size;
                return;
            }
            array[size + 1] = element;
            ++size;
        }

        void erase(const traffic_violation &element) {
            for (int i = 0; i < size; ++i) {
                shift(array, i, size);
            }
        }

        void print_array(std::ostream &out) {
            for (int i = 0; i < size; ++i) {
                out << array[i].Get_information_about_violation() << "\n\n\n";
            }
        }

        void sort() {
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (array[j].car_number > array[j + 1].car_number) {
                        std::swap(array[j], array[j + 1]);
                    }
                }
            }
        }

        traffic_violation read(traffic_violation violation) {
            violation.Add_traffic_violation();
            return violation;
        }

        traffic_violation &operator[](std::int32_t index) noexcept {
            if (index >= 0 && index <= size) {
                return static_cast<traffic_violation &>(*(dynamic_array::array + index));
            } else {
                throw std::length_error("Index is out of range.");
            }
        }

        ~dynamic_array() {
            delete[] array;
        }
    };
}


#endif //SIAOD_DYNAMIC_ARRAY_H
