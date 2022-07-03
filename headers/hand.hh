#ifndef HAND_HH
#define HAND_HH
#include "deck.hh"

class Hand : public Deck
{
    std::vector<std::pair<int,std::string>> _hand; //= std::vector<std::pair<int,std::string>>(1);


    public:
        Hand();
        void take_one_card();
        void view(std::ostream &oStrm) override;
        int GiveSize() override;
        std::pair<int,std::string>& operator[] (int iter) {return _deck[iter];}
};

// template to be made in future
std::ostream& operator << (std::ostream &Strm, Hand &H);

#endif