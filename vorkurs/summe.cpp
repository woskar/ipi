#include <iostream>
#include <cmath>

int main()
{
  int a;
  int b;
  std::cout << "Erste Zahl eingeben: ";
  std::cin >> a;
  std::cout << "Zweite Zahl eingeben: ";
  std::cin >> b;
  std::cout << "Die Summe beträgt " << a + b << std::endl;
  std::cout << "Die Differenz ist " << a - b << std::endl;
  std::cout << "Das Produkt ist " << a * b << std::endl;
  std::cout << "Der Quotient ist " << a / b << std::endl;
  std::cout << "a modulo b ergibt " << a % b << std::endl;
}
