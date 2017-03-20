//Just a quick test for iterators:

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = {1,2,3,4,5};

    //for(int k=0; k<5; ++k) v.push_back(k);

    //for(std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    for(auto iter = v.begin(); iter != v.end(); ++iter)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;

    for(auto & element : v)
    {
        std::cout << element << std::endl;
    }

    std::string test = "String";
    std::random_shuffle(test.begin()+1, test.end()-1);
    std::cout << test << std::endl;
}
