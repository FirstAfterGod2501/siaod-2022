#include "modified_list.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include "tests/tests.h"

modified_list format_L(modified_list L1, modified_list L2){
    modified_list L;
    for (int i = 0; i < L1.size; ++i) {
        auto value = L1[i];
        if(!modified_list::find(L1.listptr->begin(),L1.listptr->end(),value)){
            if(!modified_list::find(L2.listptr->begin(),L2.listptr->end(),value)) {
                L.push_back(value);
            }
        }
    }
    return L;
}

void Read_from_file(modified_list &list){
        std::string line;
        std::ifstream in("../default.txt");
        if (in.is_open())
        {
            while (getline(in, line)) {
                list.push_back(line[0]);
            }
        }
        in.close();
}


[[noreturn]] void task(){
    modified_list list;
    Read_from_file(list);
    int opt{};
    modified_list list1{},list2{};
    for (int i = 0; i < 9; ++i) {
        list1.push_back(list[i]);
        list2.push_back(list[i+9]);
    }
    for(;std::cin>>opt;){
        switch (opt) {
            case 1:
                list1.print();
                list2.print();
                break;
            case 2:
                int start,end;
                std::cin >> start >> end;
                list1.erase(start,end);
                list1.print();
                break;
            case 3:
                list2.sort();
                break;
            default:
                list1.print();
                list2.print();
                break;
        }
    }
}

int main(){
    ::testing::InitGoogleTest();
    ::testing::InitGoogleMock();
    if(RUN_ALL_TESTS()){
        return 1;
    }
    task();
    return 0;
}