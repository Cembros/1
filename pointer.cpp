// Використання покажчиків для доступу до елементів масиву
#include <iostream>

void print_string(std::string *ptr, int num = 1){
    for(int i = 0; i < num; i++){
        std::cout << *ptr << std::endl;
    }
}

int main(){
    std::string hello_w = "Hello";
    print_string(&hello_w);
    print_string(&hello_w,3);
}