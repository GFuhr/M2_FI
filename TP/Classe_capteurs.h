#ifndef __CLASS_CAPTEURS
#define __CLASS_CAPTEURS

#include <iostream>
#include <cmath>
#include <cstdlib> // pour la fonction rand
#include <fstream>
#include <string>
#include <vector>


unsigned int randint(unsigned int const imax = 1024);
double randdouble(double const dmax=100, double const dmin=0);


//classe Capteur
class Capteur {
private:
    int  id ;
    double  value;

public:
    Capteur(void) ;
    Capteur(const int iid, const double dvalue=-1);
    Capteur(const Capteur &p);
    ~Capteur(void);

    void set(const double val);
    double get(void) const;
    double ecart(const Capteur &p) const;
    void cout_id(void) const;
};

#endif
