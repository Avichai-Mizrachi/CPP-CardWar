#include "card.hpp"
using namespace ariel;


Card ::Card(int value, string type){
    this->myValue = value;
    this->myType = type;
};

Card :: Card(){
    
    this->myValue = 0;
    this->myType = "";
};

int Card::getValue(){
    return this->myValue;
}

string Card::getType(){
    return this->myType;
}

int Card ::compareto(Card second)
{
    int secondCard = second.myValue;
    int firstCard = this->myValue;
    if(firstCard == 1 && secondCard != 2 && secondCard !=1){
        return 1;
    }
    if(secondCard == 1 && firstCard != 2 && secondCard !=2){
        return -1;
    }
    if(firstCard > secondCard){
        return 1;
    }
    else if (secondCard<firstCard)
    {
        return -1;
    }
    else{
        return 0;
    }
};