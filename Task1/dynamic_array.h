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

    dynamic_array(int max_size){
        this->maxsize=max_size;
        this->ar = new traffic_violation[size+1];
    }

    void append(traffic_violation element) {
        ++size;
        auto * new_array = new traffic_violation[size];
        std::memcpy(new_array, ar, size-1 * sizeof(traffic_violation));
        ar = new_array;
        delete [] new_array;
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
