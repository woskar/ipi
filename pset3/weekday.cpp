//                         _        _
//   __      __ ___   ___ | | __ __| |  __ _  _   _
//   \ \ /\ / // _ \ / _ \| |/ // _` | / _` || | | |
//    \ V  V /|  __/|  __/|   <| (_| || (_| || |_| |
//     \_/\_/  \___| \___||_|\_\\__,_| \__,_| \__, |
//                                            |___/

#include <iostream>

int weekday2001(int d, int m, int y);

int main(){
  std::cout << weekday2001(12, 3, 2017) << std::endl;
}

int weekday2001(int d, int m, int y){
  int z = y - 2001;
  int j1 = (365*z + z/4 - z/100 +z/400) % 7;
  int p = (m == 1) ? d : \
         ((m == 2) ? d + 31 : \
        ((m > 2) and ((y % 4 != 0 or y % 100 == 0) and y % 400 != 0) ? (d + 59 + (153*m - 457)/5) :\
       (((m > 2) and ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0)) ? (d + 60 + (153*m - 457)/5): d )));

  int w = (j1 + p - 1) % 7;
  return w;
}
