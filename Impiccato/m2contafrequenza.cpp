//Bisignano Michele
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;
char temp[50];
void contafrequenza(int alfabeto[], int lungo, int cicli, char lettere[], bool lettTent[]) {

	char lettera;
	string path;

	ifstream fpath("./path.txt");

	for (int i = 0; i < 2; i++)
		fpath >> path;

	fpath.close();

	ifstream fin(path);

	fin >> temp;

	while (!fin.eof()) {
		for (int i = 0; i < lungo; i++) {
			lettera = temp[i];

			for (int j = 0; j < 26; j++) {
				if (lettera == lettere[j])
					alfabeto[j]++;
			}
		}
		fin >> temp;
	}
	fin.close();

	return;
}