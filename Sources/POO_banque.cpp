// POO_banque.cpp�: d�finit le point d'entr�e pour l'application console.
//
#include <iostream>
#include "CCompte.h"

using namespace std;

int main(int argc, char* argv[])
{
    CCompte compte1;


    cout<<"le compte 1 a un solde de " << compte1.dSolde<<endl;
    cout<<"le montant de la derniere operation surl e compte 1 etait de " << compte1.dLastOp<<endl;

    compte1.dSolde=25;
    cout<<"le compte 1 a un solde de " << compte1.dSolde<<endl;
    cout<<"le montant de la derniere operation surl e compte 1 etait de " << compte1.dLastOp<<endl;
	return 0;
}

