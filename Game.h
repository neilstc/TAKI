/*Neil Michaeli 203536818*/
/*Yair Ivgi 308275601*/

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>
#include <string>

class Game {

private:
    //private members and functions
    int turn;
    int direction;
    Card current;
    Card choosen;
    int numOfPlayers;
    int numOfCards;
    vector <Player> players;
public:

    Game();
    //public members and functions
    void start();
    void initializeGame();
    void fillPlayers();
    void runingGame();
    void printTurn(Player &p)const ;
    void PlayerTurn(int i);
    void specialEffect(const Card& c);
    void endGame(vector <Player> players)const ;
    void checkBounds(int &turn)const;
    const int nextPlayer(int &turn)const;
};
#endif