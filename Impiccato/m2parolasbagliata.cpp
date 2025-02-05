//Bisignano Michele
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//nel caso in cui il programma non ha trovato la lettera
//questa funzione valuta se la parola è presente nel database e in caso contrario
//la aggiunge a paroleaggiungere
void parolasbagliata() {
	string temp, parola;
	cout << "A quale parola stavi pensando? " << endl;
	cin >> parola;

	fstream finp;
	finp.open("./Database.txt", ios::in);

	while (!finp.eof()) {
		finp >> temp;
		if (parola == temp) {
			cout << "La parola era presente nel database, prestare attenzione a non compiere errori mentre si gioca." << endl;
			finp.close();
			return;
		}
	}
	finp.close();
	cout << "COMPLIMENTI hai trovato una parola che non era presente nel database, verra' subito aggiunta, grazie per il tuo aiuto" << endl;
	fstream fapp;//faccio inserire la parola in un altro database in modo che possa essere controllata da qualcuno prima di essere aggiunta al database
	fapp.open("./Database.txt", ios::app);
	fapp << endl << parola;
	fapp.close();
	return;
}