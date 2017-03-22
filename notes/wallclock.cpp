// Measure wall clock time:

#include <chrono>
#include <iostream>

int main ()
{


    auto start = std::chrono::high_resolution_clock::now(); // get start time

    //code to be executed and measured:
    int a = 1;
    int b = 2;
    int c;
    c = a + b;

    auto stop = std::chrono::high_resolution_clock::now(); // get stop time
    std::chrono::duration<double> diff = stop - start;
    std::cout << "Runtime: " << diff.count() << " seconds\n";
    return 0;
}
