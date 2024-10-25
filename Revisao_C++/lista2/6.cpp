#include <iostream>
using namespace std;

template<typename T>
T soma(T a, T b) {
    return a + b;
}

int main() {
    cout << soma(5, 3) << endl;       // Inteiros
    cout << soma(5.5, 3.3) << endl;   // Ponto flutuante
    return 0;
}
