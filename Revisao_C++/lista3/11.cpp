#include <iostream>
#include <cmath>
using namespace std;

double areaCirculo(double raio)
{
    return M_PI * raio * raio;
}

double areaQuadrado(double lado)
{
    return lado * lado;
}

int main()
{
    double (*funcPtr)(double);
    char escolha;
    double medida;

    cout << "\nEscolha a forma (c para circulo, q para quadrado): ";
    cin >> escolha;

    if (escolha == 'c')
    {
        funcPtr = areaCirculo;
        cout << "Digite o raio do círculo: ";
    }
    else if (escolha == 'q')
    {
        funcPtr = areaQuadrado;
        cout << "Digite o lado do quadrado: ";
    }
    else
    {
        cout << "Escolha inválida!" << endl;
        return 1;
    }

    cin >> medida;
    cout << "Area: " << funcPtr(medida) << endl;

    return 0;
}
