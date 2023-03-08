#include <iostream>
#include <list>

//too easy

int found_max(int num,int max){
    if(num == 0){
        return max;
    }
    if(num % 10 > max) {
        max = num % 10;
    }
    return found_max(num/10,max);
}

int found_nodes(std::list<int> list,int counter){
    if(list.empty()){
        return counter;
    }
    if(list.front() % 2 != 0){
        ++counter;
    }
    list.pop_front();
    return found_nodes(list,counter);
}

int main() {
    int num;
    std::list<int> list = {1,2,3,4,5,6,7,8,9};
    std::cout<<found_nodes(list,0);
}
