//Bisignano Michele
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>

using namespace std;

void confronto(string parola, string input, string& find, int& errori);
int lettnum(char lettera);//data una lettera restituisce la sua posizione nell'alfabeto

void modalita1()
{
    string parola;//conterrà la stringa che l'utente deve indovinare
    string input;// conterrà la risposta dell'utente
    string find;//contiene le lettere trovate dall'utente
    int errori = 0; //conta gli errori dell'utente (sono necessari 10 errori per perdere), va da 0 a 9
    int lung = 0;//indica la lunghezza del file
    bool alfabeto[26] = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };//diventa falso quando l'utente ha provato la lettera
    //alfabeto permette di controllare che l'utente non chieda più volte la stessa lettera
    //conto quante parole contiene il database
    fstream fin;
    fin.open("./Database.txt");

    while (!fin.eof()) {
        fin >> parola;
        lung++;
    }
    fin.close();
    //genero un numero casuale compreso tra 0 e il numero di parole nel file
    srand(time(NULL));
    int num = (rand() % lung) + 1;//num contiene il numero di cicli che deve compiere il for a righa 25 affinché
    //in parola sia contenuta la parola che l'utente deve indovinare
    fin.open("./Database.txt");
    for (int i = 0; i < num && i < lung; i++) {
        fin >> parola;
    }
    fin.close();
    find = parola;//inizializza find con la stessa lunghezza di parola

    for (int i = 0; i < parola.size(); i++) {
        find[i] = '-';
    }
    cout << find << endl;

    while (true) {
        cout << endl << "Inserisci la lettera che pensi che sia contenuta nella parola,\noppure inserisci direttamente la parola: ";
        cin >> input;

        if (input.size() == 1) { //caso in cui l'utente abbia inserito una sola lettera
            if (isalpha(input[0])) {
                input[0] = tolower(input[0]);
                int varletnum = lettnum(input[0]);
                if (alfabeto[lettnum(input[0])]) {
                    confronto(parola, input, find, errori);
                    if (find == parola) {
                        cout << "COMPLIMENTI HAI INDOVINATO LA PAROLA!!!" << endl;
                        return;
                    }
                    alfabeto[lettnum(input[0])] = false; //rendo falso il record corrispondente alla lettera tentata in modo che non entri più nel ciclo
                }
                else {
                    cout << "Per favore inserire una lettera che non sia gia' stata provata." << endl;
                    continue;
                }
            }
            else {
                cout << "Per favore inserire una lettera" << endl;
            }
        }
        else { //caso in cui l'utente abbia inserito più lettere
            if (input.size() != parola.size()) { //se l'input dell'utente non ha tanti caratteri quanti quelli della parola da indovinare
                cout << "Inserisci una parola della stessa lunghezza di quella da indovinare, oppure proporre le lettere una ad una.\n";
            }
            else if (input == parola) {
                cout << "COMPLIMENTI HAI INDOVINATO LA PAROLA!!!" << endl;
                return;
            }
            else if (input != parola) {
                errori++;
                cout << "hai sbagliato!!!" << endl << "Per ora hai fatto " << errori << " errori" << endl;
            }
        }
        if (errori == 10) {
            cout << "\nMi dispiace hai perso, hai fatto 10 errori." << endl << "La parola da indovinare era: " << parola;
            return;
        }
    }
}