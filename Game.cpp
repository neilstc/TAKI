/*Neil Michaeli 203536818*/
/*Yair Ivgi 308275601*/

#include "Game.h"
#include "Player.h"
#include <vector>
#include <iostream>


using namespace std;
// this wiil repreasent the current turn


Game::Game(){
    this->numOfPlayers = 0;
    this->numOfCards = 0;
    this-> turn = 0;
    this-> direction = 1;
    vector <Player> players;
}

void Game::start(){  
    initializeGame(); // ask the user how many players and how many cards for each onre
    fillPlayers(); //  this function will make the actual players and will put them in the players vector
    runingGame();
}

void Game::checkBounds(int& turn ) const{
    if(turn > this->numOfPlayers-1) turn = 0 ; // if all the players played and the direction is up;
    else if(turn < 0) turn = this->numOfPlayers -1 ; // id they all played and the dirtection is down ;  
}

// this function will take the number of players and cards from the user
void Game::initializeGame(){
    cout << "How many players? " << endl;
    int nop ;
    cin >> nop; // the number of players the user will decide
    
    if(nop <0 ){
        cout << "ERROR ILLEGAL NUMBER"<<endl;
        exit(0);
    }
    this->numOfPlayers = nop;
    cout << "How many cards?" << endl;
    int noc;
    cin >> noc; // the number of cards for each players
    if(noc <0 ){
        cout << "ERROR ILLEGAL NUMBER"<<endl;
        exit(0);
    }
    this->numOfCards = noc;
}

// this function will fill the actual vector of players
void Game::fillPlayers(){
   // for each player in the first loop we are assigning "numOfCards" in the second loop
    for (int i = 0 ; i<numOfPlayers; i++) {
        string playerName;
        cout<< "player number "<<i+1<<" name?" << endl;
        cin >> playerName; // getting names
        Player player(playerName,numOfCards);
        players.push_back(player);
    }
}

void Game::runingGame(){
    this->current = current.generate_card();
    while(1){
        endGame(players);
        checkBounds(turn);
        cout <<"current: " << current << endl;
        printTurn(players[turn]); // will print the cards and the player's name
        
    
        if(players[turn].play(current)){
            specialEffect(current);
        }
        checkBounds(turn);
        nextPlayer(turn); // checks which player is next
    }
}

// this function will print the players name and he's card everytime
void Game:: printTurn(Player& p)const {
    cout << p.getName()<< ", your turn - " << endl;
    cout <<"Your cards: ";
    for (int i = 0;i< p.getNumOfCards(); i++) {
        cout << "(" <<i+1<< ")" << p.getCard(i)<<" ";
    }
    cout<< endl;
}

void Game:: specialEffect(const Card &c){
    if(c.get_sign() == sign::PLUS){
        turn --;
    } else if(c.get_sign() == sign::CD){
        direction = direction%2;
        
    } else if (c.get_sign() == sign::STOP){
        if(direction == 1) turn++;
        else turn--;
    }
}

const int Game:: nextPlayer(int &turn)const {
    if(direction == 1){
        return turn++;
    } else {
        return turn --;
    }
}

void Game:: endGame(vector <Player> players)const {
    for(unsigned int i=0; i< players.size();i++){
        if(players[i].getNumOfCards() == 0){
            cout << players[i].getName()<< " wins!"<<endl;
            exit(0);
        }
    }
}
