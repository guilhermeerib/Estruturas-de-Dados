#include <iostream>
using namespace std;

int main() {
    int n;
    //  Este é um tipo de dado que representa um número 
    // inteiro sem sinal (ou seja, não pode ser negativo)
    unsigned long long fatorial = 1;
    cout << "Digite um numero inteiro: ";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        fatorial *= i;
    }
    cout << "O fatorial de " << n << " e " << fatorial << endl;
    return 0;
}
