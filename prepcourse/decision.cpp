#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{

  std::string array[3];
  int i;

  std::cout << "Give me three things you want me to decide on:" << std::endl;
  std::cout << "The first, please: " << std::endl;
  std::cin >> array[0];

  std::cout << "The second, please: " << std::endl;
  std::cin >> array[1];

  std::cout << "The third, please: " << std::endl;
  std::cin >> array[2];

  srand(time(NULL));

  i = rand()%3;

  std::cout << "The magic happened." << std::endl << "You shall choose " << array[i] << "." << std::endl;

}
