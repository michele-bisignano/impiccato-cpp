//Bisignano Michele
#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int lettnum(char carattere);
void parolasbagliata();

void separatorestring(int lung, string filepath, int cicli, char input[], bool lettTent[], bool& fine, int errori)
{
    string pathfin, pathfout;
    bool controllo = false;//se è vero la parola rispetta le condizioni per essere copiata nel file successivo
    int* pos = new int[50];
    int quantita = 0; //conta quante parole mancano
    string temp, temp2;//temp2 mi permette di controllare di non inserire 2 parole uguali nel file

    ifstream finpath(filepath);
    finpath >> pathfin;
    finpath >> pathfout;

    ifstream fin(pathfin);
    ofstream fout(pathfout);

    if (cicli == 0) {
        fin >> temp;
        while (!fin.eof())
        {
            fin >> temp;
            if (temp.size() == lung)
                fout << temp << endl;
        }
    }
    else {
        while (!fin.eof())
        {
            controllo = false;
            fin >> temp;

            if (temp == temp2)
                goto salto;//continue

            for (int i = 0; i < lung; i++)
            {
                if (input[i] != '-')
                {
                    if (temp[i] == input[i])
                    {
                        controllo = true;
                    }
                    else
                    {
                        goto salto;//continue
                    }
                }
                else {
                    if (isalpha(temp[i])) {
                        if (lettTent[lettnum(temp[i])])//vero se la lettera è già stata tentata
                            goto salto;//continue
                        else
                            controllo = true;
                    }
                }
            }

            if (controllo) {
                fout << endl << temp;
                if (temp.size() != 0)
                    quantita++;
                controllo = false;
            }
            salto:;
            temp2 = temp;
        }
    }
    fin.close();
    fout.close();

    if (quantita == 1) {
        string giusta;
        ifstream fin(pathfout);
        fin >> temp;
        cout << "Stavi pensando alla parola: " << temp << "?" << endl;
        cin >> giusta;
        if (giusta == "no" || giusta == "NO") {
            parolasbagliata();
        }else
            cout << "HO FATTO SOLO " << errori << " ERRORI SU 10!!!" << endl << endl;

        fin.close();
        fine = true;
    }
    return;
}