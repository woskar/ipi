//Just some Template examples

#include <iostream>
#include <list>
#include <vector>

//Template for printing Container to the screen
template <typename Iterator>
void print_container(Iterator begin, Iterator end)
{
    std::cout << "{";
    if(begin != end)
    {
        std::cout << " " << *begin++;
        for(; begin != end; begin++)
        {
            std::cout << ", " << *begin;
        }
    }
    std::cout << "}" << std::endl;
}

//Check whether a Container is sorted
template <typename E, typename CMP>
bool check_sorted(std::vector<E> const & v, CMP less_than)
{
    for(int i=1; i<v.size(); i++)
    {
        if(less_than(v[i], v[i-1])) return false;
    }
    return true;
}

//Check whether sorted with Iterator
template <typename Iterator, typename CMP>
bool check_sorted(Iterator begin, Iterator end, CMP less_than)
{
    if(begin == end) return true;
    Iterator next = begin;
    ++next;
    for(; next!=end; ++begin, ++next)
    {
        if(less_than(*next, *begin)) return false;
    }
    return true;
}


int main()
{
    std::list<int> l = {4,2,3};
    std::vector<double> v = {1.1, 7.3, 10.2};
    std::vector<double> w = {4.2, 2.9, 1.0};

    print_container(l.begin(), l.end());
    std::cout << check_sorted(l.begin(), l.end(), [](int a, int b){return a < b;}) << std::endl;
    print_container(v.begin(), v.end());
    std::cout << check_sorted(v, [](double a, double b){return a < b;}) << std::endl;
    print_container(w.begin(), w.end());
    std::cout << check_sorted(w, [](double a, double b){return a < b;}) << std::endl;

}
