#include <iostream>
using namespace std;

class Carro
{
public:
    string marca;
    string modelo;
    int ano;
};

int main()
{
    Carro carro1, carro2;

    carro1.marca = "Toyota";
    carro1.modelo = "Corolla";
    carro1.ano = 2020;

    carro2.marca = "Honda";
    carro2.modelo = "Civic";
    carro2.ano = 2022;

    if (carro1.ano > carro2.ano)
    {
        cout << "O carro mais novo e o " << carro1.marca << " " << carro1.modelo << endl;
    }
    else
    {
        cout << "O carro mais novo e o " << carro2.marca << " " << carro2.modelo << endl;
    }

    return 0;
}
