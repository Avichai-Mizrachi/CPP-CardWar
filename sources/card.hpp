#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{

    class Card
    {
    int myValue;
    string myType;

    public:
        Card(int value, string type);
        Card();
        int getValue();
        string getType();
        int compareto(Card second);
    };

}

#endif