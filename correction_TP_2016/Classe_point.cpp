#include "Classe_point.h"


Point::Point(void)
{
    _x = _y = 0.;
    _norm = 0;

    std::cout << "    Appel du constructeur sans parametres pour le point " << this << std::endl;
}

Point::Point(const double val_x, const double val_y)
{
    _x = val_x;
    _y = val_y;
    
    this->calculer_norme();
    std::cout << "    Appel du constructeur avec 2 parametres pour le point " << this << std::endl;
}

Point::Point(const Point &p)
{
    _x = p._x;
    _y = p._y;
    this->calculer_norme();
    std::cout << "    Appel du constructeur par copie pour le point " << this << " depuis le point : "<<&p<<std::endl;
}

Point::~Point()
{
    std::cout << "    Appel du destructeur pour le point  a l'adresse : " << this << std::endl;
}


double Point::getNorme(void) const
{
    return _norm;
}

double Point::getX(void) const
{
    return _x;
}

double Point::getY(void) const
{
    return _y;
}

void Point::setX(double const val)
{
    _x = val;
    calculer_norme();
}

void Point::setY(double const val) 
{
    _y = val;
    calculer_norme();
}



double  Point::distance(const Point &autrePoint) const
{
    double const dx = _x - autrePoint._x;
    double const dy = _y - autrePoint._y;

    return sqrt(dx*dx + dy*dy);
}


//calcul de la norme, pour avoir une sorte de calcul "automatique" lorsque un point est cree ou modifie, il faut faire appel à cette fonction dans
//les divers constructeurs et les fonctions setX/setY
void Point::calculer_norme(void)
{
    _norm = sqrt(_x*_x + _y*_y);
}

