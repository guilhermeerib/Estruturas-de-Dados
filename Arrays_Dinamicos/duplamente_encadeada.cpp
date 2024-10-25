#include <iostream>
#include <chrono>

using namespace std;
class No
{
public:
    int dado;
    No *proximo;
    No *anterior;

    No(int dado)
    {
        this->dado = dado;
        this->proximo = nullptr;
        this->anterior = nullptr;
    }
};

class ListaEncadeada
{
public:
    No *inicio;
    No *fim;
    int N;

    void cria()
    {
        inicio = nullptr;
        fim = nullptr;
        N = 0;
    }

    // metodos

    void adiciona_inicio(int dado)
    {
        No *novoNo = new No(dado);
        novoNo->proximo = inicio;
        inicio = novoNo;
    }

    void adiciona_fim(int dado)
    {

        No *no = new No(dado);
        if (N == 0)
        {
            inicio = fim = no;
        }
        else
        {
            no->anterior = fim;
            fim->proximo = no;
            fim = no;
        }
        N++;
    }
    void libera()
    {
        No *atual = inicio;
        while (atual != nullptr)
        {
            No *temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }
};

void report_list_encadeada(int N)
{
    cout << "\nLista duplamente encadeada:" << std::endl;

    auto start = chrono::high_resolution_clock::now();
    ListaEncadeada lde;
    lde.cria();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Tempo para criar a lista: " << duration.count() << " microsegundos" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        lde.adiciona_fim(i);
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Tempo adicionar "
         << N
         << " elementos a lista: "
         << duration.count()
         << " microsegundos"
         << endl;

    start = chrono::high_resolution_clock::now();
    lde.libera();
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Tempo limpar a lista: "
         << duration.count()
         << " microsegundos\n"
         << endl;
}
