//
// Created by Oddin on 28.07.2023.
//
#include <iostream>

void printString(const char* str);

void swap(int *a,int *b);

//int main(){
//    int f = 10;
//    int s = 20;
//
//    swap(&f,&s);
//
//    std::cout << f << '\t' << s;
//
//    char* str = "Hello, world!";
//    printString(str);
//
//    std::cout << *str;
//
//    return 0;
//}

//Task 3
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Task 4
void printString(const char* str) {
    while (*str != '\0') {
        std::cout << *str;
        str++;
    }
}
