/*Neil Michaeli 203536818*/
/*Yair Ivgi 308275601*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Player {
    
private:
    // name;
    string name;
    // num_of_cards;
    int numOfCards;
    // container of cards
    vector <Card> cards;
    Card choosen;
    bool isPlayed;
    
public:
    //constructors
    Player(const string name=" ",const int numOfCards=0);
    Player();
    Player (const Player &player);

    //functions
    //setters and getters
    const string getName()const ;
    const int getNumOfCards()const ;
    const Player& operator=(Player const &player); //operator=
    const Card getCard(const int index)const ;
    void setCard(const Card &card);
    void fillCards(); 
    //show function
    const bool play(Card &card);
    void deleteCard(const int cardIndex);
    void show();
};
#endif
