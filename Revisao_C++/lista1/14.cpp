#include <iostream>
using namespace std;

int main() {
    int num, soma = 0;
    cout << "Digite numeros inteiros (0 para terminar): ";
    do {
        cin >> num;
        soma += num;
    } while (num != 0);
    cout << "A soma dos numeros inseridos e: " << soma << endl;
    return 0;
}
