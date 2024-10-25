#include <iostream>
using namespace std;

float media(float notas[], int tamanho)
{
    float soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += notas[i];
    }
    return soma / tamanho;
}

int main()
{
    float notas[] = {7.5, 8.0, 6.5, 9.0, 8.5};
    int tamanho = sizeof(notas) / sizeof(notas[0]);
    cout << "Media das notas: " << media(notas, tamanho) << endl;
    return 0;
}
