//Problem 5.1: Sort numbers into an array without std::sort()

#include <iostream>
#include <vector>


int main()
{
    std::vector<int> ordered_vector;
    std::cout << "Please enter positive integers for sorting,\n"
                 "break with negative number:\n"
                 "Confirm with enter\n";
    while(true){

        int input;
        std::cin >> input;

        if(input < 0)
        {
            std::cout << "Your vector was:\n";
            for(int i=0; i<ordered_vector.size(); ++i) std::cout << ordered_vector[i] << ' ';
            std::cout << std::endl;
            return 0;
        }
        else
        {
            int i = 0;
            for(; i < ordered_vector.size(); ++i)
            {
                if(input < ordered_vector[i])
                    break;
            }
            ordered_vector.insert(ordered_vector.begin() + i, input);
        }
    }
}
