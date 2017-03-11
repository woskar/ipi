#include <iostream>


bool isprime(int n);


int main()
{
  std::cout << "Please insert a number: " << std::endl;
  int n;
  std::cin >> n;

  if (isprime(n))
  {
    std::cout <<  n << " is prime."<< std::endl;
  }
  else
  {
    std::cout << n << " is not a prime number." << std::endl;
  }
}


bool isprime(int n)
{
  int i = 2;
  while (i < n)
  {
    if ((n%i) == 0)
    {
      return false;
    }
    i ++;
  }
  return true;
}
