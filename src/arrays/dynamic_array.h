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
    struct dynamic_array {
    private:
        std::size_t capacity {};

        std::size_t size {};

        std::size_t index {};

        traffic_violation *array;

        static void shift(traffic_violation *array, std::size_t i, std::size_t j) {
            while (i < j) {
                std::swap(array[i], array[j]);
                i++;
                j--;
            }
        }
        
        static traffic_violation* reallocate_array(traffic_violation* src, std::size_t size_prev, std::size_t size_new) {
            auto* dest = new traffic_violation[size_new];
            std::copy(src, src+size_prev, dest);
            delete[] src;
            return dest;
        }

    public:
        explicit dynamic_array(std::size_t size): capacity(size+1), array(new traffic_violation[capacity]), size(size)
        {
        }

        void append(traffic_violation &element) {
            if (index == size) {
                std::size_t prev_size = capacity;
                array = reallocate_array(array, prev_size, ++capacity);
                array[index] = element;
                ++index;
                ++size;
                return;
            }
            array[index] = element;
            ++index;
        }

        void erase(const traffic_violation &element) {
            for (int i = 0; i < index; ++i) {
                shift(array, i, index);
            }
        }

        void print_array(std::ostream &out) {
            for (std::size_t i = 0; i < index; ++i) {
                if (!array[i].car_number.empty()) {
                    out << array[i].Get_information_about_violation() << "\n\n\n";
                }
            }
        }

        void sort() {
            for (std::size_t i = 0; i < index - 1; ++i) {
                for (std::size_t j = 0; j < index - i - 1; ++j) {
                    if (array[j].car_number > array[j + 1].car_number) {
                        std::swap(array[j], array[j + 1]);
                    }
                }
            }
        }

        static void read(traffic_violation& violation) {
            violation.Add_traffic_violation();
        }

        traffic_violation &operator[](std::size_t idx) noexcept {
            if (idx < size) {
                return static_cast<traffic_violation &>(*(dynamic_array::array + idx));
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
