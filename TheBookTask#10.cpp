//
// Created by Oddin on 01.08.2023.
//
#include <iostream>

int add(int a,int b);
int subtract(int a,int b);
int multiply(int a, int b);
int divide(int a,int b);

typedef int (*arithmeticFcn)(int, int);

struct ArithmeticStruct{

    char oper;
    arithmeticFcn ptrA;
};

arithmeticFcn getArithmeticFcn(char oper);

ArithmeticStruct arithmeticStructArr[4] = {
        {'+', add},
        {'-',subtract},
        {'*',multiply},
        {'/',divide}
};

//int main() {
//    int numbF, numbS;
//    char oper;
//
//    std::cout << "Enter two numbers :";
//
//    std::cin >> numbF >> numbS;
//
//    std::cout << "Enter operand :";
//
//    std::cin >> oper;
//
//    arithmeticFcn ptr = getArithmeticFcn(oper);
//
//    if (ptr == nullptr) {
//        std::cout << "Error! Invalid operand." << std::endl;
//    } else {
//        int result = ptr(numbF, numbS);
//        std::cout << "Result: " << result << std::endl;
//    }
//
//    return 0;
//
//}

int add(int a,int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}
int multiply(int a, int b){
    return a*b;
}
int divide(int a,int b){
    return a/b;
}

arithmeticFcn getArithmeticFcn(char oper){

   for(auto i : arithmeticStructArr){
       if(i.oper == oper){
           return i.ptrA;
       }
   }
    return nullptr;
}

