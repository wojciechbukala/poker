#include "deck.hh"
#include <ctime>

Deck::Deck() 
{
   fill_in();
}



Deck::Deck(bool rand)
{
    fill_in();
    if(rand == true) // if parametr rand is true, then lets mix up our deck!
    {
        this->shuffle();
    }
}

void Deck::fill_in()
{
    int _size = _deck.size();
    for(int i=0; i<_size/13; ++i)
    {
        for(int j=0; j<_size/4; ++j)
        {
            std::pair<int,std::string> temp = std::pair<int,std::string> (quantity[j],color[i]);
            _deck[j+13*i] = temp;
        }
    }
}

int Deck::GiveSize()
{
    return _deck.size();
}

std::pair<int,std::string>& Deck::operator[] (int iter)
{
    return _deck[iter];
}

void Deck::view(std::ostream &oStrm)
{
    oStrm << *this << std::endl;
}

void Deck::shuffle ()
{
    Deck shuffled_deck;
    int _size = _deck.size();
    int num_of_karts = _deck.size();
    for(int i = 0; i<_size; ++i)
    {
        srand(time(NULL));
        int rand_num = (std::rand() % num_of_karts);
        shuffled_deck[i] = _deck[rand_num];
        _deck.erase(_deck.begin()+rand_num);
        num_of_karts--;
    }
    *this = shuffled_deck;
} 

std::ostream& operator << (std::ostream &Strm, Deck &D)
{
    for(int i=0; i<D.GiveSize(); ++i)
    {
        Strm << D[i].first << D[i].second << std::endl;
    }
    return Strm;
}