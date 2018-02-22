#ifndef __CLASS_INFRA
#define __CLASS_INFRA

#include "Classe_derived.h"


class Infrastructure {
    // Déclarer les données membres ici

public:
    Infrastructure(void);
    Infrastructure(int Na, int Nc);
    Infrastructure(CapteurAnalogique * Vhum, CapteurDigital * Vtmp, int Nhum, int Ntmp);
    Infrastructure(std::vector<CapteurAnalogique> Vhum, std::vector<CapteurDigital> Vtmp);
    Infrastructure(Infrastructure const &p);
    ~Infrastructure(void);

    double mean();
    void print(void);
    double recuperer_valeur_digital(int N);
    double recuperer_valeur_analogique(int N);

};


#endif
