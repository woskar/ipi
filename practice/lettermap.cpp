#include <map>
#include <iostream>

int main()
{
    std::string text = "Hallihallo";
    std::string letters = "HhllllaaioABC";

    // create maps
    std::map<char, int> brief;
    std::map<char, int> buchstaben;

    // initialize with alphabet, all values to zero
    for(char c = 'A'; c <= 'z'; ++c)
    {
        brief[c] = 0;
        buchstaben[c] = 0;
    }

    // fill maps with letters
    for(int i = 0; i<text.size(); ++i)
        brief[text[i]] += 1;

    for(int i = 0; i<letters.size(); ++i)
        buchstaben[letters[i]] += 1;

    // check if they're the same
    for(char c = 'A'; c <= 'z'; ++c)
    {
        if(brief[c] > buchstaben[c])
            std::cout << "Not enough letters" << std::endl;
    }
    std::cout << "It will work! There are enough letters :D" << std::endl;

    return 0;
}
