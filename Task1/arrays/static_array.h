#ifndef SIAOD_STATIC_ARRAY_H
#define SIAOD_STATIC_ARRAY_H

#include <cassert>
#include <cstring>
#include <iostream>
#include <utility>
#include <algorithm>
#include "../traffic_violation.h"
namespace arrays {
    template<std::size_t Size>
    struct static_array {
    private:
        int maxsize{};

        traffic_violation array[Size];


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

        static_array() {
            this->maxsize = Size;
        }

        void append(const traffic_violation &element) {
            if (size + 1 < maxsize) {
                array[size] = element;
                size++;
                return;
            }
            exit(139);
        }

        void erase(const traffic_violation &element) {
            for (int i = 0; i < size; ++i) {
                shift(array, i, size);
            }
        }

        void print_array(std::ostream &out) {
            for (int i = 0; i < size; ++i) {
                out << array[i].Get_information_about_violation() << "\n";
            }
        }

        traffic_violation read(traffic_violation violation) {
            violation.Add_traffic_violation();
            return violation;
        }

        void sort() {
            std::sort(std::begin(array), std::end(array),
                      [](const traffic_violation &left, const traffic_violation &right) {
                          return left.car_number > right.car_number;
                      });
        }

        traffic_violation &operator[](std::int32_t index) noexcept {
            if (index >= 0 && index <= size) {
                return static_cast<traffic_violation &>(*(static_array::array + index));
            } else {
                throw std::length_error("Index is out of range.");
            }
        }
    };
}
#endif //SIAOD_STATIC_ARRAY_H