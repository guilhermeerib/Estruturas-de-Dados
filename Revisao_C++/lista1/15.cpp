#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int numeroSecreto = rand() % 100 + 1;
    int palpite;
    cout << "Adivinhe o numero entre 1 e 100: ";
    do {
        cin >> palpite;
        if (palpite > numeroSecreto) {
            cout << "Muito alto! Tente novamente: ";
        } else if (palpite < numeroSecreto) {
            cout << "Muito baixo! Tente novamente: ";
        } else {
            cout << "Parabens! Voce acertou o numero." << endl;
        }
    } while (palpite != numeroSecreto);
    return 0;
}
