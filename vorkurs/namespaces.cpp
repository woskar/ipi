#include <iostream>

namespace eins
{
  int x = 5;
}

namespace zwei
{
  double x = 2.718281;
}

int main()
{
  std::cout << eins::x << std::endl;
  std::cout << zwei::x << std::endl;
}
