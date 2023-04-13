#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"

using namespace std;
using namespace ariel;

class Game
{
    Player& player1;
    Player& player2;
    vector<Card> deck;
    int numOfTurns = 0;
    int deckSize;
    string gameLog;
    string lastTurn;
    bool resetPrinter = true;
    string type;

public:
    Game(Player& player1, Player& player2);
    void playTurn();
    void printLastTurn();
    void printStats();
    void printLog();
    void printWiner();
    void playAll();
    void shuffleDeck();
};

#endif