//
// Created by Oddin on 02.08.2023.
//
//Напишите программу, которая запрашивает у пользователя целое число N и вычисляет сумму всех чисел от 1 до N, включительно.
//
#include <iostream>

int sumNs(int*);

int main(){

    int numb;
    std::cout << "Enter number :";
    std::cin >> numb;

    std::cout << "Sum " << 1 <<" "<< numb << " : " << sumNs(&numb);


    return 0;
}

int sumNs(int *numb){
    int sum = 0;

    for(int i = 1; i <= *numb; i++){
        sum+=i;
    }
    return sum;
}