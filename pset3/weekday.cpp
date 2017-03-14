//                         _        _
//   __      __ ___   ___ | | __ __| |  __ _  _   _
//   \ \ /\ / // _ \ / _ \| |/ // _` | / _` || | | |
//    \ V  V /|  __/|  __/|   <| (_| || (_| || |_| |
//     \_/\_/  \___| \___||_|\_\\__,_| \__,_| \__, |
//                                            |___/

#include <iostream>

int weekday2001(int d, int m, int y);
int floorDiv(int a, int b);
int floorMod(int a, int b);
int weekday(int d, int m, int y);
int weekday1(int d, int m, int y);

int main(){
  std::cout << weekday2001(24, 8, 1995) << std::endl;
  std::cout << weekday1(24, 8, 1995) << std::endl;
  std::cout << weekday(24, 8, 1995) << std::endl;
  std::cout << floorDiv(-12,5) << std::endl;
  std::cout << floorMod(-12,5) << std::endl;
}

int weekday2001(int d, int m, int y){
  int z = y - 2001;
  int j1 = (365*z + z/4 - z/100 +z/400) % 7;
  int p = (m == 1) ? d : \
         ((m == 2) ? d + 31 : \
        ((m > 2) and ((y % 4 != 0 or y % 100 == 0) and y % 400 != 0) ? (d + 59 + (153*m - 457)/5) :\
       (((m > 2) and ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0)) ? (d + 60 + (153*m - 457)/5): 42 )));
       //Zuweisung von 42 sollte nicht eintreten, das heiß die letzte Fallunterscheidung ist eigentlich überflüssig,
       //nur im Falle eines Fehlers würde 42 angezeigt werden :D
       //Das könnte man jetzt ändern, lohnt sich aber nicht, ha ha.
  int w = (j1 + p - 1) % 7;
  return w;
}

int floorDiv(int a, int b){
  if(a >= 0 && b >= 0){
    return a/b;
  }
  else if (a < 0 && b < 0){
    return a/b;
  }
  else{
    return -((abs(a)+abs(b))/abs(b));
  }
}

int floorMod(int a, int b){
  return (a-(floorDiv(a,b)*b));
  // Unterschied zwischen floorMod und %:
  // normales % gibt bei -12/5 = 2.4 das .4 * 5 zurück, also 2
  // unser floorMod gibt .6*5 zurück, also 3
}

int weekday(int d, int m, int y){
  int z = y - 2001;
  int j1 = floorMod((365*z + floorDiv(z,4) - floorDiv(z,100) + floorDiv(z,400)),7);
  int p;
  if(m==1){
    p = d;
  }
  else if(m==2){
    p = d + 31;
  }
  else if(m>2 && ((floorMod(y,4)== 0 && floorMod(y,100) != 0) || floorMod(y,400)==0)){
    p = (d + 60 + floorDiv((153*m - 457),5)); // ist Schaltjahr und m > 2
  }
  else{
    p = (d + 59 + floorDiv((153*m - 457),5)); // für ist kein Schaltjahr und m > 2
  }
  int w = floorMod((j1 + p - 1),7);
  return w;
}

int weekday1(int d, int m, int y){
  int z = y - 1;
  //einfach minus eins statt minus 2001 zu schreiben funktioniert, weil
  

  int j1 = (365*z + z/4 - z/100 +z/400) % 7;
  int p = (m == 1) ? d : \
         ((m == 2) ? d + 31 : \
        ((m > 2) and ((y % 4 != 0 or y % 100 == 0) and y % 400 != 0) ? (d + 59 + (153*m - 457)/5) :\
       (((m > 2) and ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0)) ? (d + 60 + (153*m - 457)/5): 42 )));
       //Zuweisung von 42 sollte nicht eintreten, das heiß die letzte Fallunterscheidung ist eigentlich überflüssig,
       //nur im Falle eines Fehlers würde 42 angezeigt werden :D
       //Das könnte man jetzt ändern, lohnt sich aber nicht, ha ha.
  int w = (j1 + p - 1) % 7;
  return w;
}
