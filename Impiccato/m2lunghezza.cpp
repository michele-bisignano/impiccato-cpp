//Bisignano Michele
#include <iostream>

using namespace std;
// Questa funzione restituisce la lunghezza della stringa
int lunghezza(char input[])
{
    int lung = 0;

    while (input[lung] == '-') {
        lung++;
    }

    return lung;
}