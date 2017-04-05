#include <iostream>
#include "Classe_graphe.h"

using namespace std;

int main(int argc, char *argv[])
{
    Graphe G0(8);
    Point poly[4];
    poly[0].setX(0);
    poly[0].setY(0);
    poly[1].setX(4);
    poly[1].setY(0);
    poly[2].setX(4);
    poly[2].setY(2);
    poly[3].setX(0);
    poly[3].setY(2);
    Graphe graphe_rect(poly, 4);
    graphe_rect.printPoints();
    double aire = graphe_rect.getAire();
    std::cout << aire << std::endl;
    if (aire != 8.)
    {
        std::cout << "calcul de l'aire du graphe rectangle faux" << std::endl;
    }
    else {
        std::cout << "calcul de l'aire du graphe rectangle ok" << std::endl;
    }
    std::cout << "perimetre graphe rect:" << graphe_rect.getPerimetre()<<std::endl;
    double perimetre = graphe_rect.getPerimetre();
    if (perimetre != 12.)
    {
        std::cout << "calcul du perimetre du graphe rectangle faux" << std::endl;
    }
    else {
        std::cout << "calcul du perimetre du graphe rectangle ok" << std::endl;
    }


    std::vector<Point> vec_poly(4);
    vec_poly[0].setX(0);
    vec_poly[0].setY(0);
    vec_poly[1].setX(1);
    vec_poly[1].setY(0);
    vec_poly[2].setX(1);
    vec_poly[2].setY(1);
    vec_poly[3].setX(0);
    vec_poly[3].setY(1);
    Graphe graphe_carre(vec_poly);
    graphe_carre.printPoints();
    aire = graphe_carre.getAire();
    std::cout << aire << std::endl;
    if (aire != 1.)
    {
        std::cout << "calcul de l'aire du graphe carre faux" << std::endl;
    }
    else {
        std::cout << "calcul de l'aire du graphe carre ok" << std::endl;
    }
    perimetre = graphe_carre.getPerimetre();
    std::cout <<"perimetre graphe carre:"<< perimetre << std::endl;
    if (perimetre != 4.)
    {
        std::cout << "calcul du perimetre du graphe carre faux" << std::endl;
    }
    else {
        std::cout << "calcul du perimetre du graphe carre ok" << std::endl;
    }



    //exemples de creation de rectangle/carre correspondant à la partie 3
    Point origin;
    Rectangle rect(origin, 4, 2);
    std::cout << "aire Carre : " << rect.getAire()<<std::endl;
    if (rect.getAire() != 8.)
    {
        std::cout << "calcul de l'aire de rectangle fausse"<<std::endl;
    }
    else {
        std::cout << "calcul de l'aire de rectangle ok" << std::endl;
    }

    Carre car(origin, 4);
    if (car.getAire() != 16.)
    {
        std::cout << "calcul de l'aire du carre fausse" << std::endl;
    }
    else
    {
        std::cout << "calcul de l'aire du carre ok" << std::endl;
    }

    std::cout <<"aire Carre : "<< car.getAire()<<std::endl;
	return 0;
}

