#include <iostream>
using namespace std;

bool ehPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    for (int i = 21; i <= 50; i++) {
        if (ehPrimo(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
