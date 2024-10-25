#include <iostream>
using namespace std;

int main() {
    float num1, num2, num3;
    cout << "Digite tres numeros reais: ";
    cin >> num1 >> num2 >> num3;
    float media = (num1 + num2 + num3) / 3;
    cout << "A media aritmetica e: " << media << endl;
    return 0;
}
