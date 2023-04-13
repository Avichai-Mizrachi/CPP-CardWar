#include "game.hpp"
#include <string.h>
using namespace std;

Game ::Game(Player &p1, Player &p2) : player1(p1), player2(p2)
{

    // We create the deck.
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (i == 0)
            {
                Card card(j, "Club");
                this->deck.push_back(card);
            }
            else if (i == 1)
            {
                Card card(j, "Diamond");
                this->deck.push_back(card);
            }
            else if (i == 2)
            {
                Card card(j, "Spade");
                this->deck.push_back(card);
            }
            else if (i == 3)
            {
                Card card(j, "Heart");
                this->deck.push_back(card);
            }
        }
    }

    // We shuffle the deck using rand.
    unsigned int n = deck.size();
    for (unsigned int i = n - 1; i > 0; i--)
    {
        unsigned int j = static_cast<unsigned int>(rand()) % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // We deal the cards.
    bool whichOne = true;
    for (unsigned int i = 0; i <= 51; i++)
    {
        if (whichOne)
        {
            this->player1.addCard(deck.at(i));
            whichOne = false;
        }
        else
        {
            this->player2.addCard(deck.at(i));
            whichOne = true;
        }
    }
};

void Game ::playTurn()
{

    if (&player1 == &player2)
    {
        throw std::runtime_error("The players cannot be the same");
        return;
    }
    if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
    {
        throw std::runtime_error("At least one of the players with no cards");
        return;
    }

    this->numOfTurns++;
    Card card1 = this->player1.play();
    Card card2 = this->player2.play();
    this->deckSize = this->deckSize + 2;
    if (this->resetPrinter == true)
    {
        this->resetPrinter = "";
    }

    // In case player1 won
    if (card1.compareto(card2) == 1)
    {
        card1print = "";
        if (card1.getValue() == 1)
        {
            card1print = card1print + "Ace of " + card1.getType();
        }
        else if (card1.getValue() == 11)
        {
            card1print = card1print + "Jack of " + card1.getType();
        }
        else if (card1.getValue() == 12)
        {
            card1print = card1print + "Queen of " + card1.getType();
        }
        else if (card1.getValue() == 13)
        {
            card1print = card1print + "King of " + card1.getType();
        }
        else
        {
            card1print = card1print + to_string(card1.getValue()) + " of " + card1.getType();
        }

        card2print = "";
        if (card2.getValue() == 1)
        {
            card2print = card2print + "Ace of " + card2.getType();
        }
        else if (card2.getValue() == 11)
        {
            card2print = card2print + "Jack of " + card2.getType();
        }
        else if (card2.getValue() == 12)
        {
            card2print = card2print + "Queen of " + card2.getType();
        }
        else if (card2.getValue() == 13)
        {
            card2print = card2print + "King of " + card2.getType();
        }
        else
        {
            card2print = card2print + to_string(card2.getValue()) + " of " + card2.getType();
        }
        this->player1.states("win", this->deckSize);
        this->player1.states("lose", 0);

        this->lastTurn = this->lastTurn + this->player1.getName() + " played " + card1print + "\n" +
                         this->player2.getName() + " played " + card2print + "\n" +
                         "Congratulations!!" + this->player1.getName() + " has won!\n\n";
        this->resetPrinter = true;
        this->deckSize = 0;
        this->gameLog = this->gameLog + this->lastTurn + "\n\n\n";
    }
    // In case player2 won
    else if (card1.compareto(card2) == -1)
    {
        if (card1.getValue() == 1)
        {
            card1print = card1print + "Ace of " + card1.getType();
        }
        else if (card1.getValue() == 11)
        {
            card1print = card1print + "Jack of " + card1.getType();
        }
        else if (card1.getValue() == 12)
        {
            card1print = card1print + "Queen of " + card1.getType();
        }
        else if (card1.getValue() == 13)
        {
            card1print = card1print + "King of " + card1.getType();
        }
        else
        {
            card1print = card1print + to_string(card1.getValue()) + " of " + card1.getType();
        }

        card2print = "";
        if (card2.getValue() == 1)
        {
            card2print = card2print + "Ace of " + card2.getType();
        }
        else if (card2.getValue() == 11)
        {
            card2print = card2print + "Jack of " + card2.getType();
        }
        else if (card2.getValue() == 12)
        {
            card2print = card2print + "Queen of " + card2.getType();
        }
        else if (card2.getValue() == 13)
        {
            card2print = card2print + "King of " + card2.getType();
        }
        else
        {
            card2print = card2print + to_string(card2.getValue()) + " of " + card2.getType();
        }
        this->player1.states("lose", 0);
        this->player1.states("win", this->deckSize);

        this->lastTurn = this->lastTurn + this->player1.getName() + " played " + card1print + "\n" +
                         this->player2.getName() + " played " + card2print + "\n" +
                         "Congratulations!!" + this->player2.getName() + " has won!\n\n";
        this->resetPrinter = true;
        this->deckSize = 0;
        this->gameLog = this->gameLog + this->lastTurn + "\n\n\n";
    }
    else
    {
        // In case it's a draw
        if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
        {
            this->player1.states("draw", this->deckSize / 2);
            this->player2.states("draw", this->deckSize / 2);
            return;
        }

        // This is the covered card
        this->player1.play();
        this->player2.play();

        this->numOfTurns++;
        this->deckSize = this->deckSize + 2;

        // In case that at least one of the players doesn't have cards
        if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
        {
            this->player1.states("draw", this->deckSize / 2);
            this->player2.states("draw", this->deckSize / 2);
            return;
        }

        // In case both players have cards
        this->player1.states("draw", 0);
        this->player2.states("draw", 0);
        this->lastTurn = this->lastTurn + this->player1.getName() + " played " + card1print + "\n" +
                         this->player2.getName() + " played " + card2print + "\n" +
                         "It's a tie!";
        this->resetPrinter = false;
        this->playTurn();
    }
};

void Game ::printLastTurn()
{
    cout << this->lastTurn << endl
         << endl
         << endl;
};

void Game ::printStats()
{
    this->player1.printStates();
    this->player2.printStates();
};

void Game ::printLog()
{
    cout << this->gameLog << endl
         << endl;
};

void Game ::playAll()
{
    while (this->player1.stacksize() != 0 && this->player2.stacksize() != 0)
    {
        this->playTurn();
    }
};

void Game ::printWiner()
{
    if (this->numOfTurns < 26)
    {
        cout << "The game is not over yet!" << endl;
        cout << "There is another " << 26 - (this->numOfTurns) << " turns to play!" << endl;
        return;
    }

    if (this->player1.cardesTaken() > this->player2.cardesTaken())
    {
        cout << "The winner is: " << this->player1.getName() << endl;
    }
    else if (this->player1.cardesTaken() < this->player2.cardesTaken())
    {
        cout << "The winner is: " << this->player2.getName() << endl;
    }
    // In case of a draw
    else
    {
        throw std::runtime_error("Draw!");
    }
};