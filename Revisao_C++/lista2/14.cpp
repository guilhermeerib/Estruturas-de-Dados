#include <iostream>
using namespace std;

class Pessoa
{
public:
    string nome;
    int idade;
    float altura;
};

int main()
{
    Pessoa p;
    p.nome = "João";
    p.idade = 30;
    p.altura = 1.75;

    cout << "Nome: " << p.nome << endl;
    cout << "Idade: " << p.idade << endl;
    cout << "Altura: " << p.altura << " metros" << endl;

    return 0;
}
