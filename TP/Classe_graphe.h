#ifndef __CLASS_GRAPHE
#define __CLASS_GRAPHE

#include "Classe_point.h"
#include <vector>
//classe Graphe
class Graphe {
    std::vector<Point> ArrayPoint;
    int iNbPoint;
    double *point_dist;

public :
    Graphe(void);
    Graphe(const int N);
   // Graphe(double const *const listX, double const *const listY, const int N);
    Graphe(Point const *const Plist, const int N);
    Graphe(std::vector<Point> &Plist );
    Graphe(const Graphe & Poly);

    ~Graphe(void);

    void printPoints(void) const;
    Point getValue(int const  idx) const;
    int getSize(void) const;
    double getPerimetre(void) const;
    double getAire(void) const;

};
#endif
