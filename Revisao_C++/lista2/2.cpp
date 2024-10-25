#include <iostream>
using namespace std;

int main() {
    int num;
    while (true) {
        cout << "Digite um numero: ";
        cin >> num;
        if (num < 0) {
            break;
        }
    }
    return 0;
}
