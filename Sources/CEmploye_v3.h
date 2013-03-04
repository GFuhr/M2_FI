#include <iostream>
#include <string>
#include "CCompte_vf.h"


class CPersonne
{
protected:
    int id;
    std::string name;

public:
    CPersonne(std::string pers_name="JohnDoe",int pers_id=0)
    {
        name=pers_name;
        id = pers_id;
        std::cout<<"*** nouvelle personne cree : [ "<<name<<" ] ***"<<std::endl;
    }

    CPersonne(CPersonne const & autrepersonne)
    {
        name=autrepersonne.name;
        id = autrepersonne.id;
        std::cout<<"*** nouvelle personne cree par copie : [ "<<name<<" ] ***"<<std::endl;
    }

    ~CPersonne(void)
    {
        std::cout<<"+++ Personne : [ "<<name<<" ] disparue +++"<<std::endl;
    }


    std::string  getName(void) const
    {
        return "nom de la personne : "+name;
    }

    void  setName(std::string newname) 
    {
        name=newname;
    }

    int  getID(void) const
    {
        return id;
    }




};


class CClient:public CPersonne
{
private:
    CCompte ComptePerso;

public:
    CClient(void):CPersonne()
    {
        std::cout<<"*** Personne : [ "<<name<<" ] devenue client ***"<<std::endl;
    }

   /*     CClient(std::string newname):CPersonne(newname,0)
    {
        std::cout<<"*** Personne : [ "<<name<<" ] devenue client ***"<<std::endl;
    }*/


    CClient(std::string client_name, double soldeinit=0, double id=0):CPersonne(client_name,id)
    {
        name=client_name;
        ComptePerso.placer(soldeinit);
        std::cout<<"*** Personne : [ "<<name<<" ] devenue client ***"<<std::endl;
    }

        CClient(CClient const & client):CPersonne(client)
    {
        name=client.name;
        
        std::cout<<"*** Client : [ "<<name<<" ] cree par copie ***"<<std::endl;
    }

    
    CCompte  &  donner_id_compte(void) 
    {
        return ComptePerso;
    };

    ~CClient(void)
    {
        std::cout<<"+++ Client : [ "<<name<<" ] disparue +++"<<std::endl;
    }

        std::string  getName(void) const
    {
        return "nom du client : "+name;
    }

};

class CEmploye:public CPersonne
{

public:

        CEmploye(void):CPersonne()
    {
        std::cout<<"*** Personne : [ "<<name<<" ] devenue employe ***"<<std::endl;
    }

        CEmploye(std::string newname,int id=0):CPersonne(newname,id)
    {
        std::cout<<"*** Personne : [ "<<name<<" ] devenue employe ***"<<std::endl;
    }

    ~CEmploye(void)
    {
        std::cout<<"+++ Employe : [ "<<name<<" ] disparue +++"<<std::endl;
    }


    void operation_bancaire(CClient &  client, double const somme)
    {
        CCompte & comptetemp = client.donner_id_compte();
        if (somme>0.)
            comptetemp.placer(somme);
        else
            comptetemp.retirer(somme);
    };


    void virement_compte(CClient &  client_dest,CClient &  client_src, double const somme)
    {
        CCompte & comptetemp_dest = client_dest.donner_id_compte();
        CCompte & comptetemp_src = client_src.donner_id_compte();
        comptetemp_dest.virement(comptetemp_src,somme);

    };

    double solde_client(CClient &client)
    {
        CCompte &comptetemp = client.donner_id_compte();
        std::cout<<"solde du client [ "<<client.getName()<<" ] :"<<comptetemp.recup_solde()<<std::endl;
        return comptetemp.recup_solde();
    };

        std::string  getName(void) const
    {
        return "nom de l'employe : "+name;
    }

};