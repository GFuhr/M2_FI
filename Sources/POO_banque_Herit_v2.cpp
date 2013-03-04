// POO_banque.cpp : définit le point d'entrée pour l'application console.
//
#include <iostream>
#include "CEmploye_v3.h"

using namespace std;

int main(int argc, char* argv[])
{
    CPersonne personne1("Gerard");
    CEmploye employe1("Roger");
    CClient client1("Francois");

 
    cout<<personne1.getName()<<endl;
    cout<<employe1.getName()<<endl;
    cout<<client1.getName()<<endl;

    cout<<" ****utilisation des pointeurs ****"<<std::endl;
    CPersonne *ppers1=&personne1;
    CPersonne *ppers2=&employe1;
    
    cout<<ppers1->getName()<<endl;
    cout<<ppers2->getName()<<endl;

    cout<<" ****utilisation des references ****"<<std::endl;
    CPersonne &rpers1=personne1;
    CPersonne &rpers2=employe1;

    cout<<rpers1.getName()<<endl;
    cout<<rpers2.getName()<<endl;


    return 0;
}
