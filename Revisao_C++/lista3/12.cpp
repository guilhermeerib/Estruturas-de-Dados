#include <iostream>
#include <algorithm>
using namespace std;

bool crescente(int a, int b)
{
    return a < b;
}

bool decrescente(int a, int b)
{
    return a > b;
}

void ordenar(int arr[], int tamanho, bool (*funcPtr)(int, int))
{
    sort(arr, arr + tamanho, funcPtr);
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    
    cout << endl;
    cout << "Array original: ";
    for (int i = 0; i < tamanho; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    ordenar(arr, tamanho, crescente);
    cout << "Array ordenado crescente: ";
    for (int i = 0; i < tamanho; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    ordenar(arr, tamanho, decrescente);
    cout << "Array ordenado decrescente: ";
    for (int i = 0; i < tamanho; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
