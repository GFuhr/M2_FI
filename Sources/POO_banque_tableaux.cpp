// POO_banque.cpp : définit le point d'entrée pour l'application console.
//
#include <iostream>
#include "CCompte_vf.h"
#include <vector>


int main(int argc, char* argv[])
{
    CCompte compte1[2]; //version statique
    CCompte compte1b[2]={CCompte(10),CCompte(11)}; //version statique

    std::cout<<"le compte 1[0] a un solde de " << compte1[0].recup_solde()<<std::endl;
    std::cout<<"le compte 1[1] a un solde de " << compte1[1].recup_solde()<<std::endl;
    std::cout<<"le compte 1b[0] a un solde de " << compte1b[0].recup_solde()<<std::endl;
    std::cout<<"le compte 1b[1] a un solde de " << compte1b[1].recup_solde()<<std::endl;

    CCompte *compte2=NULL; //version dynamique
    compte2=new CCompte[4];

    std::cout<<"le compte 2[0] a un solde de " << compte2[0].recup_solde()<<std::endl;
	
    delete []compte2;

    std::vector<CCompte> v1(4,-2); //version dynamique via STL
    std::cout<<"le compte v1[0] a un solde de " << v1[0].recup_solde()<<std::endl;
    std::cout<<"le compte v1[1] a un solde de " << v1.at(1).recup_solde()<<std::endl;
    return 0;
}
