//Bisignano Michele
#include <iostream>

using namespace std;
int lettnum(char proposta);
//rende vera la cella in corrispondenza della lettera proposta all'untente nell'array lettTent[]
void letteretentate(char proposta, bool lettTent[])
{
    int i = lettnum(proposta);
    lettTent[i] = true;

    return;
}