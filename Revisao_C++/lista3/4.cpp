#include <iostream>
using namespace std;

void imprimeArray(int *arr, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    imprimeArray(arr, tamanho);
    return 0;
}
