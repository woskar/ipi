//       _     _____    _____     ____   _
//      / \   |___ /   |___ / _  / ___| (_) _ __   _   _  ___
//     / _ \    |_ \     |_ \(_) \___ \ | || '_ \ | | | |/ __|
//    / ___ \  ___) |_  ___) |_   ___) || || | | || |_| |\__ \
//   /_/   \_\|____/(_)|____/(_) |____/ |_||_| |_| \__,_||___/
//
#include <cmath>
#include <iostream>

double taylor_sin(double x);
double bogen(double x);
double pump_sin(double sin_third);
double my_sin(double x);

int main(){

  //Teilaufgabe a): Taylor Näherung für Sinus
  double test[18] = {1,2,3,4,5,6,7,8,9,10,20,45,90,135,180,225,270,315};
  std::cout << "Test wird durchgeführt: Grad, Taylor, Sinus, Fehler" << std::endl;
  for (int i=0; i < 18; i++){
    double a = taylor_sin(bogen(test[i]));
    double b = std::sin(bogen(test[i]));
    std::cout << test[i] << "   \t" << a << "   \t" << b << "       \t" << (b - a) << std::endl;
  }
/*  Ausgabe: Grad, Taylor, Sinus, Fehler
1   	0.0174524   	0.0174524      	1.34959e-11
2   	0.0348995   	0.0348995      	4.3186e-10
3   	0.052336   	  0.052336       	3.27932e-09
4   	0.0697565   	0.0697565      	1.38183e-08
5   	0.0871557   	0.0871557      	4.21674e-08
6   	0.104528     	0.104528       	1.04918e-07
7   	0.121869    	0.121869       	2.26747e-07
8   	0.139173    	0.139173       	4.42032e-07
9   	0.156434    	0.156434       	7.96458e-07 //bis neun Grad ist der Fehler unter 10^-6
10   	0.173647    	0.173648       	1.34862e-06
20   	0.341977    	0.34202       	4.30622e-05
45   	0.704653    	0.707107       	0.00245413
90   	0.924832    	1       	      0.0751678
135  	0.176066    	0.707107       	0.531041
180 	-2.02612    	1.22465e-16    	2.02612
225  	-6.1662     	-0.707107      	5.45909
270  	-12.7286    	-1            	11.7286
315  	-22.1979    	-0.707107     	21.4908
*/

  //Teilaufgabe b): pump_sin implementieren

  //Teilaufgabe c): my_sin
  double test2[18] = {1,2,3,4,5,6,7,8,9,10,20,45,90,135,180,225,270,315};
  std::cout << std::endl << "Test wird durchgeführt: Grad, my_sin, Sinus, Fehler" << std::endl;
  for (int i=0; i < 18; i++){
    double c = my_sin(bogen(test2[i]));
    double d = std::sin(bogen(test2[i]));
    std::cout << test2[i] << "   \t" << c << "   \t" << d << "       \t" << (d - c) << std::endl;
  }
  //std::abs();
}

double bogen(double x){
  return (x * M_PI) / 180;
}

double taylor_sin(double x){
  return (x - ((x*x*x)/6));
}

double pump_sin(double sin_third){
  if(sin_third*3 >= -M_PI && sin_third*3 <= M_PI){
    return 3*sin_third - 4 * (pow(sin_third,3.0));
  }
  //Teilaufgabe d)
  else{
    int k = (sin_third*3)/(2*M_PI);
    sin_third = ((sin_third*3)-k*(2*M_PI))/3;
    return 3*sin_third - 4 * (pow(sin_third,3.0));
  }
}

double my_sin(double x){
  double r = (x <= 9) ? taylor_sin(x) : pump_sin(my_sin(x/3.0));
  return r;
}
