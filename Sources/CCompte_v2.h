
class CCompte
{
private:
    double dSolde;
    double dLastOp;

public:
    double recup_solde(void)
    {   return dSolde;   };

    double recup_lastop(void)
    {    return dLastOp; };

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