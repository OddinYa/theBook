#include <iostream>

std::string rSting(std::string str);
void switchVowel(std::string str);
bool isVowel(char &i);

// int main() {
//
//    system("chcp 65001");
//    std::string inputString;
//
//    std::cout << "Введите строку: ";
//    std::getline(std::cin,inputString);
//
//    std::cout << "Строка в обратном порядке: ";
//
//    std::cout << rSting(inputString) << std::endl;
//
//    std::cout << "Строка с заменой гласных: ";
//    switchVowel(inputString);
//
//
//    return 0;
//}


std::string rSting(std::string str){

    std::string result;

    for(auto it = str.rbegin();it !=str.rend();++it){
        result += *it;
    }



    return result;
}

void switchVowel(std::string str){
    for(auto it = str.begin();it != str.end();++it){

        if(isVowel(*it)){
            *it = '#';
        }
    }
    std::cout << str;
}

bool isVowel(char &i) {

    char temp = i;

    temp = std::tolower(i);

    return (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u' || temp == 'y');
    
}
