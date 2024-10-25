#include <iostream>
using namespace std;

int soma(int a, int b)
{
    return a + b;
}

int multiplica(int a, int b)
{
    return a * b;
}

int main()
{
    int (*funcPtr)(int, int);

    funcPtr = soma;
    cout << "Soma: " << funcPtr(5, 3) << endl;

    funcPtr = multiplica;
    cout << "Multiplicacao: " << funcPtr(5, 3) << endl;

    return 0;
}
