#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <chrono>

void initialize(std::map<char, int> & alphabet)
{
    for(char c = 'A'; c <='z'; ++c)
    {
        if(isalpha(c))
            alphabet[c] = 0;
        else continue;
    }
}

void count(std::map<char, int> & alphabet, std::string const & text)
{
    for( auto it = text.begin(); it!=text.end(); ++it)
    {
        if(isalpha(*it))
            alphabet[*it]++;
        else
            continue;
    }
}

void print(std::map<char, int> const & alphabet)
{
    for(auto it = alphabet.begin(); it!=alphabet.end(); ++it)
        std::cout << (*it).first << ": " << (*it).second << std::endl;
}

void print(std::multimap<int, char> const & alphabet)
{
    for(auto it = alphabet.begin(); it!=alphabet.end(); ++it)
        std::cout << (*it).first << ": " << (*it).second << std::endl;
}


int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::map<char, int> alphabet;
    initialize(alphabet);

    std::string text = "Hello this is a text for the alphabet.";
    count(alphabet, text);
    print(alphabet);

    std::multimap<int, char> numbers;
    for(auto it = alphabet.begin(); it!=alphabet.end(); ++it)
    {
        numbers.insert(std::pair<int, char>((*it).second,(*it).first));
    }
    print(numbers);

    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = stop-start;

    std::cout << diff.count() << std::endl;

    return 0;
}
