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
        cout << "Erro: divisão por zero!" << endl;
        return 0;
    }
}

int main()
{
    int (*funcPtr)(int, int);
    int escolha, a, b;

    while (true)
    {
        cout << ""<< endl;
        cout << "Escolha a operacao (1: soma, 2: subtracao, 3: multiplicacao, 4: divisao, 0: sair): ";
        cin >> escolha;

        if (escolha == 0)
            break;

        cout << "Digite dois numeros: ";
        cin >> a >> b;

        switch (escolha)
        { 
        case 1:
            funcPtr = soma;
            break;
        case 2:
            funcPtr = subtrai;
            break;
        case 3:
            funcPtr = multiplica;
            break;
        case 4:
            funcPtr = divide;
            break;
        default:
            cout << "Escolha invalida!" << endl;
            continue;
        }

        cout << "Resultado: " << funcPtr(a, b) << endl;
    }

    return 0;
}
