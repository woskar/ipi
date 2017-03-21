//Generic implementation of insertion sort

#include <iostream>
#include <vector>


template <typename ElementType, typename LessThanFunctor>
bool check_sorted(std::vector<ElementType> const & v, LessThanFunctor less_than)
{
    for(int i=1; i<v.size(); i++)
    {
        if(less_than(v[i], v[i-1])) return false;
    }
    return true;
}


template <typename Iterator, typename LessThanFunctor>
bool check_sorted(Iterator begin, Iterator end, LessThanFunctor less_than)
{
    for(auto iter1 = begin, iter2 = begin + 1; iter2 != end; ++iter1, ++iter2)
    {
        if(less_than(*iter1, *iter2)) return false;
    }
    return true;
}

//implement insertion sort
template <typename ElementType, typename LessThanFunctor>
void insertion_sort(std::vector<ElementType> & v, LessThanFunctor less_than)
{
    for(int i = 1; i<v.size(); ++i)
    {
        int j = i;
        auto current = v[i];
        while(j > 0)
        {
            if(less_than(v[j - 1],current)) break;
            else
            {
                v[j] = v[j - 1];
                --j;
            }
            v[j] = current;
        }
    }
}

template <typename Iterator, typename LessThanFunctor>
void insertion_sort(Iterator begin, Iterator end, LessThanFunctor less_than)
{
    for(auto iter1 = begin; iter1 != end; ++iter1)
    {
        auto current = *iter1;
        auto iter2 = iter1;
        while(iter2 != begin)
        {
            if(less_than(*(iter2-1), current)) break;
            else
            {
                *iter2 = *(iter2 -1);
                --iter2;
            }
            *iter2 = current;
        }
    }
}

int main()
{
    std::vector<int> v = {1,4,3,5,6,7,3};
    std::cout << check_sorted(v, [](int a, int b){return a > b;}) << std::endl;
    std::cout << check_sorted(v.begin(), v.end(), [](int a, int b){return a > b;}) << std::endl;
    insertion_sort(v, [](int a, int b){return a > b;});
    std::cout << check_sorted(v, [](int a, int b){return a > b;}) << std::endl;
    std::random_shuffle(v.begin(), v.end());
    std::cout << check_sorted(v, [](int a, int b){return a > b;}) << std::endl;
    insertion_sort(v.begin(), v.end(), [](int a, int b){return a > b;}); 
    std::cout << check_sorted(v, [](int a, int b){return a > b;}) << std::endl;
}

/*
// non-generic implementation of insertion sort
// pass-by-reference, weil v ver ̈andert werden soll

void insertion_sort(std::vector<double> & v)
{
    for(int k=1; k<v.size(); ++k)
    {
        double current = v[k]; // element to be inserted
        int j = k;             // position of gap
        while(j > 0)
        {
            if(current < v[j-1])
            {
                v[j] = v[j-1]; // gap one position to left
            }
            else
            {
                break; // gap at right spot
            }
            --j;
        }
        v[j] = current; // insert element into gap
    }
}
*/
