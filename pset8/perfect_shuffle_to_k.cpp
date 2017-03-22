// Problem 8.2: Perfect Shuffle to position k using bitwise operators

#include <iostream>
#include <cassert>
#include <vector>


std::vector<int> init_deck();
void print_deck(std::vector<int> const & deck);
std::vector<int> shuffle(std::vector<int> cards, bool out);
std::vector<int> shuffle_top_to(std::vector<int> deck, uint8_t k);


int main()
{
    std::vector<int> deck = init_deck();
    print_deck(deck);
    std::vector<int> shuffled = shuffle_top_to(deck, 6);
    print_deck(shuffled);
    return 0;
}

std::vector<int> shuffle_top_to(std::vector<int> deck, uint8_t k)
{
    for(int i=0; i<8; ++i)
    {
        //print_deck(deck);
        if(k & ( 128 >> i ))
        {
            deck = shuffle(deck, false);
            //print_deck(deck);
        }
        else
        {
            deck = shuffle(deck, true);
            //print_deck(deck);
        }
    }
    return deck;
}


//Methods from pset 5:
//initialize vector (deck of cards) with integers 0 ... 51
std::vector<int> init_deck()
{
    std::vector<int> deck;
    for(int i = 0; i < 52; ++i)
    {
        deck.push_back(i);
    }
    return deck;
}

//function for printing a given deck
void print_deck(std::vector<int> const & deck)
{
    for(int i=0, n=deck.size(); i<n; ++i) std::cout << deck[i] << ' ';
    std::cout << std::endl;
}

//shuffle the cards perfect-out or perfect-in
std::vector<int> shuffle(std::vector<int> cards, bool out)
{
    std::vector<int> shuffle;
    int deck_size = cards.size();
    int half_deck_size = deck_size/2;
    for(int i = 0; i<half_deck_size; ++i)
    {
        if(out) //Perfect-In-Shuffle
        {
            shuffle.push_back(cards[i]);
            shuffle.push_back(cards[half_deck_size + i]);
        }
        else //Perfect-Out-Shuffle
        {
            shuffle.push_back(cards[half_deck_size + i]);
            shuffle.push_back(cards[i]);
        }
    }
    return shuffle;
}
