#include <iostream>
using namespace std;

template<typename T>
T media(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    cout << media(arr1, 5) << endl;  // Inteiros

    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << media(arr2, 5) << endl;  // Ponto flutuante

    return 0;
}
