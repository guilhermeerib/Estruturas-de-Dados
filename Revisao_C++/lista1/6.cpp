#include <iostream>
using namespace std;

int main() {
    const float PI = 3.14159;
    float raio;
    cout << "Digite o raio do circulo: ";
    cin >> raio;
    float area = PI * raio * raio;
    cout << "A area do circulo e: " << area << endl;
    return 0;
}
