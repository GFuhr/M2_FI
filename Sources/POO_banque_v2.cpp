// POO_banque_v2.cpp : définit le point d'entrée pour l'application console.

#include <iostream>
#include "CCompte_v2.h"

using namespace std;

int main(int argc, char* argv[])
{
    CCompte compte1;
    

    cout<<"le compte 1 a un solde de " << compte1.recup_solde()<<endl;
    cout<<"le montant de la derniere operation sur le compte 1 etait de " << compte1.recup_lastop()<<endl;

    compte1.placer(25);
    cout<<"le compte 1 a un solde de " << compte1.recup_solde()<<endl;
    cout<<"le montant de la derniere operation sur le compte 1 etait de " << compte1.recup_lastop()<<endl;
	return 0;
}
