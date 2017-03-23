#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <algorithm>

std::wstring read_file(std::string filename)
{
    // Datei zum Lesen von wchar_t oeffnen
    std::wifstream infile(filename);

    // Daten einlesen
    std::wstringstream textstream;
    textstream << infile.rdbuf();

    // Inhalt als std::wstring zurueckgeben
    return textstream.str();
}

void write_file(std::string filename, std::wstring const & text)
{
    // Datei zum Schreiben von wchar_t oeffnen
    std::wofstream outfile(filename);

    // Text in Datei schreiben
    outfile << text;
}

struct Character
{
    wchar_t encrypted;
    wchar_t clear;
    int count;
};

int biggest_code(std::wstring const & text)
{
    int code = text[0];
    //code is the biggest code we want to find
    //iterate over all characters in text to find biggest one
    for(int i = 0, n = text.size(); i < n; ++i)
    {
        if(text[i] > code)
            code = text[i];
    }
    return code;
}


int main()
{
#if defined(_MSC_VER)
    // unter Windows/Visual Studio: locale fuer Deutsch definieren
    std::locale german("de-de");
#elif defined(__APPLE__)
    // unter MacOS: locale fuer Deutsch mit UTF-8 definieren
    std::locale german("de_DE.UTF-8");
#elif defined(__linux__)
    // unter Linux: locale fuer sprachunabhaengiges UTF-8 definieren
    std::locale german("C.UTF-8");
#else
    // sonst: verwende die Spracheinstellungen des Betriebssystems
    std::locale german("");
#endif

    // Konverter zwischen UTF-8 (Zeichentyp in der Datei) und
    // wchar_t (Zeichentyp im Programm) erzeugen
    std::locale codec(german, new std::codecvt_utf8<wchar_t>);

    // Konverter global setzen (er wird ab jetzt von allen
    // Ein-/Ausgabeoperationen in diesem Programm verwendet)
    std::locale::global(codec);

    // Datei einlesen
    std::wstring text = read_file("verschluesselt_utf8.txt");

    // Ihre Loesung hier

    // Determine the biggest appearing character-code
    std::cout << "Biggest Code appearing is " << biggest_code(text) << std::endl;

    // Create vector of struct Character to hold all characters
    std::vector<Character> characters(biggest_code(text) + 1);

    // Initialize the vector:
    for(int i = 0, n = characters.size(); i<n; ++i)
    {
        characters[i].count=0;
        characters[i].clear=i;
        characters[i].encrypted=i;
    }

    // Count frequency of characters in the text by incrementing count in characters
    for(int i=0, n=text.size(); i<n; ++i)
    {
        // Using tolower for ignoring upper case, german because of üöäß
        characters[std::tolower(text[i], german)].count++;
    }

    // Sort characters vector ascending according to count
    std::sort(characters.begin(), characters.end(), [](Character a, Character b){return a.count < b.count;});

    // Read file with frequency of german letters, sorted ascending
    std::wstring buchstaben = read_file("buchstaben_haeufigkeit_utf8.txt");
    //std::wcout << buchstaben << std::endl; //show string

    // Map those characters onto vector of characters
    int buch_count = 0;
    for(int i=0, n=characters.size(); i<n; ++i)
    {
        if(std::islower(characters[i].encrypted, german) && characters[i].count!=0)
        {
            characters[i].clear = buchstaben[buch_count];
            buch_count++;
        }
    }

    // Bring characters-vector in original order
    std::sort(characters.begin(), characters.end(), [](Character a, Character b){return a.encrypted<b.encrypted;});

    // Decipher text by going through every character
    for(int i=0, n=text.size(); i<n; ++i)
    {
        // If character is lower, we can use mapping
        if(std::islower(text[i], german))
        {
            text[i] = characters[text[i]].clear;
        }
        // Otherwise, character is capital letter and we have to use corresponing lower letter
        else
        {
            text[i] = std::toupper(characters[std::tolower(text[i], german)].clear, german);
        }
    }

    //Show me the characters vector
    std::cout << "The vector characters looks like this:\ni count clear encrypted" << std::endl;
    for(int i=0, n=characters.size(); i<n; ++i)
    {
        if(characters[i].count != 0)
        std::cout << i << " " << characters[i].count << " " << characters[i].clear << " " << characters[i].encrypted << std::endl;
    }

    // Ergebnis in Datei schreiben
    write_file("entschluesselt.txt", text);
}
