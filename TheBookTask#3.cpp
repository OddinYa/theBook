//
// Created by Oddin on 29.07.2023.
//
#include <random>
#include <iostream>
#include <array>

const int sizeDeck = 52;

enum Rang{
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    LADY,
    KING,
    ASE,
    ALL_RANG ,
};

enum Suit{
    DIAMONDS,
    HEARTS,
    CLUBS,
    SPADES,
    ALL_SUIT
};

struct Cart{
    Rang rang;
    Suit suit;
};

void printCard(Cart*);
int getRandom();

std::array<Cart,52> *fullDeck(int rangs,int suits);

int main(){

    Cart cart;

    std::array<Cart,sizeDeck> *deck = fullDeck((int)Rang::ALL_RANG-1,(int)Suit::ALL_SUIT);

    for(auto i : *deck){
        printCard(&i);
    }


    delete deck;
    return 0;
}



int getRandom()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int min = 1;
    int max = 100;
    std::uniform_int_distribution<>dis(min, max);

    return dis(gen);
}

void printCard(Cart *cart){

    if(cart->rang < 11){
        std::cout << cart->rang;
    } else{

        switch ((int)cart->rang) {
            case 11: std::cout << "V";break;
            case 12: std::cout << "L";break;
            case 13: std::cout << "K";break;
            case 14: std::cout << "A";break;
        }
    }
    switch (cart->suit) {
        case DIAMONDS: std::cout << "D"; break;
        case HEARTS: std::cout << "H"; break;
        case CLUBS: std::cout << "C"; break;
        case SPADES: std::cout << "S"; break;
    }
    std::cout << '\t';

}

std::array<Cart,sizeDeck>* fullDeck(int rangs,int suits){

    std::array<Cart,sizeDeck> *deck = new std::array<Cart,sizeDeck>;

    int size = 0;

    for (int i = 0; i < suits; i++) {

        for (int j = 2; j <= rangs; j++) {

            Cart cart;
            cart.rang =(Rang)j;
            cart.suit =(Suit)i;

            (*deck)[size] = cart;

            size++;
        }
    }
    return deck;

}





