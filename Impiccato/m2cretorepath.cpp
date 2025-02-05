//Bisignano Michele
//crea il path a file nuovi sui quali l'algoritmo andrà a lavorare
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void creatorepath(int cicli) {

	ofstream fout("./path.txt");

	if (cicli == 0) {
		fout << "Database.txt" << endl;
	}
	else if (cicli != 0) {
		fout << "./lista";
		fout << cicli;
		fout << ".txt" << endl;
	}
	fout << "./lista";
	fout << ++cicli;
	fout << ".txt" << endl;

	fout.close();
	return;
}