// POO_banque.cpp : définit le point d'entrée pour l'application console.
//
#include <iostream>
#include "CEmploye.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    CEmploye employe1;
    CClient client1;

    cout<<"le client 1 a un solde de " << employe1.solde_client(client1)<<endl;

    employe1.operation_bancaire(client1,42);
    cout<<"le client 1 a un solde de " << employe1.solde_client(client1)<<endl;


        CClient client2;
        employe1.operation_bancaire(client2,30);
        cout<<"le client 1 a un solde de " << employe1.solde_client(client1)<<endl;
        cout<<"le client 2 a un solde de " << employe1.solde_client(client2)<<endl;
        employe1.virement_compte(client1,client2,15);
        cout<<"le client 1 a un solde de " << employe1.solde_client(client1)<<endl;
        cout<<"le client 2 a un solde de " << employe1.solde_client(client2)<<endl;

	return 0;
}
