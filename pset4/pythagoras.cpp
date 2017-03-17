//Problem 4.2: Pythagorean triple

#include <iostream>
#include <cmath>

bool is_square(int n);
void pythagorean_triple(int bmax);

int main(){
  pythagorean_triple(400);
}

//a) test whether n is a square number
bool is_square(int n){
  //b) use fact that if n is square number, n%4 returns only 1 or 0
  if(n % 4 == 1 || n % 4 == 0){
    return ((std::sqrt(n) - floor(std::sqrt(n))) == 0);
  }
  else return false;
}

void pythagorean_triple(int bmax){
  int i = 1;
  for(int a = 1; a < bmax; a++){
    for(int b = 1; b < a; b ++){
      int c = pow(a,2) + pow(b,2);
      if(is_square(c)){
        c = std::sqrt(c);
        std::cout << "triple \t"<< i << " (" << b << ", " << a << ", " << c << ")" << std::endl;
        i++;
      }
    }
  }
}
