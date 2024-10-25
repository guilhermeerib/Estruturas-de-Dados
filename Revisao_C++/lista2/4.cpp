// Programa que le um numero “n” do 
// usuario e imprime todos os numeros de 1 a “n”,
//  exceto os multiplos de 3:
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Digite um numero: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            continue;
        }
        cout << i << " ";
    }
    return 0;
}
