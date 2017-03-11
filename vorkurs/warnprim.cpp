#include <iostream>

bool istprim(int n)
{
  int i = 2;
  while (i < n)
  {
    if((n%i) == 0)
    {
      return false;
    }
    i = i + 1;
  }
  return true;
}

int main()
{
  int n;
  std::cout << "Gebe eine positive Zahl ein: " << std::endl;
  std::cin >> n;

  if (n <= 0)
  {
    std::cerr << "Die Zahl soll positiv sein!" << std::endl;
    return 1;
  }

  if (istprim(n))
  {
    std::cout << n << " ist prim." << std::endl;
  }
  else
  {
    std::cout << n << " ist nicht prim." << std::endl;
  }
}
