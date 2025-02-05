#include <iostream>
#include <fstream>
#include <cstring>
//Bisignano Michele
#include <string>

using namespace std;

void parolasbagliata();
bool parola1(string filepath)
{
    bool condizione = false;
    string temporanea, path;
    ifstream finpath(filepath);

    for (int i = 0; i < 2; i++)
        finpath >> path;

    finpath.close();

    ifstream fin(path);
    int i = 0;
    while (!fin.eof())
    {
        fin >> temporanea;
        i++;
    }
    fin.close();
    if (i == 1) {
        condizione = true;
        cout << "NON ABBIAMO TROVATO LA PAROLA CHE STAVI CERCANDO" << endl;
        parolasbagliata();
    }
    
    return condizione;
}