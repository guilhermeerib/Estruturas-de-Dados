#include <iostream>
using namespace std;

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

int main()
{
    int number = 1561;
    cout << "Numero de dígitos em " << number << ": " << num_digits(number) << endl;
    return 0;
}
