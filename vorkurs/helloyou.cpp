#include <iostream>
#include <string>

int main()
{
  std::cout << "Bitte gebe deinen Vor- und Nachnamen durch ein Leerzeichen getrennt ein:" << std::endl;

  std::string hallo;
  hallo = "Hallo ";

  std::string vorname;
  std::cin >> vorname;

  std::string nachname;
  std::cin >> nachname;

  std::cout << hallo << vorname << " " << nachname << std::endl;
}
