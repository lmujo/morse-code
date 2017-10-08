#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "open file.h"

using namespace std;

void abeceda_load(vector<string> &abc)
{

    string line;

    ifstream myfile;

    myfile.open("Files/morse_1.txt");

    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            abc.push_back(line);
        }

    }

    myfile.close();

}

void change(string &tekst, char c, vector<string> &abc)
{
    int mjesto;
    string slovo;

    if(c - 65 >= 0 && c - 65 <= 25)
    {
        mjesto = c - 65;

        slovo = abc[mjesto];

        for(int i = 0; i < slovo.size() - 2; i++)
        {
            tekst = tekst + slovo[i];
        }

        tekst = tekst + ' ';

    }

    else if(c - 97 >= 0 && c - 97 <= 25)
    {
        mjesto = c - 97;

        slovo = abc[mjesto];

        for(int i = 0; i < slovo.size() - 2; i++)
        {
            tekst = tekst + slovo[i];
        }

        tekst = tekst + ' ';

    }

    else if(c == 32)
    {
        tekst = tekst + '/' + ' ';
    }

}
