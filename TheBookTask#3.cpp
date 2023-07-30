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
    ACE,
    ALL_RANG ,
};

enum Suit{
    DIAMONDS,
    HEARTS,
    CLUBS,
    SPADES,
    ALL_SUIT
};

struct Card{
    Rang rang;
    Suit suit;
};

void swapCard(Card*, Card*);
void printCard(Card*);
int getRandom();
void shuffleDeck(std::array<Card,sizeDeck>& arr);
int getCardValue(Card card);

std::array<Card,52> *fullDeck(int rangs, int suits);

int main(){

    Card cart;

    std::array<Card,sizeDeck> *deck = fullDeck((int)Rang::ALL_RANG - 1, (int)Suit::ALL_SUIT);
    shuffleDeck(*deck);

    for(auto i : *deck){
        printCard(&i);
    }

    std::cout << std::endl;
    std::cout << getCardValue((*deck)[20]) << " 20card ";
    printCard(&(*deck)[20]);

    delete deck;
    return 0;
}



int getRandom()
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(0, sizeDeck - 1);

    return dis(gen);
}

void printCard(Card *card){

    if(card->rang < 11){
        std::cout << card->rang;
    } else{

        switch ((int)card->rang) {
            case 11: std::cout << "V";break;
            case 12: std::cout << "L";break;
            case 13: std::cout << "K";break;
            case 14: std::cout << "A";break;
        }
    }
    switch (card->suit) {
        case DIAMONDS: std::cout << "D"; break;
        case HEARTS: std::cout << "H"; break;
        case CLUBS: std::cout << "C"; break;
        case SPADES: std::cout << "S"; break;
    }
    std::cout << '\t';

}

std::array<Card,sizeDeck>* fullDeck(int rangs, int suits){

    std::array<Card,sizeDeck> *deck = new std::array<Card,sizeDeck>;

    int size = 0;

    for (int i = 0; i < suits; i++) {

        for (int j = 2; j <= rangs; j++) {

            Card cart;
            cart.rang =(Rang)j;
            cart.suit =(Suit)i;

            (*deck)[size] = cart;

            size++;
        }
    }
    return deck;

}

void shuffleDeck(std::array<Card,sizeDeck>& arr){

    int random;

    for (int i = 0; i < sizeDeck; i++) {

        random = getRandom();
        swapCard(&arr[i],&arr[random]);
    }


}


void swapCard(Card *firstCard, Card *secondCard){
    Card *temp = firstCard;
    *firstCard = *secondCard;
    *secondCard = *firstCard;
}

int getCardValue(Card card){

    Rang val = card.rang;

    switch (val)  {
        case JACK: return 10;
        case LADY: return 10;
        case KING: return 10;
        case ACE: return 11;
        default:
            return static_cast<int>(val);
    }
}


