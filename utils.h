//
// Created by first on 14.02.23.
//

#ifndef SIAOD_UTILS_H
#define SIAOD_UTILS_H
#define CIN_FLUSH if (std::cin.peek()) std::cin.ignore()

#include <iostream>
#include <vector>
#include <algorithm>

namespace utils{
template<typename Type, std::size_t Size>
struct Array {
private:
    Type *ptr_array;
protected:
    auto self() const noexcept { return this; }

    using iterator = Type*;
    using c_iterator = const Type*;
public:
    Array() : ptr_array(new Type[Size]) {}

    Array(std::initializer_list<Type> list): ptr_array(new Type[list.size()]) {
        memcpy(begin(), list.begin(), list.size() * sizeof(Type));
    }

    Array(Array<Type, Size> &array) : ptr_array(new Type[Size]) {
        memcpy(begin(), array.begin(), Size * sizeof(Type));
    }

    Array(Array<Type, Size> &&array) noexcept: ptr_array(array.ptr_array) {
        array.ptr_array = nullptr;
    }

    Array(Type elem, std::uint32_t count): ptr_array(new Type[count]) {
        if (count == Size)
            std::fill(begin(), end(), elem);
        else
            throw std::length_error("Count of elements is greater than size of array.");
    }

    virtual ~Array() noexcept {
        delete[] ptr_array;
    };

    friend std::ostream &operator<<(std::ostream &stream, Array<Type, Size> &array) {
        std::for_each(array.begin(), array.end(), [&stream](const auto& elem) {
            stream << elem << " ";
        });
        stream << std::endl;
        return stream;
    }

    Type &operator[](std::int32_t index) const noexcept {
        if (index >= 0 && index <= Size) {
            return *(Array::ptr_array + index);
        } else if (std::abs(index) <= Size) {
            return *(Array::ptr_array + (Size + index));
        } else {
            throw std::length_error("Index is out of range.");
        }
    }

    Array &operator=(Array<Type, Size> const &array) {
        if (this == array.self())
            return *this;
        memcpy(begin(), array.begin(), Size * sizeof(Type));
        return *this;
    }

    Array &operator=(Array<Type, Size> &&array) noexcept {
        if (this == array.self()) {
            return *this;
        }
        this->ptr_array = array.ptr_array;
        array.ptr_array = nullptr;
        return *this;
    }

    [[nodiscard]] std::size_t size() const noexcept {
        return Size;
    }


    constexpr iterator begin() noexcept { return iterator(ptr_array); }
    constexpr c_iterator begin() const noexcept { return c_iterator(ptr_array); }

    constexpr iterator end() noexcept { return iterator(ptr_array + Size); }
    constexpr c_iterator end() const noexcept { return c_iterator(ptr_array + Size); }
};

    template <typename Type, typename inputHandler, typename cast>
    void input(Type& input, const inputHandler& handler, const cast& typeCast) {
        CIN_FLUSH;
        while (!std::cin.eof()) {
            std::string tempInput;
            std::getline(std::cin, tempInput);
            if (handler(tempInput)) {
                input = typeCast(tempInput);
                return;
            } else {
                std::cout << "wrong input\n";
            }
        }
    }

    template<typename Type>
    void output(const std::vector<std::ostream> &output_streams,const Type &output_value,const std::string &comment) {
        std::for_each(output_streams.begin(), output_streams.end(), [&](std::ostream ostream) {
            ostream<<output_value.Format_output_string<<comment;
        });
    }
}

#endif //SIAOD_UTILS_H
