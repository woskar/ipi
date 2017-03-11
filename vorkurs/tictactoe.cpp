#include <iostream>

void print_feld(int feld[9]);
int frage_feld_nummer(int feld[9]);
int winner(int feld[9], int s);

int main(){
  //setup
  int feld[9];
  int i = 0;
  int a;
  int b;
  int s;
  int e;

  //initialisieren:
  while (i<9)
  {
    feld[i] = 0;
    i++;
  }
  std::cout << "Wir starten: Das ist das Spielfeld:" << std::endl;
  print_feld(feld);

while (true){
    // Input
    // Update
    // Display

  s = 1;
  std::cout << std::endl << "Spieler "<< s << " ist an der Reihe: " << std::endl;
  a = frage_feld_nummer(feld) - 1;
  feld[a] = 1;
  std::cout << "Das Spielfeld sieht jetzt so aus:" <<std::endl;
  print_feld(feld);
  e = winner(feld, s);

  if(e == s){
    std::cout << "Spieler " << s << " hat gewonnen!" << std::endl;
    std::cout << "Das Spiel wird beendet." << std::endl;
    return 0;
  }

  else if (e == 3){
    std::cout << "Das Spiel ist unentschieden, alle Felder sind besetzt." << std::endl;
    std::cout << "Das Spiel wird beendet." << std::endl;
    return 0;
  }


  s = 2;
  std::cout << std::endl << "Spieler " << s << " ist an der Reihe: " << std::endl;
  b = frage_feld_nummer(feld) - 1;
  feld[b] = 2;
  std::cout << "Das Spielfeld sieht jetzt so aus:" << std::endl;
  print_feld(feld);
  e = winner(feld, s);

  if(e == s){
    std::cout << "Spieler " << s << " hat gewonnen!" << std::endl;
    std::cout << "Das Spiel wird beendet." << std::endl;
    return 0;
  }

  else if (e == 3){
    std::cout << "Das Spiel ist unentschieden, alle Felder sind besetzt." << std::endl;
    std::cout << "Das Spiel wird beendet." <<std::endl;
    return 0;
  }

  }
}


int winner(int feld[9], int s)
{
  if(feld[0]==s and feld[1]==s and feld[2]==s)
  {
    return s;
  }
  else if(feld[3]==s and feld[4]==s and feld[5]==s)
  {
    return s;
  }
  else if(feld[6]==s and feld[7]==s and feld[8]==s)
  {
    return s;
  }
  else if(feld[0]==s and feld[3]==s and feld[6]==s)
  {
    return s;
  }
  else if(feld[1]==s and feld[4]==s and feld[7]==s)
  {
    return s;
  }
  else if(feld[2]==s and feld[5]==s and feld[8]==s)
  {
    return s;
  }
  else if(feld[0]==s and feld[4]==s and feld[8]==s)
  {
    return s;
  }
  else if(feld[2]==s and feld[4]==s and feld[6]==s)
  {
    return s;
  }
  else if(feld[0]!=0 and feld[1]!=0 and feld[2]!=0 and feld[3]!=0 and feld[4]!=0 and feld[5]!=0 and feld[6]!=0 and feld[7]!=0 and feld[8]!=0)
  {
    return 3;
  }

  else
  {
    return 0;
  }
}


void print_feld(int feld[9])
{
  std::cout << feld[0] << feld[1] << feld[2] << std::endl;
  std::cout << feld[3] << feld[4] << feld[5] << std::endl;
  std::cout << feld[6] << feld[7] << feld[8] << std::endl;
}



int frage_feld_nummer(int feld[9])
{
  int m;
  std::cout << "Welches Feld willst du wählen?" << std::endl;
  int j = 0;
  int telefon[9];
  while(j<9)
  {
    telefon[j] = j + 1;
    j++;
  }
  while(true){
    std::cout << "Setze dein Zeichen durch Angabe des Index:" << std::endl;
    print_feld(telefon);
    std::cout << "So sieht das Spielfeld momentan aus:" << std::endl;
    print_feld(feld);
    std::cout << "Eingabe: ";
    std::cin >> m;

    if(feld[m-1]==0)
    {
      return m;
      break;
    }else{
      std::cout << "Dieses Feld ist bereits besetzt!" << std::endl;
      std::cout << "Bitte gib ein anderes Feld an."  << std::endl;
    }
  }
}
