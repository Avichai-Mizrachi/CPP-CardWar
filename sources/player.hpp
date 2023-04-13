#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
#include <vector>

using namespace std;
using namespace ariel;

class Player
{
string name;
int stackSize;
int score = 0;
int wins = 0;
int loses = 0;
int draws = 0;
vector<Card> cards;

public:
    Player(string);
    Player();
    Card play();
    int stacksize();
    int cardesTaken();
    void addCard(Card);
    void states(string,int);
    void printStates();
    string getName();
};

#endif