#include <iostream>
#include <string>
#include "CCompte_vf.h"


class CPersonne
{
protected:
    int id;
    std::string name;

public:
    CPersonne(std::string pers_name="JohnDoe",int pers_id=0);
    CPersonne(CPersonne const & autrepersonne);
    ~CPersonne(void);


    std::string  getName(void) const;
    void  setName(std::string newname) ;
    int  getID(void) const;
};



class CClient:public CPersonne
{
private:
    CCompte ComptePerso;

public:
    CClient(void):CPersonne()
    {
        std::cout<<"*** Personne : [ "<<name<<" ] devenue client ***"<<std::endl;
    };

    CClient(std::string client_name, double soldeinit=0.);
    CClient(CClient const & client);

    CCompte &   donner_id_compte(void) ;

    ~CClient(void);
};

class CEmploye:public CPersonne
{
public:
    ~CEmploye(void)
    {
        std::cout<<"+++ Employe : [ "<<name<<" ] disparu +++"<<std::endl;
    };

    CEmploye(void):CPersonne()
    {
        std::cout<<"*** Personne : [ "<<name<<" ] devenue employe ***"<<std::endl;
    };

    CEmploye(std::string employe_name);
    CEmploye(CEmploye const & employe);

    double solde_client(CClient  &client) const;
    void virement_compte(CClient &  client_dest,CClient &  client_src, double const somme);
    void operation_bancaire(CClient &  client, double const somme);

};


CPersonne::CPersonne(std::string pers_name,int pers_id)
{
    name=pers_name;
    id = pers_id;
    std::cout<<"*** nouvelle personne cree : [ "<<name<<" ] ***"<<std::endl;
}

CPersonne::CPersonne(CPersonne const & autrepersonne)
{
    name=autrepersonne.name;
    id = autrepersonne.id;
    std::cout<<"*** nouvelle personne cree par copie : [ "<<name<<" ] ***"<<std::endl;
}

CPersonne::~CPersonne(void)
{
    std::cout<<"+++ Personne : [ "<<name<<" ] disparue +++"<<std::endl;
}


std::string  CPersonne::getName(void) const
{
    return name;
}

void  CPersonne::setName(std::string newname) 
{
    name=newname;
}

int  CPersonne::getID(void) const
{
    return id;
}



CClient::CClient(std::string client_name, double soldeinit):CPersonne(client_name)
{
    name=client_name;
    ComptePerso.placer(soldeinit);
    std::cout<<"*** Personne : [ "<<name<<" ] devenue client ***"<<std::endl;
}

CClient::CClient(CClient const & client):CPersonne(client)
{
    name=client.name;
    id=client.id;
    ComptePerso.placer(client.ComptePerso.recup_solde());
    std::cout<<"*** Client : [ "<<name<<" ] cree par copie ***"<<std::endl;
}


CCompte &   CClient::donner_id_compte(void)  
{
    return ComptePerso;
};

CClient::~CClient(void)
{
    std::cout<<"+++ Client : [ "<<name<<" ] disparue +++"<<std::endl;
}





void CEmploye::operation_bancaire(CClient &  client, double const somme)
{
    CCompte  &comptetemp = client.donner_id_compte();
    if (somme>0.)
        comptetemp.placer(somme);
    else
        comptetemp.retirer(somme);
};


void CEmploye::virement_compte(CClient &  client_dest,CClient &  client_src, double const somme)
{
    CCompte  &comptetemp_dest = client_dest.donner_id_compte();
    CCompte  &comptetemp_src = client_src.donner_id_compte();
    comptetemp_dest.virement(comptetemp_src,somme);

};

double CEmploye::solde_client(CClient  &client) const
{
    std::cout<<"solde du client [ "<<client.getName()<<" ] :"<<client.donner_id_compte().recup_solde()<<std::endl;
    return client.donner_id_compte().recup_solde();
};

CEmploye::CEmploye(std::string client_name):CPersonne(client_name)
{
    name=client_name;

    std::cout<<"*** Personne : [ "<<name<<" ] devenue employe ***"<<std::endl;
}