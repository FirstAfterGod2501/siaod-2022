//
// Created by first on 14.02.23.
//

#ifndef SIAOD_TRAFFIC_VIOLATION_H
#define SIAOD_TRAFFIC_VIOLATION_H
#endif //SIAOD_TRAFFIC_VIOLATION_H

#include <string>
#include <chrono>
#include <sstream>
#include <iostream>
#include "utils.h"

struct traffic_violation{
    template<class Type>
    void get_value(Type &value){
        utils::input(value,[](const std::string& input){return true;},
                     [](const std::string& input){return input;});
    }


    void Add_traffic_violation(){
        std::cout<<"Enter car number\n";
        std::cin>>car_number;
        std::cout<<"Enter full name\n";
        get_value(full_name);
        std::cout<<"Enter model of car\n";
        get_value(model);
        std::cout<<"Enter date of violation\n";
        std::cin>>date_of_violation;
        std::cout<<"Enter place of violation\n";
        get_value(place_of_violation);
        std::cout<<"Enter article\n";
        get_value(article);
        std::cout<<"Enter punishment\n";
        std::cin>>punishment;
    }

    std::string Get_information_about_violation(){
        return "car number: " + car_number +
               "\nfull name: " + full_name +
               "\nmodel: " + model +
               "\ndate of violation: " + asctime(gmtime(&date_of_violation))
               +"\narticle: " + article+
               +"\npunishment: " + std::to_string(punishment);

    }

    std::string car_number;

    std::string full_name;

    std::string model;

    time_t date_of_violation;

    std::string place_of_violation;

    std::string article;

    int punishment;

};
