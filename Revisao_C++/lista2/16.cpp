#include <iostream>
#include <cmath>
using namespace std;

class Ponto
{
public:
    int x, y;
};

double distanciaEuclidiana(Ponto p1, Ponto p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main()
{
    Ponto p1, p2;

    p1.x = 3;
    p1.y = 4;

    p2.x = 7;
    p2.y = 1;

    cout << "Distancia euclidiana entre os pontos: " << distanciaEuclidiana(p1, p2) << endl;

    return 0;
}
