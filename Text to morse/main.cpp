#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "SFML/Audio.hpp"
#include <iostream>
#include <vector>
#include <string>

#include "sound reading.h"
#include "open file.cpp"

using namespace std;

int main()
{

    cout << "\nOvaj program ce pretvarati tekst u morseovu abecedu." << endl;

    string unos;
    string prijevod;
    vector<string> abc;
    abc.reserve(50);
    string koje_slovo;

    abeceda_load(abc);
    sf::SoundBuffer buffer;

    if(!buffer.loadFromFile("beep.wav"))
    {
        cout << "Greska pri ucitavanju zvuka!" << endl;
    }

    sf::Sound beep;
    beep.setBuffer(buffer);
    beep.setVolume(75);

    sf::Music hymn;

    if(!hymn.openFromFile("soviet-anthem.wav"))
    {
        cout << "Greska pri ucitavanju himne!" << endl;
    }

    hymn.setVolume(30);
    hymn.play();

    cout << "\nUnesi recenicu za pretvoriti u morseovu abecedu: ";
    getline(cin, unos);

    for(int i = 0; i < unos.size(); i++)
    {
        change(prijevod, unos[i], abc);
    }

    cout << prijevod << endl;

    for(int i = 0; i < prijevod.size(); i++)
    {

        koje_slovo.clear();

        for(int j = 0; j <= i; j++)
        {
            if(j == i)
            {
                koje_slovo += '^';
            }

            else
            {
                koje_slovo += ' ';
            }

        }

        cout << "\r" << koje_slovo;

        if(prijevod[i] == '-')
        {
            beep.play();
            //cout << "play -" << endl;
            sf::sleep(sf::seconds(0.8f));
            beep.stop();
            sf::sleep(sf::seconds(0.05));
        }

        else if(prijevod[i] == '.')
        {
            beep.play();
            //cout << "play ." << endl;
            sf::sleep(sf::seconds(0.4f));
            beep.stop();
            sf::sleep(sf::seconds(0.05));
        }

        else if(prijevod[i] == ' ')
        {
            sf::sleep(sf::seconds(0.6));
        }

        else if(prijevod[i] == '/')
        {
            sf::sleep(sf::seconds(1));
        }

    }

}
