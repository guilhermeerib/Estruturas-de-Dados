/*
1. Implemente uma função que cria um array dinâmico vazio. Em seguida, implemente uma função
que inicializa o array dinâmico com um determinado tamanho e preenche todos os elementos com
um valor padrão.

*/

#include <iostream>

using namespace std;

class ArrayDinamico
{

public:
    int N;
    int *list;
    bool error;

    // Construtor vazio e nulo
    ArrayDinamico() : N(0), list(nullptr), error(false) {}
    // Destrutor (forma atual)
    ~ArrayDinamico()
    {
        if (list != nullptr)
        {
            delete[] list;
        }
        N = 0;
    };

    void criaVazio()
    {
        if (list == nullptr)
        {
            delete[] list;
        }

        list = new int[0];
        N = 0;
    }

    void criaArrayTamN(int tamanho, int valorPadrao)
    {
        if (list != nullptr)
        {

            delete[] list;
        }
        list = new int[tamanho];
        for (int i = 0; i < tamanho; i++)
        {
            list[i] = valorPadrao;
        }
        N = tamanho;
    }

    void imprimirLista()
    {
        if (N == 0)
        {
            cout << "Lista vazia\n"
                 << endl;
            return;
        }
        cout << "\nTamanho da lista: " << N << "\n";
        cout << "Lista: ";

        for (int i = 0; i < this->N; i++)
        {
            cout << this->list[i] << ", ";
        }
        cout << "Fim." << endl;
    }

}; // fim da classe ArrayDinamico

int main()
{

    system("cls");
    ArrayDinamico lista;

    lista.criaVazio();
    lista.imprimirLista();

    lista.criaArrayTamN(1000, 0);
    lista.imprimirLista();

    return 0;
}
