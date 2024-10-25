#include <iostream>
using namespace std;

template<typename T>
void swap_valores(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "x: " << x << ", y: " << y << endl;
    
    swap_valores(x, y);
    cout << "Swap_valores: x= " << x << ", y= " << y << endl;  // x: 10, y: 5

    double a = 1.1, b = 2.2;
    cout << "a: " << a << ", b: " << b << endl; 
    swap_valores(a, b);
    cout << " Swap_valores: a= " << a << ", b= " << b << endl;  // a: 2.2, b: 1.1

    return 0;
}
