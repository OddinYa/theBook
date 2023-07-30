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
    int playBlackjack(std::array<Card, sizeDeck> deck, int *cardPosition);

void swapCard(Card*, Card*);
void printCard(Card*);
int getRandom();
void shuffleDeck(std::array<Card,sizeDeck>& deck);
int getCardValue(Card card);
void whoWon(int fPlayer,int sPlayer);


std::array<Card,52> *fullDeck(int rangs, int suits);


int main(){

    Card cart;

    std::array<Card,sizeDeck> *deck = fullDeck((int)Rang::ALL_RANG - 1, (int)Suit::ALL_SUIT);
    shuffleDeck(*deck);

//    for(auto i : *deck){
//        printCard(&i);
//    }

    int coutn = 0;


    whoWon(playBlackjack(*deck,&coutn), playBlackjack(*deck,&coutn));

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

void shuffleDeck(std::array<Card,sizeDeck> &deck){

    int random;

    for (int i = 0; i < sizeDeck; i++) {

        random = getRandom();
        swapCard(&deck[i],&deck[random]);
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
void whoWon(int sPlayer,int fPlayer){
    if(fPlayer>sPlayer && fPlayer <= 21){

        std::cout << "Player's won "<< fPlayer << " vs " << sPlayer;
    }else if(sPlayer > fPlayer && sPlayer <= 21 ){

        std::cout << "Diller's won " << sPlayer;
    }else{
        std::cout << "Draw " << fPlayer;
    }
}

int playBlackjack(std::array<Card,sizeDeck> deck,int *cardPosition){

    bool flagBot = false;
    bool flagOut = false;
    bool firstHit = true;

    if(*cardPosition > 0){
        flagBot = true;
    }

    int player = 0;
    
    std::string playerIsDo;

    while(playerIsDo!="stand"&&!flagOut){

        if(!flagBot) {

            if(firstHit) {
                player += getCardValue(deck[*cardPosition]);
            }
            std::cout << "You have is " << player << std::endl;

            std::cin >> playerIsDo;

                if(playerIsDo == "hit"){

                     player += getCardValue(deck[*cardPosition]);
                     firstHit = false;
                     *cardPosition += 1;

                }else if(playerIsDo != "stand"){

                  std::cout << "Try again, bad request" << std::endl;
                }
        }else{
            if(player<=17){

                player += getCardValue(deck[*cardPosition]);
                *cardPosition += 1;
            }else{
                flagOut = true;
                playerIsDo = "stand";
            }
        }
    }
    return player;
}


