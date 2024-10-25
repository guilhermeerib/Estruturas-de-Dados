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

    void concatenar(lista_circular &outra)
    {
        if (outra.N == 0)
            return;
        if (N == 0)
        {
            primeiro = outra.primeiro;
            ultimo = outra.ultimo;
            N = outra.N;
            return;
        }

        ultimo->proximo = outra.primeiro;
        outra.ultimo->proximo = primeiro;
        ultimo = outra.ultimo;
        N += outra.N;
    }
};

int main()
{
    lista_circular lista1;
    lista1.adicionar(1);
    lista1.adicionar(2);
    lista1.adicionar(3);

    lista_circular lista2;
    lista2.adicionar(4);
    lista2.adicionar(5);
    lista2.adicionar(6);

    cout << "Lista 1: ";
    lista1.imprimir();

    cout << "Lista 2: ";
    lista2.imprimir();

    lista1.concatenar(lista2);

    cout << "Lista concatenada: ";
    lista1.imprimir();

    return 0;
}
