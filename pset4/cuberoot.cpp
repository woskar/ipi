//       _    _  _      _       ____        _                               _
//      / \  | || |    / | _   / ___|_   _ | |__    ___  _ __  ___    ___  | |_
//     / _ \ | || |_   | |(_) | |   | | | || '_ \  / _ \| '__|/ _ \  / _ \ | __|
//    / ___ \|__   _|_ | | _  | |___| |_| || |_) ||  __/| |  | (_) || (_) || |_
//   /_/   \_\  |_| (_)|_|(_)  \____|\__,_||_.__/  \___||_|   \___/  \___/  \__|
//

//Exercise 4:

//a) Iteration rule:
// x(t+1) = (2*x(t)+(y/x(t)**2))/3

//break condition:
//()(x*x*x) - y) <= epsilon

#include <cmath>
#include <iostream>
#include <cassert>

double cbrt(double y);

int main(){

  double delta = pow(10, -15);
  double test[4] = {8, 42, 373, 2017};

  std::cout << "Test started: Number, pow, cbrt" << std::endl;
  for (int i = 0, n = sizeof(test); i < n; i++){
    std::cout << test[i] << "\t" << std::pow(test[i], 1.0/3.0) << "\t" << cbrt(test[i]) << std::endl;
    assert(std::pow(test[i], 1.0/3.0)+delta >= cbrt(test[i]) && std::pow(test[i], 1.0/3.0)-delta <= cbrt(test[i]));
  }
  return 0;
}

double cbrt(double y){
  if (y == 0.0) return 0.0;

  double x = y; //initial guess
  double epsilon = pow(10, -15)*fabs(y);

  while(fabs((x*x*x)-y) > epsilon){
    x = (2*x+(y/pow(x,2)))/3;
  }
  return x;
}
