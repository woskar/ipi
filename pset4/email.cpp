//Problem 4.4: Is a given String an E-Mail-address

#include <iostream>
#include <cctype>
#include <cassert>

bool is_email(std::string s);

int main(){

  do{
  std::cout << "Please insert an email to test or leave with 'exit':\n";
  std::string s;
  std::getline(std::cin, s);
  if(is_email(s)){
    std::cout << "Your String passed all E-Mail-tests\n";
  }
  else if (s == "exit") return 0;
  else std::cout << "Test failed.\n";
  }
  while(true);

  return 0;
}

bool is_email(std::string s){
  int l=s.size(); //length of the given string
  for(int i = 0; i<l; i++){
    //let only allowed characters pass
    if(!std::isalnum(s[i]) && s[i]!='@' && s[i]!='.' && s[i]!='-' && s[i]!='_') return false;
  }


  //check if there's exaktly one '@'
  int at_count = 0;
  for(int i=0; i<l; i++){
    if(s[i] == '@') at_count++;
  }
  if(at_count > 1 || at_count==0) return false;


  //determine location of @
  int at = 0;
  for(int i=0; i<l; i++){
    if (s[i]=='@') {
      at = i;
    }
  }

  //is there a . right from @?
  if(s.substr(at+1).find('.') == std::string::npos) return false;


  //is there an allowed character before @?
  if(!std::isalnum(s[at-1]) && s[at-1]!='.' && s[at-1]!='-' && s[at-1]!='_') return false;


  //determine location of last .
  int dot = s.rfind('.');

  //is there an allowed character after the last .?
  if(l<dot) return false;
  if(!(std::isalnum(s[dot+1]) || s[dot+1]=='-' || s[dot+1]=='_')) return false;


  //is there an allowed character between @ and last .?
  if(dot - at < 2) return false;
  for(int i = at+1; i < dot; i++){
    if(!std::isalnum(s[i]) && s[i]!='-' && s[i]!='_' && s[i]!='.') return false;
  }

  return true;
}
