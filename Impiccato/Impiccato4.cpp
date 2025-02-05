//Bisignano Michele
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
//modalita:
void modalita1();
void modalita2();
//funzioni della modalita1
void confronto(string parola, string input, string& find, int& errori);
void immagineimp(int errori);
int lettnum(char lettera);//data una lettera restituisce la sua posizione nell'alfabeto
//funzioni della modalita2
int lunghezza(char controllo[]);
void separatorestring(int lung, string filepath, int cilcli, char input[], bool lettTent[], bool& fine);
void contafrequenza(int alfabeto[], int lung, int cicli, char lettere[], bool lettTent[]);
void creatorepath(int cicli);
void letteraPiuProb(int alfabeto[], char le[]);
void proporre(int lung, int& errori, bool lettTent[], char probabilityorder[], char input[]);
void letteretentate(char proposta, bool lettTent[]);
//int convLettNum(char proposta);
bool parola1(string filepath);
void parolasbagliata();
int main()
{
    //interfaccia grafica
    system("color f0");

    int modalita;//conterrà la modalità che l'utente vuole giocare
    bool cesterno = true;//c significa ciclo, la variabile gestisce il ciclo più grande
    while (cesterno) {
        bool cinterno = true; //c significa ciclo, la variabile gestisce il ciclo più piccolo, che si ripete fino a quando l'utente non in serisce la modalità corretta
        cout << "Questo e' il gioco dell'impiccato, scegliere la modalita':\n";
        cout << "- modalita' 1: l'utente tenta di indovinare la parola scelta dal programma;\n";
        cout << "- modalita' 2: l'utente sceglie una parola e l'algoritmo tenta di indovinarla;\n";

        cout << endl << "Inserisci il numero corrispondente alla modalita' che si vuole giocare." << endl;
        while (cinterno) {
            cin >> modalita;
            if (modalita == 1) {//l'utente tenta di indovinare
                system("CLS");
                modalita1();
                cinterno = false;
            }
            else if (modalita == 2) {//l'utente sceglie la parola e l'algoritmo tenta di indovinarla
                system("CLS");
                modalita2();
                cinterno = false;
            }
            else {
                cout << "per favote inserire 1 oppure 2 a seconda della modalita' che si vuole giocare." << endl;
            }
        }
        string contrcestreno;//la variabile controlla il ciclo esterno, che si ripete se l'utente vuole rigiocare
        cout << endl <<"Scrivi si se vuoi rigiocare " << endl;
        cin >> contrcestreno;
        if (contrcestreno != "si" && contrcestreno != "SI" && contrcestreno != "s" && contrcestreno != "S")
            cesterno = false;

        system("CLS");
    }
    return 0;
}
