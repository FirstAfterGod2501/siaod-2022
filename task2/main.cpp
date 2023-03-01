//3
class list;

/*
 * Даны два линейных однонаправленных
списка L1 и L2.
1) Разработать функцию, которая формирует
список L, включив в него по одному разу
элементы, значения которых входят в список L1
и не входят в список L2.
2) Разработать функцию, которая удаляет
подсписок списка
L1 заданный диапазоном
позиций. Например, со второго три.
3) Разработать функцию, которая
упорядочивает значения списка
L2, располагая
их в порядке возрастания.
 */

#include <iostream>
#include <list>
#include <algorithm>

struct modified_list{

    int size = 0;

    std::list<char> listptr;

    modified_list(){
        listptr = *new std::list<char>;
    }

    void sort(){
        listptr.sort();
    }

    void append(char a){
        listptr.push_back(a);
        ++size;
    }

    template<typename Predicate>
    void erase(std::list<char>::iterator begin,std::list<char>::iterator end, Predicate predicate){
        for (auto it = begin; it != end;) {
            if (predicate(*it)) {
                it = listptr.erase(it);
            } else {
                ++it;
            }
        }
    }

    static bool find(std::list<char>::iterator begin,std::list<char>::iterator end,char c){
        for(auto  it = begin; it!= end;) {
            if (c == *it) {
                return true;
            } else {
                it++;
            }
        }
        return false;
    }

    void print(){
        for (char i : listptr) {
            std::cout << i << " ";
        }
        std::cout << '\n';

    }

    char operator[](int idx)  {
        int counter = 0;
        for (char element : listptr) {
            if(counter == idx){
                return element;
            }
            ++counter;
        }
        return 0;
    }
};

modified_list format_L(modified_list L1, modified_list L2){
    modified_list L;
    for (int i = 0; i < L1.size; ++i) {
        auto value = L1[i];
        if(!modified_list::find(L1.listptr.begin(),L1.listptr.end(),value)){
            if(!modified_list::find(L2.listptr.begin(),L2.listptr.end(),value)) {
                L.append(value);
            }
        }
    }
    return L;
}

int main(){
    modified_list list;
    list.append('1');
    list.append('2');
    list.append('3');
    list.append('4');
    list.append('5');
    list.append('6');
    list.append('7');
    list.append('8');
    list.append('9');
    for (int i = 0; i < list.size; ++i) {
        std::cout<<list[i]<<" ";
    }
    list.erase(list.listptr.begin(),list.listptr.end(),[](char element){
        return element == '4';
    });
    list.print();
}
