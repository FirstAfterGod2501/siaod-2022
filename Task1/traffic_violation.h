//
// Created by first on 14.02.23.
//

#ifndef SIAOD_TRAFFIC_VIOLATION_H
#define SIAOD_TRAFFIC_VIOLATION_H

#include <string>
#include <iostream>
#include <fstream>
#include "../utils.h"

struct traffic_violation{
    void get_value(std::string &value){
        utils::input(value);
    }

    void read_data_from_file(const std::string& path,int offset){
        std::string line;
        std::ifstream in(path);
        std::vector<std::string> temp_values;
        int line_counter = 0;
        if (in.is_open())
        {
            while (getline(in, line)) {
                if (line_counter >= offset) {
                    temp_values.push_back(line);
                }
                ++line_counter;
            }
        }
        in.close();
        int counter = 0;
        car_number = temp_values[counter++];
        full_name = temp_values[counter++];
        model = temp_values[counter++];
        date_of_violation = (time_t)std::atoi(temp_values[counter++].c_str());
        place_of_violation = temp_values[counter++];
        article = temp_values[counter++];
        punishment = std::stoi(temp_values[counter++]);
    }

    void Add_traffic_violation() {
        std::cout << "Enter car number" << std::endl;
        std::cin >> car_number;
        std::cout << "Enter full name" << std::endl;
        get_value(full_name);
        std::cout << "Enter model of car" << std::endl;
        get_value(model);
        std::cout << "Enter date of violation" << std::endl;
        std::cin >> date_of_violation;
        std::cout << "Enter place of violation" << std::endl;
        get_value(place_of_violation);
        std::cout << "Enter article" << std::endl;
        get_value(article);
        std::cout << "Enter punishment" << std::endl;
        std::cin >> punishment;
   }

    std::string Get_information_about_violation(){
        return "car number: " + car_number +
               "\nfull name: " + full_name +
               "\nmodel: " + model +
               "\ndate of violation: " + asctime(gmtime(&date_of_violation))
               +"article: " + article+
               +"\npunishment: " + std::to_string(punishment);

    }

    std::string car_number {};

    std::string full_name {};

    std::string model {};

    time_t date_of_violation {};

    std::string place_of_violation {};

    std::string article {};

    int punishment {};
};

#endif //SIAOD_TRAFFIC_VIOLATION_H
