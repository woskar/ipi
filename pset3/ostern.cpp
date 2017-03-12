//     ____                                _
//    / ___|  __ _  _   _  ___  ___   ___ | |__    ___
//   | |  _  / _` || | | |/ __|/ __| / __|| '_ \  / _ \
//   | |_| || (_| || |_| |\__ \\__ \| (__ | | | ||  __/
//    \____| \__,_| \__,_||___/|___/ \___||_| |_| \___|   _
//    / _ \  ___ | |_  ___  _ __  _ __  ___   __ _   ___ | |
//   | | | |/ __|| __|/ _ \| '__|| '__|/ _ \ / _` | / _ \| |
//   | |_| |\__ \| |_|  __/| |   | |  |  __/| (_| ||  __/| |
//    \___/ |___/ \__|\___||_|   |_|   \___| \__, | \___||_|
//

#include <string>
#include <cassert>
#include <iostream>

std::string easter(int y);

int main(){
  std::cout << easter(2017) << std::endl;

  assert(easter(1800)=="Ostern ist am 13. April.");
  assert(easter(4586)=="Ostern ist am 9. April.");
  assert(easter(1995)=="Ostern ist am 16. April.");
  assert(easter(2000)=="Ostern ist am 23. April.");
  assert(easter(3000)=="Ostern ist am 13. April.");

}

std::string easter(int y){
  int a = y % 19;
  int b = y % 4;
  int c = y % 7;
  int k = y / 100;
  int p = (8*k + 13)/25;
  int q = k/4;
  int m = (15 + k - p - q)%30;
  int d = (19*a + m) % 30;
  int n = (4 + k - q) % 7;
  int e = (2*b + 4*c + 6*d + n)%7;
  int x = 22 + d + e;

  int z = (x == 57) ? 50 : ((x == 56 and d ==28 and a > 10 ) ? 49 : x );

  if(z < 32){
    std::string r = std::to_string(z);
    return "Ostern ist am " + r + ". März.";
  } else {
    std::string r = std::to_string(z-31);
    return "Ostern ist am " + r + ". April.";
  }
}
