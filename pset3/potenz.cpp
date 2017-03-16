//       _     _____   _  _       ____         _
//      / \   |___ /  | || |  _  |  _ \  ___  | |_  ___  _ __   ____
//     / _ \    |_ \  | || |_(_) | |_) |/ _ \ | __|/ _ \| '_ \ |_  /
//    / ___ \  ___) |_|__   _|_  |  __/| (_) || |_|  __/| | | | / /
//   /_/   \_\|____/(_)  |_| (_) |_|    \___/  \__|\___||_| |_|/___|
//
#include <iostream>
#include <cmath>

double power(double x, int n);
double sq(double x);

int main(){
  std::cout << "x, n, std::pow(), power" << std::endl;
  double x[10] = {1,2,3,4,5,6,7,8,9,10};
  int n[10]    = {1,2,3,4,5,6,7,8,9,10};
  for (int i = 0; i < 10; i++){
        std::cout << x[i] << "\t" << n[i] << "\t" << std::pow(x[i], n[i]) << "\t" << power(x[i], n[i]) << std::endl;
  }
}

double power(double x, int n){
  return (n == 1) ? x : ((fmod(x,2) == 0.0) ? sq(power(x, n/2)) : x * power(x, n-1));
}

double sq(double x){
  return x*x;
}

//Gute Idee, weil für x hoch 8
//ohne Hilfsfunktion: 11 Multiplikationen notwendig
//mit Hilfsfunktion: 3 Mulitplikationen notwendig
