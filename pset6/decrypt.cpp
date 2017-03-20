//Problem 6.3: Read text from file and decipher

#include <fstream>
#include <vector>
#include <iostream>
#include <map>
#include <cctype>

int main()
{
    //read the document
    std::ifstream infile("encrypted_text.txt");
    std::string text;
    std::string line;
    while(infile)
    {
        std::getline(infile, line);
        text += line + "\n";
    }

    //create Map and initialize with a...z, all values 0
    std::map<char, int> counts;
    std::vector<char> mykeys(26);
    for(int i=97; i < 97+26; ++i) mykeys[i-97] = i;
    for (auto c : mykeys)
        counts.emplace(c, 0);

    //print keys just to verify
    //for(char c : mykeys)
    //    std::cout << c << std::endl;

    //iterate over map and count number of appearance of each letter
    for(int i=0, n=text.size(); i<n; i++)
    {
        if(std::isalpha(text[i])) counts[tolower(text[i])]++;
    }

    //print map counts
    for(auto iter = counts.begin(); iter != counts.end(); ++iter)
    {
        std::cout << (*iter).first << " ";
        std::cout << (*iter).second << std::endl;
    }

    std::map<int, char> sorted;

    for(auto iter = counts.begin(); iter!= counts.end(); ++iter)
    {
        sorted.insert(std::pair<int,char> ((*iter).second, (*iter).first));
    }

    //print map sorted
    for(auto iter = sorted.begin(); iter != sorted.end(); ++iter)
    {
        std::cout << (*iter).first << " ";
        std::cout << (*iter).second << std::endl;
    }

    //Sorting of letters in ascending frequency in english text:
    std::string letterstring = "zjqxkvbygpwfmculdrhsnioate";
    std::vector<char> letters;
    for(int i=0, n=letterstring.size(); i<n; i++)
    {
        letters.push_back(letterstring[i]);
    }

    //keys: encoded, values: decoded
    std::map<char, char> decrypt;

    auto iter_1 = sorted.begin();
    auto iter_2 = letters.begin();

    for(; iter_1!=sorted.end() && iter_2!=letters.end(); ++iter_1, ++iter_2)
    {
        decrypt.insert(std::pair<char,char> ((*iter_1).second, *iter_2));
    }

    //std::cout << decrypt.at('c') << std::endl;

    for(int i=0, n=text.size(); i<n; i++)
    {
        if(std::isalpha(text[i]))
        {
            //if capital letter
            if(text[i]>=65 && text[i]<=65+26)
            {
                text[i] = (toupper(decrypt.at(tolower(text[i]))));
            }
            else
            {
                text[i] = decrypt.at(text[i]);
            }
        }
    }

    std::ofstream outfile("decrypted_text.txt");
    outfile << text;

}
