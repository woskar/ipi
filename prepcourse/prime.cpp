#include <iostream>

int main()
{
  int n;
  std::cout << "Give me a positive integer: " << std::endl;
  std::cin >> n;

  if (n <= 0)
  {
    std::cerr << "The number has to be positive." << std::endl;
    return 1; // Return 1 means there has been an error
  }

  if (n == 1)
  {
    std::cout << "Your number was one." << std::endl;
    return 1;
  }

  if (n == 2)
  {
    std::cout << "Your number was two, and this is a prime number" << std::endl;
    return 1;
  }

  int i = 2;
  while (i < n)
  {
    if (n%i != 0)
    {
      i ++;

      if (i==n)
      {
        std::cout << "Your number " << n << " is a prime number!" << std::endl;
        break;
      }
    }

    else
    {
      std::cout << i << " divides n." << std::endl;
      break;
    }
  }
}
