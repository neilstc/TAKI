/*Neil Michaeli 203536818*/
/*Yair Ivgi 308275601*/

#include "Player.h"
#include "Game.h"

Player::Player(){
    this->name = "" ;
    this->numOfCards = 0;   
}

Player::Player(const string name,const int numOfCards){
    this->name = name;
    this->numOfCards = numOfCards;
    fillCards();
}

Player::Player(const Player &player){
    this->name = player.name ;
    this->numOfCards = player.numOfCards;
    this->cards  = player.cards;// TODO make a deep copying
}

const bool Player:: play(Card &current){    
    bool isPlayed = false;
    int cardIndex;
    cin >> cardIndex;
    cardIndex --;  
    if(-1 < cardIndex && cardIndex < this->numOfCards){ // checks if the player wants to choose an actual card and play or to take from the deck;
        this->choosen = getCard(cardIndex);
        
    }
    // illegal move
    while (!current.is_legal(choosen) && (-1 < cardIndex && cardIndex <numOfCards)){
        this->choosen = getCard(cardIndex);
        cout << "You can't put " << choosen << " on " << current << endl;
        cin >> cardIndex;
        cardIndex--;
        
    }    
    if(-1 < cardIndex && cardIndex <numOfCards){      
        numOfCards-- ;// set the new value
        deleteCard(cardIndex);//delete's the card
        current = choosen; //replace current by this one ;
        isPlayed = true;
    } else {
        Card newCard = newCard.generate_card(); // will generate a randon card
        numOfCards++;
        setCard(newCard); // new card added to the players cards.
    }
    return isPlayed;
}

void Player::fillCards(){    
    for (int i =0; i<numOfCards; i++) {
        cards.push_back(Card::generate_card());
    }
}

void Player:: deleteCard(const int cardIndex){
    cards.erase(cards.begin()+cardIndex);
}

const Player& Player::operator=( Player const &player) {   
    this->name = player.name;
    this->numOfCards = player.numOfCards;
    this->cards = player.cards;
    return *this;
}

//SETTERS & GETTERS
const string Player::getName()const{
    return this->name;
}

const int Player::getNumOfCards()const{
    return this->numOfCards;
}
const Card Player::getCard(const int index)const {
    return cards[index];
}
void Player::setCard(const Card &card){
    cards.push_back(card);
}

