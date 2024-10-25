#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Digite o primeiro numero: ";
    cin >> num1;
    cout << "Digite o segundo numero: ";
    cin >> num2;

    if (num1 > num2) {
        cout << "O primeiro numero e maior que o segundo." << endl;
    } else if (num1 < num2) {
        cout << "O primeiro numero e menor que o segundo." << endl;
    } else {
        cout << "Os dois numeros são iguais." << endl;
    }
    return 0;
}
