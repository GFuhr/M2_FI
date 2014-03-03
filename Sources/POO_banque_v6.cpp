// POO_banque.cpp : définit le point d'entrée pour l'application console.
//
#include <iostream>
#include "CCompte_v6.h"

using namespace std;

int main(int argc, char* argv[])
{
    CCompte compte1;
    CCompte compte2(12);

    cout<<"le compte 1 a un solde de " << compte1.recup_solde()<<endl;
    cout<<"le compte 2 a un solde de " << compte2.recup_solde()<<endl;

    compte1.virement(compte2,12);
    cout<<"le compte 1 a un solde de " << compte1.recup_solde()<<endl;
    cout<<"le compte 2 a un solde de " << compte2.recup_solde()<<endl;
	return 0;
}
