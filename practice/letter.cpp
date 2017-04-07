#include <iostream>
//#include <algorithm>
#include <string>

bool enough_letters(std::string text, std::string letters)
{
    std::sort(text.begin(), text.end());
    std::sort(letters.begin(), letters.end());

    std::cout << text << std::endl;
    std::cout << letters << std::endl;

    int i = 0;
    int j = 0;
    char L = text[0];

    while(i < text.size())
    {
        if(text[i] == ' ')
        {
            std::cout <<"space " << text[i] << std::endl;
            i++;
            std::cout << "i: " << i << " j:" << j << std::endl;
        }
        else if(text[i] == letters[j])
        {
            L = text[i];
            i++;
            j++;
        }
        else
        {
            if(letters[j] < L)
            {
                j++;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::string text = "Hallihallo";
    std::string letters = "Hhllllaaio";
    std::cout << enough_letters(text, letters) << std::endl;
    return 0;
}
