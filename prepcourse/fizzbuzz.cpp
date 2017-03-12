#include <iostream>

int main(){
  int i = 0;

  while(i<100)
  {
    if(i%3 == 0)
    {
      std::cout << "Fizz";
    }
    if(i%5 == 0)
    {
      std::cout << "Buzz";
    }
    if(i%3 != 0 and i%5 != 0)
    {
      std::cout << i;
    }
    std::cout << std::endl;
    i ++;
  }
}
