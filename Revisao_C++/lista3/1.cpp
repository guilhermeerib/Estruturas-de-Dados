#include <iostream>
using namespace std;

int somaElementos(int arr[], int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += arr[i];
    }
    return soma;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    cout << "Soma dos elementos: " << somaElementos(arr, tamanho) << endl;
    return 0;
}
