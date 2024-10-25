#include <iostream>
using namespace std;

template<typename T>
T maior(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maior(5, 3) << endl;       // Inteiros
    cout << maior(5.5, 3.3) << endl;   // Ponto flutuante
    return 0;
}
