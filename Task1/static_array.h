#include <cassert>
#include <cstring>
#include <iostream>
#include <utility>
#include <algorithm>
#include "traffic_violation.h"

template<std::size_t Size>
struct static_array {
    int size = 0;
private:
    int maxsize{};
    traffic_violation array[Size];
public:

    static_array(){
        this->maxsize=Size;
    }

    void append(const traffic_violation& element) {
        if (size + 1 < maxsize) {
            array[size] = element;
            size++;
            return;
        }
        exit(139);
    }

    void print_array(std::ostream &out) {
        for (int i = 0; i < size; ++i) {
            out << array[i].Get_information_about_violation() << "\n";
        }
    }

    traffic_violation read(traffic_violation violation){
        violation.Add_traffic_violation();
        return violation;
    }
    traffic_violation &operator[](std::int32_t index) const noexcept {
        if (index >= 0 && index <= size) {
            return *(static_array::array + index);
        }
        else {
            throw std::length_error("Index is out of range.");
        }
    }
};