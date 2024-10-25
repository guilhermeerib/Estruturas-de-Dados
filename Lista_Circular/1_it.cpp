#include <iostream>

using namespace std;

class No
{
public:
    int dado;
    No *proximo;

    No(int valor) : dado(valor), proximo(nullptr) {}
};

class Iterador
{
public:
    No *no = nullptr;
    No *anterior = nullptr;
    No *primeiro = nullptr;
    bool encontrado = false;

    int atual()
    {
        return no->dado;
    }

    bool terminou()
    {
        return no == primeiro && anterior != nullptr;
    }

    void iniciar(No *primeiroNo)
    {
        primeiro = primeiroNo;
        no = primeiroNo;
        anterior = nullptr;
    }

    void proximo()
    {
        if (no != nullptr)
        {
            anterior = no;
            no = no->proximo;
            if (no == nullptr)
            {
                no = primeiro;
            }
        }
    }
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

        Iterador it;
        it.iniciar(primeiro);

        for (int i = 0; i < (N - 1) / 2; ++i)
        {
            it.proximo();
        }

        lista1.primeiro = primeiro;
        lista1.ultimo = it.no;
        lista2.primeiro = it.no->proximo;
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
    lista2.imprimir();

    return 0;
}
