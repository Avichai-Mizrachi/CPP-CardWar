#include "player.hpp"
#include "card.hpp"

Player ::Player(string name)
{
    this->name = name;
    this->stackSize = 0;
};

Player ::Player()
{
    this->name = "";
    this->stackSize = 0;
};

int Player::stacksize()
{
    return this->stackSize;
};

int Player::cardesTaken()
{
    return this->score;
};

void Player::addCard(Card extra)
{
    this->cards.push_back(extra);
    this->stackSize++;
};

Card Player ::play()
{
    if (this->stackSize == 0)
    {
        return Card();
    }
    Card temp = cards[cards.size()];
    this->cards.pop_back();
    this->stackSize--;
    return temp;
};

void Player ::states(string res, int taken)
{
    if (res == "lose")
    {
        this->loses++;
    }
    else if (res == "win")
    {
        this->wins++;
        this->score = this->score + taken;
    }
    else if (res == "draw")
    {
        this->draws++;
        this->score = this->score + taken;
    }
};

void Player ::printStates()
{
    cout << this->name << " won " << this->score << " cards!" << endl;
    cout << "He have " << this->wins << " wins, " << this->draws << " draws and " << this->loses << " loses :()" << endl;
    cout << "The wins precentage is: " << wins * 100 / 26 << "%" << endl;
    cout << "The draws precentage is: " << draws * 100 / 26 << "%" << endl;
};

string Player ::getName() { return this->name; };