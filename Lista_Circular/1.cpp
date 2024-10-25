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

    void dividir(lista_circular &lista1, lista_circular &lista2)
    {
        if (N < 2)
            return;

        No *slow = primeiro;
        No *fast = primeiro;

        while (fast->proximo != primeiro && fast->proximo->proximo != primeiro)
        {
            slow = slow->proximo;
            fast = fast->proximo->proximo;
        }

        lista1.primeiro = primeiro;
        lista1.ultimo = slow;
        lista2.primeiro = slow->proximo;
        lista2.ultimo = ultimo;

        lista1.ultimo->proximo = lista1.primeiro;
        lista2.ultimo->proximo = lista2.primeiro;

        lista1.N = (N + 1) / 2;
        lista2.N = N / 2;
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

    lista_circular lista1, lista2;
    lista.dividir(lista1, lista2);

    cout << "Primeira metade: ";
    lista1.imprimir();

    cout << "Segunda metade: ";
    lista1.primeiro->dado = 10;
    lista2.primeiro->dado = 40;
    lista2.imprimir();

    return 0;
}
