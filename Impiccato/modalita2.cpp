//Bisignano Michele
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int lunghezza(char controllo[]);
void separatorestring(int lung, string filepath, int cilcli, char input[], bool lettTent[], bool& fine,int errori);
void contafrequenza(int alfabeto[], int lung, int cicli, char lettere[], bool lettTent[]);
void creatorepath(int cicli);
void letteraPiuProb(int alfabeto[], char le[]);
void proporre(int lung, int& errori, bool lettTent[], char probabilityorder[], char input[]);
void letteretentate(char proposta, bool lettTent[]);
int lettnum(char lettera);
bool parola1(string filepath);
void parolasbagliata();
void immagineimp(int errori);

const string filepath("./path.txt");

void modalita2(){
    char* input = new char[50];
    cout << "inserisci la parola da indovinare,\nATTENZIONE Gli accenti sono stati rimossi!" << endl;
    cout << "Inizialmente scrivere tanti trattini '-' quanti sono i caratteri della parola da inserire;" << endl;
    cout << "in seguito alle proposte del computer NON RISPONDERE SI,\nMA SOSTITUIRE, nei punti corrispondenti AI TRATTINI, LA LETTERA PROPOSTA " << endl;
    cin >> input;

    int lung = lunghezza(input);
    int cicli = 0; //si aggiorna ad ogni tentativo
    bool fine = false;

    int errori = 0;
    bool lettTent[26] = { false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false };
    char lettere[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

    while (true) {
        char probabilityorder[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
        int alfabeto[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

        creatorepath(cicli);
        separatorestring(lung, filepath, cicli, input, lettTent, fine, errori);
        if (fine) {
            immagineimp(errori);
            return;
        }

        if (parola1(filepath)) //se ha trovato la parola o non l'ha trovata
            return;

        cicli++;

        contafrequenza(alfabeto, lung, cicli, lettere, lettTent);

        for (int i = 0; i < 26; i++) {
            if (lettTent[i] == true)
                alfabeto[i] = -1;
        }

        letteraPiuProb(alfabeto, probabilityorder);
        //arrivato qui a copiare
        proporre(lung, errori, lettTent, probabilityorder, input);

        if (errori == 10) {
            cout << "HAI VINTO " << endl;
            parolasbagliata();
            cout << "Se vuoi rigiocare riesegui il programma";
            return;
        }
    }
}