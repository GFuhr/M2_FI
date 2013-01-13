#include "CCompte.h"

double CCompte::recup_solde(void)
{
    return dSolde;
}
double CCompte::recup_lastop(void)
{
    return dLastOp;
}
void CCompte::placer(double dValeur)
{
    dSolde=dSolde+dValeur;
    dLastOp=dValeur;
}

double CCompte::retirer(double dValeur)
{
    dLastOp=dValeur;
    if ((dSolde-dValeur)<0.)
    {
        dLastOp=dSolde;
        return dLastOp;
    }
    else
    {
        dSolde=dSolde-dValeur;
        dLastOp=dValeur;
        return dLastOp;
    }
}