// POO_banque.cpp : définit le point d'entrée pour l'application console.
//
#include <iostream>
#include "CEmploye_v2.h"

using namespace std;

int main(int argc, char* argv[])
{
    CEmploye employe1;
    CClient client1("Francois");


    employe1.operation_bancaire(client1,42);
    employe1.solde_client(client1);


    CClient client2;
    employe1.operation_bancaire(client2,30);
    employe1.virement_compte(client1,client2,15);
    employe1.solde_client(client1);
    employe1.solde_client(client2);


    CPersonne p1("toto");
    CPersonne p2=p1;
    cout <<"personne 2 "<<p2.getName()<<std::endl;
    p1.setName("tata");
    cout <<"personne 2 "<<p2.getName()<<std::endl;

    employe1.operation_bancaire(client1,42);

    CClient client3(client1);
    employe1.solde_client(client1);
    employe1.solde_client(client3);

    return 0;
}
