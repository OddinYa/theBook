//
// Created by Oddin on 01.08.2023.
//

#include <iostream>


void func1() {
    std::cout << "Вызвана функция 1" << std::endl;
}

void func2() {
    std::cout << "Вызвана функция 2" << std::endl;
}

    void printValues(int numb = 10,std::string = "Hello, World!" );

//int main(){
//
//    printValues(); // Выводит на экран: 10 Hello, World!
//    printValues(20); // Выводит на экран: 20 Hello, World!
//    printValues(30, "Привет!"); // Выводит на экран: 30 Привет!
//
//    void (*ptr)(); // Объявление указателя на функцию
//    ptr = func1; // Присваивание адреса функции func1 указателю
//    ptr(); // Вызов функции через указатель
//
//    ptr = func2; // Присваивание адреса функции func2 указателю
//    ptr(); // Вызов функции через указатель
//
//    return 0;
//
//}

void printValues(int numb,std::string str){
    std::cout << numb << " " << str;
}
