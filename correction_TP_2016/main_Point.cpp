#include <iostream>
#include "Classe_point.h"

using namespace std;

int main(void)
{
    Point A;
    Point B(2, 2);
    Point C(B);
    Point &D = A;
    Point *E = new Point(3, 4);

    if (A.getX() != 0)
    {
        std::cout << "souci dans le constructeur par defaut" << std::endl;
    }


    if (B.getX() != 2)
    {
        std::cout << "souci dans le constructeur avec argument" << std::endl;
    }

    if (C.getX() != 2)
    {
        std::cout << "souci dans le constructeur avec argument" << std::endl;
    }

    B.setY(5);
    if (B.getY() != 5)
    {
        std::cout << "souci dans la fonction setY" << std::endl;
    }

    B.setX(6);
    if (B.getX() != 6)
    {
        std::cout << "souci dans la fonction setX" << std::endl;
    }

    std::cout << "distance AB : " << A.distance(B) << std::endl;
    std::cout << "distance CD : " << C.distance(D) << std::endl;
    std::cout << "distance DE : " << E->distance(D) << std::endl;
    std::cout << "distance EA : " << D.distance(*E) << std::endl;

    if (E->distance(A) != 5)
    {
        std::cout << "souci dans le calcul de distance" << std::endl;
    }

    if (E->getNorme() != 5.)
    {
        std::cout << "souci dans le calcul de norme" << std::endl;
    }


    //creation de tableaux de points
    //via pointeur
    Point *G = new Point[3];
    //via vector
    vector<Point> H(3);

    delete[]G;   
    delete E;
	return 0;
}

