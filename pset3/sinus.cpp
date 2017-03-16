#include <cmath>
#include <iostream>

double taylor_sin(double x);
double bogen(double x);

int main(){
  //std::cout << std::sin(M_PI) << std::endl;
  double test[18] = {1,2,3,4,5,6,7,8,9,10,20,45,90,135,180,225,270,315};
  std::cout << "Test wird durchgeführt: Grad, Taylor, Sinus, Fehler" << std::endl;
  for (int i=0; i < 18; i++){
    double a = taylor_sin(bogen(test[i]));
    double b = std::sin(bogen(test[i]));
    std::cout << test[i] << "   \t" << a << "   \t" << b << "       \t" << (b - a) << std::endl;
  }
  //std::abs();
}

double bogen(double x){
  return (x * M_PI) / 180;
}

double taylor_sin(double x){
  return (x - ((x*x*x)/6));
}
