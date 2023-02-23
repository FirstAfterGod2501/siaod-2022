#include "traffic_violation.h"
#include "tests/static_array_test.h"
#include "tests/dynamic_array_test.h"
#include "tests/vector_test.h"
#include "handler.h"
#include <iostream>
#include <vector>

void create_start_vector(std::vector<traffic_violation> &violations){
    int offset = 0;
    for(int i = 0; i < 3 ;++i){
        traffic_violation violation;
        violation.read_data_from_file("../default.txt",offset);
        violations.push_back(violation);
        offset+=7;
    }
}

[[noreturn]] void process(){
    int operations;
    handler::handler<arrays::vector_wrapper> array_handler;
    traffic_violation violation;
    while(true){
        std::cout<<"1.From keyboard\n2.insertion\n3.delete from number\n4.output\n";
        std::cin>>operations;
        switch (operations) {
            case 1: {
                violation.Add_traffic_violation();
                break;
            }
            case 2: {
                array_handler.Insertion(violation);
                break;
            }
            case 3: {
                std::cout << "enter car number: ";
                std::string car_number;
                std::cin >> car_number;
                array_handler.Delete(car_number);
                break;
            }
            case 4: {
                std::cout << "enter article: ";
                std::string article;
                std::cin >> article;
                array_handler.OutputWithPredicate(article);
                break;
            }
            default:
                array_handler.Output();
        }
    }
}

void running_test(){
    std::cout<<"run tests\n";
    std::cout<<"run static array test///\n\n";
    test::test_static_array();
    std::cout<<"static array: OK\nrun dynamic array test....\n\n";
    test::test_dynamic_array();
    std::cout<<"dynamic array: OK\nRunning vector test... \n\n";
    test::vector_test();
    std::cout<<"vector: OK\nexit... \n\n";
    return;
}

int main(int argc, char **argv){
    if(argc>1){
        running_test();
        return 0;
    }
    process();
}
