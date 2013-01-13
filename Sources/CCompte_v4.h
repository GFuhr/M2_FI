#include <iostream>

class CCompte
{
private:
    double dSolde;
    double dLastOp;

public:
    CCompte(double sommeinit)
    {dSolde=dLastOp=sommeinit;
       std::cout<<"***"<<std::endl<<"constructeur de la classe CCompte avec argument "<<std::endl<<"***"<<std::endl;
    };

    ~CCompte(void)
    {
       std::cout<<"++++"<<std::endl<<"destructeur de la classe CCompte "<<std::endl<<"++++"<<std::endl;
    };


    double recup_solde(void)
    {
        return dSolde;
    };
    double recup_lastop(void)
    {
        return dLastOp;
    };
    void placer(double dValeur)
    {
        dSolde=dSolde+dValeur;
        dLastOp=dValeur;
    };

    double retirer(double dValeur)
    {
        dLastOp=dValeur;

        dSolde=dSolde-dValeur;
        return dValeur;

        
    };
};