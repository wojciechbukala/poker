#ifndef DECK_HH
#define DECK_HH

#include <iostream>
#include <vector>
#include <cstring>

class Deck
{
    protected:
        std::vector<int> quantity {2,3,4,5,6,7,8,9,10,11,12,13, 14};
        std::vector<std::string> color {"Hearts", "Diamonds", "Clubs", "Spades"};
        std::vector<std::pair<int,std::string>> _deck = std::vector<std::pair<int,std::string>>(52);
        void fill_in();
        
    public:
        Deck(); 
        Deck(bool rand);
        virtual int GiveSize();
        std::pair<int,std::string>& operator[] (int iter);
        void shuffle ();
        virtual void view(std::ostream &oStrm);

};

// template to be made in future
std::ostream& operator << (std::ostream &Strm, Deck &D);

#endif