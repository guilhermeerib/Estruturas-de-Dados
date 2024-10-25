#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Digite o tamanho do array[]: ";
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Digite o valor para arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "\nElementos do array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
