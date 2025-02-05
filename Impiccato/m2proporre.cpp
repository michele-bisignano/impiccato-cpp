//Bisignano Michele
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
//il sottoprogramma propone le lettere
void letteretentate(char proposta, bool lettTent[]);
int lettnum(char proposta);

void proporre(int lung, int& errori, bool lettTent[], char probabilityorder[], char input[])
{
    string controllo("no");
    int tentativi = 0;
    char proposta;

    while (controllo == "no")
    {
        proposta = probabilityorder[tentativi];
        if (!lettTent[lettnum(proposta)])
        {
            cout << "La tua parola contiene la lettera " << proposta << "? " << endl;
            letteretentate(proposta, lettTent);
        etichetta:
            cin >> controllo;
        }


        if (controllo.size() == lung) {
            tentativi++;
        }
        else if (controllo.size() != 2 && controllo.size() != lung) {
            cout << "Per favore inserire una parola della lunghezza corretta " << endl;
            controllo = "no";
            goto etichetta;
        }
        else {
            if (controllo.size() == 2) {
                if (controllo == "no" || controllo == "NO") {
                    errori++;
                    tentativi++;
                    return;
                }
                else if (controllo == "si" || controllo == "SI") {
                    cout << "RICORDATI DI NON INSERIRE SI, MA SOSTITUIRE, nei punti corrispondendnti AI TRATTINI, LA LETTERA PROPOSTA" << endl;
                    controllo = "no";
                    goto etichetta;
                }
                else {
                    cout << "Per favore inserire una parola della lunghezza corretta " << endl;
                    controllo = "no";
                    goto etichetta;
                }
            }

        }
    }
    //trasfomra la stringa controllo nell'array di caratteri input
    int i = 0;
    for (auto c : controllo) {
        input[i] = c;
        i++;
    }
    return;
}