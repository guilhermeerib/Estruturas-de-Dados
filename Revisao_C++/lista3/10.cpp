#include <iostream>
using namespace std;

int soma(int a, int b)
{
    return a + b;
}

int subtrai(int a, int b)
{
    return a - b;
}

int multiplica(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b != 0)
        return a / b;
    else
    {
        cout << "Erro: divisao por zero!" << endl;
        return 0;
    }
}

int operacao(int a, int b, int (*funcPtr)(int, int))
{
    return funcPtr(a, b);
}

int main()
{
    cout << "Soma: " << operacao(10, 5, soma) << endl;
    cout << "Subtracao: " << operacao(10, 5, subtrai) << endl;
    cout << "Multiplicacao: " << operacao(10, 5, multiplica) << endl;
    cout << "Divisao: " << operacao(10, 5, divide) << endl;

    return 0;
}
