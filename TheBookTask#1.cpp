//
// Created by Oddin on 26.07.2023.
//
#include <iostream>


// The Game

enum Items {
    ARROW,
    TORCH,
    BOTTLE
};

int countTotalItems(Items arr[]);

//int main(){
//    Items arr[] = {BOTTLE, BOTTLE, BOTTLE, TORCH, TORCH, TORCH, TORCH, TORCH, TORCH, TORCH,
//                   ARROW, ARROW, ARROW, ARROW, ARROW, ARROW, ARROW, ARROW, ARROW,
//                   ARROW, ARROW};
//
//    std::cout << countTotalItems(arr);
//
//    return 0;
//}

int countTotalItems(Items arr[]){
    int count = 0;
    while (true){
        if(arr[count] == BOTTLE || arr[count] == TORCH || arr[count] == ARROW ){
            count++;
        } else{
            break;
        }
    }
    return count;
}
