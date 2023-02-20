#include "traffic_violation.h"
#include "tests/static_array_test.h"
#include "tests/dynamic_array_test.h"
#include "handler.h"
#include <iostream>
#include <vector>

void create_start_vector(std::vector<traffic_violation> &violations){
    int offset = 0;
    for(int i =0;i<3;++i){
        traffic_violation violation;
        violation.read_data_from_file("../default.txt",offset);
        violations.push_back(violation);
        offset+=7;
    }
}

void solve_with_vector(){
    int operations;
    std::vector<traffic_violation> violations;
    traffic_violation violation;
    create_start_vector(violations);
    while(true) {
        std::cout<<"1.From keyboard\n2.insertion\n3.delete from number\n4.output\n";
        std::cin >> operations;
        switch (operations) {
            case 1: {
                violation.Add_traffic_violation();
                break;
            }
            case 2: {
                violations.push_back(violation);
                std::sort(violations.begin(), violations.end(),
                          [&](const traffic_violation &left, const traffic_violation &right) {
                              return left.car_number > right.car_number;
                          });

                break;
            }
            case 3: {
                std::cout<<"enter car number";
                std::string car_number;
                std::cin >> car_number;
                violations.erase(
                        std::find_if(violations.begin(), violations.end(), [&](const traffic_violation &violation1) {
                            return violation1.car_number == car_number;
                        }));
                break;
            }
            case 4: {
                std::cout<<"enter article";
                std::string article;
                std::cin >> article;
                std::for_each(violations.begin(), violations.end(),
                              [&](traffic_violation violation) {
                                  if (violation.article == article) {
                                      std::cout << violation.Get_information_about_violation() << "\n";
                                  }
                              }
                );
                break;
            }
            case 5:
                std::for_each(violations.begin(), violations.end(),
                              [&](traffic_violation violation) {
                                  std::cout << violation.Get_information_about_violation() << "\n\n";
                              }
                );
                break;
        }
    }
}
void solve_with_array(){
    int operations;
    handler::handler<dynamic_array<100>> array_handler;
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

int main(int argc, char **argv){
    if(argc>1){
        std::cout<<"run tests\n";
        std::cout<<"run static array test\n";
        test::test_static_array();
        std::cout<<"static array: OK\n run dynamic array test\n\n";
        test::test_dynamic_array();
        std::cout<<"dynamic array: OK\n exit\n\n";
        return 0;
    }
    solve_with_array();
    return 0;

}
