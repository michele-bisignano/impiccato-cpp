//Bisignano Michele
#include <iostream>
#include <cctype>

using namespace std;

//data una lettera restituisce la sua posizione nell'alfabeto
int lettnum(char lettera) {
	int pos = 0;//contiene la posizione della lettera nell'alfabeto
	char alfabeto[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	while (lettera != alfabeto[pos])
		pos++;

	return pos;
}