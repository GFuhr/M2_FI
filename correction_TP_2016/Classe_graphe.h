#ifndef __CLASS_GRAPHE
#define __CLASS_GRAPHE

#include "Classe_point.h"
#include <vector>
//classe Graphe
class Graphe {
    //les donnees ici peuvent rester privées, même si protected aurait pu être utilisé
    std::vector<Point> ArrayPoint;
    int iNbPoint;
    double *point_dist;

    void calculer_distances(void);
    double calculer_perimetre(void) const;
    double calculer_aire(void) const;

 
    void allocateGrapheElements(const int N);
    void deleteGrapheElements(void);

public :
    Graphe(void);
    Graphe(const int N);
    Graphe(Point const *const Plist, const int N);
    Graphe(std::vector<Point> const &Pvector );
    Graphe(const Graphe & Poly);

    ~Graphe(void);

    void printPoints(void) const;
    Point getValue(int const  idx) const;
    int getSize(void) const;
    double getPerimetre(void) const;
    double getAire(void) const;
    void addPoints(const int N);
    void modifierPoint(const int idx, Point const& p);
};

//heritage correspondant à la partie 3

//classe rectangle (partie N)
class Rectangle:public Graphe
{
    //ici les donnees doivent être protegees car elles seront utilisee dans la classe fille carre
    //dans tous les cas Lx et Ly ne sont pas accessibles depuis Graphe.
protected:
    int Lx;
    int Ly;

public:
    ~Rectangle(void);

    Rectangle(void);

    Rectangle(Point const& P0, const int taille_x, const int taille_y);
    double getAire(void) const{ 
        std::cout << "calcul de l'aire depuis un rectangle" << std::endl; 
    return Lx*Ly; };
};

//classe carre (partie M)
class Carre :public Rectangle
{
public:
    ~Carre();
    Carre(void);
    Carre(Point const& P0, const int taille);
};
#endif
