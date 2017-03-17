//Problem 4.3: Palindromes

#include <cctype>
#include <iostream>
#include <cassert>

std::string to_lower(std::string s);
std::string letter_only(std::string s);
bool is_palindrom(std::string s);

int main(){
  std::cout << to_lower("OsKar") << std::endl;
  std::cout << letter_only("test 1 2 3 test") << std::endl;
  std::cout << is_palindrom("anna") << std::endl;

  //Test some examples:
  std::string test[5] = {"Anna", "Otto", "Rentner", "Lagerregal", "Ein Neger mit Gazelle zagt im Regen nie"};
  for(int i = 0, n = 5; i < n; i++){
    assert(is_palindrom(test[i]) == true);
  }

  do{
  std::cout << "Please insert a word or sentence or leave with 'exit':\n";
  std::string s;
  std::getline(std::cin, s);
  if(is_palindrom(s)){
    std::cout << "That's a palindrome!\n";
  }
  else if (s == "exit") return 0;
  else std::cout << "That's not a palindrome.\n";
  }
  while(true);
}

//a) function to lower all characters in a given string
std::string to_lower(std::string s){
  char temp;
  for(int i = 0, n = s.size(); i < n; i++){
    temp = s[i];
    s[i] = std::tolower(temp);
  }
  return s;
}

//b) only return the letters in the string
std::string letter_only(std::string s){
  std::string result;
  for(int i = 0, n = s.size(); i < n; i++){
    if(std::isalpha(s[i])){
      result += s[i];
    }
  }
  return result;
}

//c) palindrome function
bool is_palindrom(std::string s){
  s = to_lower(letter_only(s));
  int i = 0;
  int j = s.size() - 1;
  while(i <= j){
    if(s[i] == s[j]){
      i++;
      j--;
    }
    else return false;
  }
  return true;
}
