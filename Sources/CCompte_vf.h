#include <iostream>

class CCompte
{
private:
    double dSolde;
    double dLastOp;

public:
    CCompte(void)
    {dSolde=dLastOp=0.0;
    std::cout<<"*** constructeur de la classe CCompte par defaut  ***"<<std::endl;
    };

    CCompte(double const sommeinit)
    {dSolde=dLastOp=sommeinit;
    std::cout<<"*** constructeur de la classe CCompte avec argument  ***"<<std::endl;
    };

    CCompte(CCompte const &  comptebase)
    {
        dSolde=comptebase.dSolde;
        dLastOp=comptebase.dLastOp;
        std::cout<<"*** constructeur de la classe CCompte par copie  ***"<<std::endl;
    };


    ~CCompte(void)
    {
        std::cout<<"++++ destructeur de la classe CCompte  ++++"<<std::endl;
    };

    void virement(CCompte &autrecompte, double const somme)
    {
        dLastOp = somme;
        dSolde=dSolde+somme;
        autrecompte.dLastOp = -somme;
        autrecompte.dSolde = autrecompte.dSolde - somme;
    };

    double recup_solde(void) const
    {
        return dSolde;
    };

    double recup_lastop(void) const
    {
        return dLastOp;
    };

    void placer(double const dValeur)
    {
        dSolde=dSolde+dValeur;
        dLastOp=dValeur;
    };

    double retirer(double const dValeur)
    {
        dLastOp=dValeur;
        dSolde=dSolde-dValeur;

        return dValeur;

    }
};