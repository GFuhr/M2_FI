#include "Classe_capteurs.h"

//NE PAS TOUCHER A CES 2 DEFINITIONS
//genere un nombre entier aleatoire entre 0 et imax
unsigned int randint(unsigned int const imax)
{
    return rand() % imax;
}


//genere un nombre decimal aleatoire entre 0 et dmax
double randdouble(double const dmax, double const dmin)
{
    return dmin+(rand() / (1. + RAND_MAX))*dmax;
}

//COMMENCER LA DEFINITION DE LA CLASSE ICI
