#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> & v)
{
    for(int i = 1; i < v.size(); ++i)
    {
        if(v[i] >= v[i-1])
            continue;
        else
        {
            int j = i;
            while(v[j-1] > v[j] && j>0)
            {
                int temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
                j--;
            }
        }
    }
}

template <typename T>
void generic_insertion_sort(std::vector<T> & vec)
{
    for(int i = 1; i<vec.size(); ++i)
    {
        T current = vec[i];
        int j = i;
        while(j > 0)
        {
            if (vec[j-1] <= current)
                break;
            vec[j] = vec[j-1];
            --j;
        }
        vec[j] = current;
    }
}

void print(std::vector<int> const & vec)
{
    for(int i = 0; i<vec.size(); ++i)
        std::cout << vec[i] << " " << std::flush;
    std::cout << std::endl;
}

template <typename T>
void gen_print(T const & t)
{
    std::cout << "{ " << std::flush;
    auto iter = t.begin();
    for(; iter != t.end()-1; ++iter)
        std::cout << (*iter) << ", " << std::flush;
    std::cout << (*iter) << "}" << std::endl;
}

template <typename T>
bool test_sort(T const & t)
{
    auto first = t.begin();
    auto second = t.begin()+1;
    for(; second!=t.end(); ++first, ++second)
    {
        if(*first > *second)
            return false;
    }
    return true;
}

template <typename Iterator, typename Functor>
bool sorted(Iterator begin, Iterator end, Functor lessThan)
{
    if(begin == end)
        return true;
    Iterator next = begin;
    ++next;
    for(; next != end; ++begin, ++next)
    {
        if(lessThan(*next, *begin))
            return false;
    }
    return true;
}

template <typename Iterator>
void print_container(Iterator begin, Iterator end)
{
    std::cout << "{ ";
    if (begin != end)
    {
        std::cout << *begin;
        ++begin;
        for(; begin != end; ++begin)
        {
            std::cout << ", " << *begin;
        }
    }
    std::cout << "}" << std::endl;
}

int main()
{
    std::vector<int> vec = {1,4,7,3,4,2,4};
    print(vec);
    gen_print(vec);
    insertion_sort(vec);
    gen_print(vec);
    std::random_shuffle(vec.begin(), vec.end());
    gen_print(vec);
    generic_insertion_sort(vec);
    gen_print(vec);
    std::cout << std::endl;

    std::vector<double> dvec = {1.0,4.3,7.6,3.2,4.1,2.7,4.2};
    gen_print(dvec);
    std::cout << test_sort(dvec) << std::endl;
    std::cout << sorted(dvec.begin(), dvec.end(),
                 [](double a, double b){return a < b;}) << std::endl;
    generic_insertion_sort(dvec);
    gen_print(dvec);
    std::cout << test_sort(dvec) << std::endl;
    print_container(dvec.begin(), dvec.end());
    std::cout << sorted(dvec.begin(), dvec.end(),
                 [](double a, double b){return a < b;}) << std::endl;


    return 0;
}
