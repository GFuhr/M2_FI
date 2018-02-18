#ifndef __CLASS_INFRA
#define __CLASS_INFRA

#include "Classe_derived.h"


class Infrastructure {
    std::vector<CapteurAnalogique> humidity;
    std::vector<CapteurDigital> temperature;
    int nombre_ca;
    int nomre_cd;

public:
    Infrastructure(void);
    Infrastructure(int Na, int Nc);
        Infrastructure(CapteurAnalogique * Vhum, CapteurDigital * Vtmp, int Nhum, int Ntmp);
    Infrastructure(std::vector<CapteurAnalogique> Vhum, std::vector<CapteurDigital> Vtmp);
    Infrastructure(Infrastructure const &p);
    ~Infrastructure(void);

    double mean();
    double deviation();
    void print(void);
    double recuperer_valeur_digital(int N);
    double recuperer_valeur_analogique(int N);
    void ajoutcapteur_digital(int N);
    void ajoutcapteur_analogique(int N);
};


#endif
