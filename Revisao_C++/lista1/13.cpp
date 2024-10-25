#include <iostream>
using namespace std;

bool ehPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    cout << "Numeros primos entre 1 e 100: ";
    for (int i = 1; i <= 100; ++i) {
        if (ehPrimo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
