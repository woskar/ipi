//Problem 5.2: Perfect shuffle
//How many times do you have to (perfect-) shuffle a deck to get to status quo?

#include <vector>
#include <iostream>
#include <cassert>

//Functions to implement:
std::vector<int> init_deck();   //creates array with 52 ascending numbers
bool check_deck(std::vector<int> cards);    //evaluates to true if array in correct order
std::vector<int> shuffle(std::vector<int> cards, bool out); //shuffles 'out' with true and 'in' with false
void print_deck(std::vector<int> deck); //print the deck to the screen
int shuffle_time(bool out); //check how often cards have to be shuffled until deck is in correct order

int main(){
    std::vector<int> deck = init_deck();
    assert(check_deck(deck));
    //print_deck(deck);
    //print_deck(shuffle(deck, true));
    std::cout << "Perfect-out requires " << shuffle_time(true) << " shuffles for reset.\n";
    std::cout << "Perfect-in requires " << shuffle_time(false) << " shuffles for reset.\n";

}

//initialize vector with integers 0 ... 51
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

//return true if integers in vector are in order 0 ... 51
bool check_deck(std::vector<int> cards){
    int i=0;
    while(i<52)
    {
        if(cards[i]==i) ++i;
        else return false;
    }
    return true;
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

int shuffle_time(bool out){
    int number = 0;
    std::vector<int> cards = init_deck();
    while(true)
    {
        cards = shuffle(cards, true);
        ++number;
        if (check_deck(cards))
            {
                return number;
            }
    }
}
