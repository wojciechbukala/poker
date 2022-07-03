#include "deck.hh"
#include "hand.hh"


using namespace std;


int main()
{
    cout << "----------------" << endl;
    cout << "|   Poker 24   |" << endl;
    cout << "| Texas Holdem |" << endl;
    cout << "----------------" << endl;
    Deck D(true);
    Hand H1;
    D.view(std::cout);
    H1.take_one_card();
    H1.take_one_card();
    H1.view(std::cout);
}