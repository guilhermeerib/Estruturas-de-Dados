#include <iostream>
#include <chrono>

using namespace std;
class ArrayList
{
public:
    int MAX;
    int N;
    int *list;
    bool error = false;

    void cria(int tam)
    {

        this->MAX = tam;
        this->list = new int[MAX];
        this->N = 0;
    }
    void libera()
    {
        delete[] list;
        this->list = new int[MAX];
        this->N = 0;
    }

    void adicionarFim(int dado)
    {

        error = false;

        if (N >= MAX)
        {

            error = true;
            return;
        }
        list[N] = dado;
        N++;
    }
};

void report_array_dinamico(int N)
{
    cout << "\nArray dinamico:" << endl;
    auto start = chrono::high_resolution_clock::now();
    ArrayList lista;
    lista.cria(N);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Tempo para criar a lista: "
         << duration.count()
         << " microsegundos"
         << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        lista.adicionarFim(i);
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Tempo adicionar "
         << N
         << " elementos a lista: "
         << duration.count()
         << " microsegundos" << endl;

    start = chrono::high_resolution_clock::now();
    lista.libera();
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Tempo limpar a lista: "
         << duration.count()
         << " microsegundos\n"
         << endl;
}
