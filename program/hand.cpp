#include "hand.hh"

Hand::Hand()
{
    for(int i=0; i<GiveSize(); ++i)
    {
        _hand[i] = std::pair<int,std::string>{1,"none"};
    }
}

void Hand::take_one_card()
{
    if(!_deck.empty())
    {
        _hand.push_back(_deck.back());
        std::cout << _hand.front().first << std::endl;
        _deck.pop_back();
        std::cout << _deck.back().first << std::endl;
    }
}

void Hand::view(std::ostream& oStrm)
{
    oStrm << *this << std::endl;
}

int Hand::GiveSize()
{
    return _hand.size();
}

std::ostream& operator << (std::ostream &Strm, Hand &H)
{
    for(int i=0; i<H.GiveSize(); ++i)
    {
        //std::cout << H.GiveSize() << std::endl;
        Strm << H[i].first << H[i].second << std::endl;
    }
    return Strm;
}

