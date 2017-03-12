#include <string>
#include <iostream>
#include <assert.h>

int main(){
  std::string s1 = "oskar";
  std::string s2 = "xyz";
  std::string s3;
  std::string s4;

  assert(s1.size() == 5);
  s3 = s1 + s2;
//  s4 = "bla" + "blub"; das ist nicht erlaubt
  s4 = "test " + s2;

  std::cout << s1 << std::endl;
  std::cout << "s.size() gibt " << s1.size() << std::endl;
  std::cout << s2 << std::endl;
  std::cout << s3 << std::endl;
  std::cout << s4 << std::endl;

  //meine Funktion zum umkehren eines Strings:
  int i = 0;
  int k = s1.size()-1;
  std::string s_neu = s1;
  while(i<=k){
    s_neu[i] = s1[k-i];
    i++;
  }
  std::cout << "Umgekehrter erster String: " << s_neu << std::endl;


  //Funktion aus Vorlesung:
  i = 0;
  k = s1.size()-1;
  while (i<k){
    char temp = s1[i];
    s1[i] = s1[k];
    s1[k] = temp;
    i++;
    k--;
  }
  std::cout << "Umgekehrter erster String: " << s1 << std::endl;

}
