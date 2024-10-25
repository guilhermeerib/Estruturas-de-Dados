#include <iostream>
using namespace std;

template<typename T>
T menor(T a, T b, T c) {
    T min = (a < b) ? a : b;
    return (min < c) ? min : c;
}

int main() {
    cout << menor(5, 3, 7) << endl;       // Inteiros
    cout << menor(5.5, 3.3, 7.7) << endl; // Ponto flutuante
    return 0;
}
