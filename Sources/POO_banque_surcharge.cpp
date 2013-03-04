// POO_banque.cpp : définit le point d'entrée pour l'application console.
//
#include <iostream>
#include "CCompte_surcharge.h"

using namespace std;

int main(int argc, char* argv[])
{
    CCompte compte1(39);

    cout<<"le compte 1 a un solde de " << compte1.recup_solde()<<endl;
    cout<<"le compte 1 a un solde de " << (-compte1).recup_solde()<<endl;


    cout<<"le compte 1 a un solde de " << (compte1++).recup_solde()<<endl;
    cout<<"le compte 1 a un solde de " << (++compte1).recup_solde()<<endl;
    cout<<"le compte 1 a un solde de " << compte1.recup_solde()<<endl;

    int i=0;
    cout<< ++i << i++<< i<< std::endl;
	return 0;
}
