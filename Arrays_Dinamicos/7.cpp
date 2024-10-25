#include <iostream>
#include <chrono>
#include "lista_por_array.cpp"
#include "duplamente_encadeada.cpp"

using namespace std;

int main()
{
    int N = 5000000;
    // lista duplamente encadeada;
    report_list_encadeada(N);
    //lista array dinamico;
    report_array_dinamico(N);

    return 0;
}

/*

quantidade de elementos:
Lista duplamente encadeada: 1000000
Tempo para criar a lista: 0 microsegundos
Tempo adicionar 1000000 elementos a lista: 47314 microsegundos
Tempo limpar a lista: 22132 microsegundos

Array dinamico:
Tempo para criar a lista: 0 microsegundos
Tempo adicionar 1000000 elementos a lista: 2014 microsegundos
Tempo limpar a lista: 0 microsegundos


quantidade de elementos:5000000
Lista duplamente encadeada:
Tempo para criar a lista: 0 microsegundos
Tempo adicionar 5000000 elementos a lista: 177086 microsegundos
Tempo limpar a lista: 99005 microsegundos

Array dinamico:
Tempo para criar a lista: 0 microsegundos
Tempo adicionar 5000000 elementos a lista: 15627 microsegundos
Tempo limpar a lista: 1001 microsegundos

*/