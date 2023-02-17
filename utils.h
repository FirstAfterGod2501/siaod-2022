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
