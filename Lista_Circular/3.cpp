#include <iostream>

using namespace std;

class No
{
public:
    int dado;
    No *proximo;

    No(int valor) : dado(valor), proximo(nullptr) {}
};

class lista_circular
{
public:
    No *primeiro;
    No *ultimo;
    int N;

    lista_circular() : primeiro(nullptr), ultimo(nullptr), N(0) {}

    void adicionar(int dado)
    {
        No *novoNo = new No(dado);
        if (N == 0)
        {
            primeiro = novoNo;
            ultimo = novoNo;
            novoNo->proximo = novoNo;
        }
        else
        {
            ultimo->proximo = novoNo;
            novoNo->proximo = primeiro;
            ultimo = novoNo;
        }
        N++;
    }

    void imprimir()
    {
        if (N == 0)
            return;
        No *atual = primeiro;
        do
        {
            cout << atual->dado << " ";
            atual = atual->proximo;
        } while (atual != primeiro);
        cout << endl;
    }

    void reverter()
    {
        if (N < 2)
            return;

        No *anterior = nullptr;
        No *atual = primeiro;
        No *proximo = nullptr;
        No *inicio = primeiro;

        do
        {
            proximo = atual->proximo;
            atual->proximo = anterior;
            anterior = atual;
            atual = proximo;
        } while (atual != inicio);

        primeiro->proximo = anterior;
        primeiro = anterior;
    }
};

int main()
{
    lista_circular lista;
    lista.adicionar(1);
    lista.adicionar(2);
    lista.adicionar(3);
    lista.adicionar(4);
    lista.adicionar(5);

    cout << "Lista original: ";
    lista.imprimir();

    lista.reverter();

    cout << "Lista revertida: ";
    lista.imprimir();

    return 0;
}
