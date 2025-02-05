//Bisignano Michele
#include <iostream>

using namespace std;

void letteraPiuProb(int alphabet[], char probabilityorder[]) {
    char lettera, temp;
    int frequenza = 0, numero; //numero corrisponde alla posizione della lettera più frequente nell'array

    //dispone le lettere in ordine dalla più alla meno probabile;
    //ordineprobabilita[0]=lettera;

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (alphabet[i] < alphabet[j]) {

                //ordino i numeri
                temp = alphabet[i];
                alphabet[i] = alphabet[j];
                alphabet[j] = temp;

                //ordino le lettere corrispondenti
                temp = probabilityorder[i];
                probabilityorder[i] = probabilityorder[j];
                probabilityorder[j] = temp;
            }
        }
    }
    return;
}