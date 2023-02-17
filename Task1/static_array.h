#include <cassert>
#include <cstring>
#include <iostream>
#include <utility>
#include <algorithm>
#include "traffic_violation.h"


struct static_array {
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

    static_array(int max_size){
        this->maxsize=max_size;
        this->ar = new traffic_violation[max_size];
    }

    void append(traffic_violation element) {
        if (size + 1 < maxsize) {
            ++size;
            ar[size] = std::move(element);
            return;
        }
        exit(139);
    }

    void erase(int start,int end,traffic_violation element){
        for (int i = start; i < end; ++i) {
            shift(ar,i,end);
        }
    }

    void print_array(std::ostream &out){
        for (int i = 0; i < size; ++i) {
            out<<ar[i].Get_information_about_violation()<<" ";
        }
    }

    traffic_violation read(traffic_violation violation){
        violation.Add_traffic_violation();
        return violation;
    }

     ~static_array(){
        delete(ar);
    }
};