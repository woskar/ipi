//Problem 5.3: Mix words

#include <iostream>
#include <vector>
#include <algorithm>
#include "text.hpp"

//Functions to be implemented:
std::vector<std::string> split_words(std::string s);
std::string mix(std::string s);
std::string split_and_mix(std::string s);
void print_vector(std::vector<std::string> const & strings);

//Running main:
int main()
{
    std::cout << "Ursprünglicher Text in str1\n";
    std::cout << str1 << std::endl << std::endl;
    std::cout << "Ergebnis von split_and mix(str1)\n";
    std::cout << split_and_mix(str1) << std::endl << std::endl;

    std::cout << "Ursprünglicher Text in str2\n";
    std::cout << str2 << std::endl << std::endl;
    std::cout << "Ergebnis von split_and mix(str2)\n";
    std::cout << split_and_mix(str2) << std::endl << std::endl;

    std::cout << "Ursprünglicher Text in str3\n";
    std::cout << str3 << std::endl << std::endl;
    std::cout << "Ergebnis von split_and mix(str3)\n";
    std::cout << split_and_mix(str3) << std::endl << std::endl;

    std::cout << "Ursprünglicher Text in str4\n";
    std::cout << str4 << std::endl << std::endl;
    std::cout << "Ergebnis von split_and mix(str4)\n";
    std::cout << split_and_mix(str4) << std::endl << std::endl;

    std::cout << "Ursprünglicher Text in str5\n";
    std::cout << str5 << std::endl << std::endl;
    std::cout << "Ergebnis von split_and mix(str5)\n";
    std::cout << split_and_mix(str5) << std::endl << std::endl;
}

//split string s at spaces
std::vector<std::string> split_words(std::string s)
{
    //result will store the strings
    std::vector<std::string> result;

    int i=0;
    std::string temp;
    while(i < s.size())
    {
        while(s[i] != ' ' && s[i] != '\0')
        {
            temp += s[i];
            ++i;
        }
        result.push_back(temp);
        ++i;
        temp="";
    }
    return result;
}

//function for printing a vector
void print_vector(std::vector<std::string> const & strings)
{
    for(int i=0, n=strings.size(); i<n; ++i) std::cout << strings[i] << std::endl;
}

//randomly mix the inner characters of string s
std::string mix(std::string s)
{
    //Determine position of first and last character
    int l = s.size();
    int first=0;
    int last=0;

    for(int i=0; i<l; ++i)
    {
        if(std::isalpha(s[i]))
        {
            first = i;
            break;
        }
    }

    for(int i=l; i>0; --i)
    {
        if(std::isalpha(s[i]))
        {
            last = i;
            break;
        }
    }
    std::string w = s.substr(first+1, (last-1-first));
    std::random_shuffle(w.begin(), w.end());
    return s[first] + w + s[last];
}

std::string split_and_mix(std::string s){
    std::string result;
    std::vector<std::string> vector = split_words(s);

    for(int i=0, n=vector.size(); i<n; i++)
    {
        result += mix(vector[i]);
        result += ' ';
    }
    return result;
}
