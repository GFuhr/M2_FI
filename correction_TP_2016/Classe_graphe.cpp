#include "Classe_graphe.h"

//fonction privee dans laquelle les allocations faites via new sont effacees, plus sûr que des copier/coller
void Graphe::deleteGrapheElements(void)
{
    delete []point_dist, point_dist = NULL;
}

//fonction pour faire les allocations de taille des divers tableaux, plus sûr que les copier/collerdans les constructeurs
void Graphe::allocateGrapheElements(const int N)
{
    iNbPoint = N;
    point_dist = new double[N];
    ArrayPoint.resize(N);
}

//constructeur par defaut de la classe graphe
Graphe::Graphe(void)
{
    std::cout << "  constructeur par defaut pour la classe Graphe " << this << std::endl;
    iNbPoint = 0;
    ArrayPoint.resize(0);
    point_dist = NULL;
}


Graphe::Graphe(const int N)
{
    double const Pi = 3.12159;
    std::cout << "  constructeur avec taille pour la classe Graphe " <<this<< std::endl;
    //allocation des tableaux
    //l'allocation memoire doit être faite dans tous les constructeurs attention
    allocateGrapheElements(N);

    //remplissage des elements
    for (int i = 0; i < N; i++)
    {
        double const x = (double)i / (double)(N - 1);
        ArrayPoint[i].setX(x);
        ArrayPoint[i].setY(sin(Pi*x));
    }
    //mise à jour des distances
    calculer_distances();
}


Graphe::Graphe(Point const *const Plist, const int N)
{
    std::cout << "  constructeur via liste de valeurs pour la classe Graphe " << this << std::endl;
    //allocation des tableaux
    allocateGrapheElements(iNbPoint);
    //Pour remplir le tableau, il faut le faire element par element
    //Une instruction du type ArrayPoint = Plist ne copie pas les valeurs du tableau Plist dans ArrayPoint mais copie l'adresse du tableau
    for (int i = 0; i < iNbPoint; i++)
    {
        ArrayPoint[i].setX(Plist[i].getX());
        ArrayPoint[i].setY(Plist[i].getY());
    }
    calculer_distances();
}

Graphe::Graphe(std::vector<Point> const& Pvector)
{
    std::cout << "  constructeur via liste de valeurs pour la classe Graphe " << this << std::endl;
    //allocation des tableaux
    allocateGrapheElements(Pvector.size());
    for (int i = 0; i < iNbPoint; i++)
    {
        ArrayPoint[i].setX(Pvector[i].getX());
        ArrayPoint[i].setY(Pvector[i].getY());
    }
    calculer_distances();
}


Graphe::Graphe(const Graphe & Poly)
{
    std::cout << "  constructeur via copie pour la classe Graphe " << this << std::endl;
    iNbPoint = Poly.iNbPoint;

    //allocation des tableaux
    allocateGrapheElements(iNbPoint);

    for (int i = 0; i < iNbPoint; i++)
    {
        ArrayPoint[i].setX(ArrayPoint[i].getX());
        ArrayPoint[i].setY(ArrayPoint[i].getY());
        point_dist[i] = Poly.point_dist[i];
    }
}


Graphe::~Graphe(void)
{
    //Contrairement à la classe point, cette fois ci l'utilisation de tableaux dynamiques en tant que donnees membres oblige à mettre 
    //un delete dans le destructeur
    deleteGrapheElements();
    std::cout << "  destructeur pour la classe Graphe" << this << std::endl;
}

double Graphe::calculer_perimetre(void) const
{
    double res = 0;
    for (int i = 0; i < iNbPoint; i++)
    {
        res += point_dist[i];
    }
    return res;
}

Point Graphe::getValue(int const  idx) const
{
    return ArrayPoint[idx];
}

int Graphe::getSize(void) const
{
    return iNbPoint;
}


double Graphe::getPerimetre(void) const
{
    return calculer_perimetre();
}

void Graphe::calculer_distances(void)
{
    for (int i = 0; i < iNbPoint; i++)
    {
        point_dist[i] = ArrayPoint[i].distance(ArrayPoint[(i + 1) % iNbPoint]);
    }
}


double Graphe::calculer_aire(void) const
{
    double aire = 0;
    for (int i = 0; i < iNbPoint; i++)
    {
        //utilisation de variables locales pour une meilleure lisibilite
        int const next_i = (i+1)%iNbPoint;
        double const xiyii = ArrayPoint[i].getX()*ArrayPoint[next_i].getY();
        double const xiiyi = ArrayPoint[i].getY()*ArrayPoint[next_i].getX();

        aire += xiyii - xiiyi;
    }
    aire = 0.5*fabs(aire);
    return aire;
}


//fonction renvoyant l'aire du graphe
double Graphe::getAire(void) const
{
    std::cout << "calcul de l'aire depuis un graphe" << std::endl;
    return calculer_aire();
}

//affichage des points sur la console
void Graphe::printPoints(void) const 
{
    for (int i = 0; i < iNbPoint; i++)
    {
        std::cout << "idx : " << i << "(" << ArrayPoint[i].getX() << ", " << ArrayPoint[i].getY() << ")\n";
    }
}

//fonction pour ajouter des points
void Graphe::addPoints(const int N)
{
    int const ancienne_taille = iNbPoint;
    iNbPoint += N;
    ArrayPoint.resize(iNbPoint);

    //plus compliqué pour la distance vu qu'il n'y a pas de resize pour les tableaux défini via pointeur
    //etape 1 : on copie les distances dans un tableau temporaire
    double *copy_distance = new double[ancienne_taille];
    for (int idx = 0; idx < ancienne_taille; idx++)
    {
        copy_distance[idx] = point_dist[idx];
    }

    //etape 2 : on efface point_dist et on le recrée avec la nouvelle taille
    delete[]point_dist;
    point_dist = new double[iNbPoint];

    //etape 3 : on copie les valeurs et on initialise les autres à 0
    for (int idx = 0; idx < ancienne_taille; idx++)
    {
        point_dist[idx] = copy_distance[idx];
    }
    for (int idx = ancienne_taille; idx < iNbPoint; idx++)
    {
        point_dist[idx] = 0.;
    }

    //on oublie pas d'effacer le tableau temporaire
    delete[]copy_distance;
}

/* fonction permettant de modifier les coordonnees d'un point du graphe, utile pour la partie 3 principalement */
void Graphe::modifierPoint(const int idx, Point const& p)
{
    ArrayPoint[idx].setX(p.getX());
    ArrayPoint[idx].setY(p.getY());

    //une coordonnee a change donc on recalcules les distances entre les points
    calculer_distances();
}


//classes associées à la partie 3

Rectangle::~Rectangle(void)
{
    std::cout << "  destructeur de la classe rectangle pour l'objet :" << this << std::endl;
}


Rectangle::Rectangle(void) :Graphe()
{
    std::cout << "  constructeur par defaut pour la  classe rectangle pour l'objet :" << this << std::endl;
}

//pour faire le rectangle (donc un graphe de 4 points) on specifie le constructeur Graphe qui sera appelé avec la taille en argument (:Graphe(4)) et ensuite on crée
//le rectangle
Rectangle::Rectangle(Point const& P0, const int taille_x = 1, const int taille_y = 1):Graphe(4)
{
    std::cout << "  constructeur avec argument pour la  classe rectangle pour l'objet :" << this << std::endl;
    Lx = taille_x;
    Ly = taille_y;
    //on cree un tableau de points correspondant aux coordonnees du rectangle
    Point coord[4];
    double x0 = P0.getX();
    double y0 = P0.getY();
    coord[0].setX(x0);
    coord[0].setY(y0);
    coord[1].setX(x0+taille_x);
    coord[1].setY(y0);
    coord[2].setX(x0 + taille_x);
    coord[2].setY(y0+taille_y);
    coord[3].setX(x0);
    coord[3].setY(y0+taille_y);
    for (int idx = 0; idx < 4; idx++)
    {
        modifierPoint(idx, coord[idx]);
    }
}


Carre::~Carre(void)
{
    std::cout << "  destructeur de la classe Carre pour l'objet :"<<this<<std::endl;
}


Carre::Carre(void) :Rectangle()
{
    std::cout << "  constructeur par defaut pour la  classe Carre pour l'objet :" << this << std::endl;
}

//De même que pour le constructeur de Rectangle on avait specifie le constructeur de graphe qui devait être utilisé, 
//il en est de même pour le constructeur de Carre ou l'on choisit le constructeur de rectangle utilise
Carre::Carre(Point const& P0, const int taille = 2) :Rectangle(P0, taille, taille)
{
    std::cout << "  constructeur avec argument pour la  classe Carre pour l'objet :" << this << std::endl;
}

