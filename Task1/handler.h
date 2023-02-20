//
// Created by first on 21.02.23.
//

#ifndef SIAOD_HANDLER_H
#define SIAOD_HANDLER_H

#include "traffic_violation.h"
#include "static_array.h"
#include "dynamic_array.h"

namespace handler{
    template<typename Array>
    struct handler {
    public:
        Array array;

        void Insertion(traffic_violation violation) {
            array.append(violation);
            array.sort();
        }

        void Delete(traffic_violation violation){
            array.erase(violation);
        }

        void Delete(std::string car_number){
            for(int i =0; i< array.size; ++i){
                if(array[i].car_number == car_number){
                    Delete(array[i]);
                }
            }
        }

        void OutputWithPredicate(const std::string& article){
            for(int i = 0; i< array.size;++i){
                if(array[i].article == article){
                    std::cout << array[i].Get_information_about_violation() << "\n";
                }
            }
        }

        void Output(){
            for(int i = 0; i< array.size;++i){
                std::cout << array[i].Get_information_about_violation() << "\n";
            }
        }
    };
}


#endif //SIAOD_HANDLER_H
