#include <iostream>
using namespace std;

int main() {
    float largura, altura;
    cout << "Digite a largura do retangulo: ";
    cin >> largura;
    cout << "Digite a altura do retangulo: ";
    cin >> altura;
    float perimetro = 2 * (largura + altura);
    cout << "O perimetro do retangulo e: " << perimetro << endl;
    return 0;
}
