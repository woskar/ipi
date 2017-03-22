//Determine runtime of insertion sort empirically

#include <chrono>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

double std_sort_time(int n);
double insertion_sort_best_time(int n);
double insertion_sort_worst_time(int n);
double insertion_sort_typical_time(int n);
void insertion_sort(std::vector<int> & v);

int main ()
{
    std::cout << "Runtime standard sort algorithm with n=100000: " << std_sort_time(100000) << " seconds\n"; //0.17373 seconds
    std::cout << "Runtime insertion sort with n=100000 best: " << insertion_sort_best_time(100000) << " seconds\n"; // 0.0332733 seconds
    std::cout << "Runtime insertion sort with n=100000 worst: " << insertion_sort_worst_time(100000) << " seconds\n"; // 0.0307265 secs  and  n=100000000 takes 1.82884 seconds
    std::cout << "Runtime insertion sort with n=100000 typical: " << insertion_sort_typical_time(100000) << " seconds\n";
    return 0;
}


double std_sort_time(int n)
{
    // fill array with random values
    std::vector<int> v(n);
    for(int k=0; k<n; ++k)
    {
        v[k] = k;
    }
    std::random_shuffle(v.begin(), v.end());

    //Determine start and end time
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(v.begin(), v.end());
    auto stop = std::chrono::high_resolution_clock::now();

    //Calculate the passed time
    std::chrono::duration<double> diff = stop - start;
    return diff.count();
}

double insertion_sort_best_time(int n)
{
    // fill array with already sorted values
    std::vector<int> v(n);
    for(int k=0; k<n; ++k)
    {
        v[k] = k;
    }

    //Determine start and end time
    auto start = std::chrono::high_resolution_clock::now();
    insertion_sort(v);
    auto stop = std::chrono::high_resolution_clock::now();

    //Calculate the passed time
    std::chrono::duration<double> diff = stop - start;
    return diff.count();
}


double insertion_sort_worst_time(int n)
{
    // fill array with reverse sorted values
    std::vector<int> v(n);
    for(int k=n; k>0; --k)
    {
        v[k] = k;
    }

    //Determine start and end time
    auto start = std::chrono::high_resolution_clock::now();
    insertion_sort(v);
    auto stop = std::chrono::high_resolution_clock::now();

    //Calculate the passed time
    std::chrono::duration<double> diff = stop - start;
    return diff.count();
}


double insertion_sort_typical_time(int n)
{
    // fill array with random values
    std::vector<int> v(n);
    for(int k=0; k<n; ++k)
    {
        v[k] = k;
    }
    std::random_shuffle(v.begin(), v.end());

    //Determine start and end time
    auto start = std::chrono::high_resolution_clock::now();
    insertion_sort(v);
    auto stop = std::chrono::high_resolution_clock::now();

    //Calculate the passed time
    std::chrono::duration<double> diff = stop - start;
    return diff.count();
}

void insertion_sort(std::vector<int> & v)
{
    for(int k=1; k<v.size(); ++k)
    {
        int current = v[k]; // element to be inserted
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
