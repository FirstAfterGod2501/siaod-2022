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
#include "traffic_violation.h"

struct dynamic_array{
private:
    int maxsize;
    traffic_violation* ar;

    void shift(traffic_violation *array, int i, int j)
    {
        while(i < j)
        {
            traffic_violation tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
public:

    int size = 0;

    dynamic_array(){
        this->maxsize=0;
        this->ar = new traffic_violation[size+1];
    }

    void append(traffic_violation &element) {
        if(size+1 >= maxsize) {
            auto *new_array = new traffic_violation[size+1];
            std::memcpy(new_array, ar, (size) * sizeof(traffic_violation));
            delete[] ar;
            new_array[size] = element;
            ar = new_array;
            ++size;
            return;
        }
        ar[size+1] = element;
        ++size;
    }

    void erase(int start,int end,traffic_violation element){
        for (int i = start; i < end; ++i) {
            shift(ar,i,end);
        }
    }

    void print_array(std::ostream &out){
        for (int i = 0; i < size; ++i) {
            out<<ar[i].Get_information_about_violation()<<"\n\n\n";
        }
    }

    traffic_violation read(traffic_violation violation){
        violation.Add_traffic_violation();
        return violation;
    }

    ~dynamic_array(){
        delete(ar);
    }
};



#endif //SIAOD_DYNAMIC_ARRAY_H
