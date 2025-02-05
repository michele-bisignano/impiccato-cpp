//Bisignano Michele
#include <iostream>
#include <cctype>
#include <windows.h>

using namespace std;

int lettnum(char lettera);//data una lettera restituisce la sua posizione nell'alfabeto
void immagineimp(int errori);//restituisce in output l'immagine dell'impiccato

//questo sottoprogramma confronta la stringa con il carattere inserito dall'utente
void confronto(string parola, string input, string& find, int& errori) {
	
	char lettera = input[0];//lettera proposta dall'utente
	int lung = parola.size();
	string controllo = find; //questa variabile mi permette di eseguire i controlli

	lettera = tolower(lettera);

	for (int i = 0; i < lung; i++) {
		if (lettera == parola[i])
			controllo[i] = lettera;
	}
	system("CLS");
	if (controllo == find) {
		errori++;
		cout << "\nMi dispiace ma la parola non contiene la lettera proposta" << endl << "Per ora hai fatto " << errori << " errori" << endl;;
	}
	else
		find = controllo;

	immagineimp(errori);

	cout << endl << find << endl; //restituisce la parola con i trattini al posto delle lettere sconosciute

	return;
}