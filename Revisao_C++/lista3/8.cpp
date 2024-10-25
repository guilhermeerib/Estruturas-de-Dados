#include <iostream>
#include <utility>
using namespace std;

// Função para contar o número de dígitos
int num_digits(int number)
{
    int digitos = 0;
    if (number == 0)
        return 1;
    while (number != 0)
    {
        number /= 10;
        digitos++;
    }
    return digitos;
}

// Função para inverter um array
void reverse(int arr[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Função para converter número em array de dígitos
pair<int *, int> number_to_array(int number)
{
    int size = num_digits(number);
    int *arr = new int[size];
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i] = number % 10;
        number /= 10;
    }
    return make_pair(arr, size);
}

int main()
{
    int number = 1561;
    pair<int *, int> result = number_to_array(number);

    cout << "Array de dígitos: ";
    for (int i = 0; i < result.second; i++)
    {
        cout << result.first[i] << " ";
    }
    cout << endl;

    cout << "Tamanho do array: " << result.second << endl;

    delete[] result.first; // Libera a memória alocada
    return 0;
}
