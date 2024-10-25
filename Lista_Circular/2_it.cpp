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

    static lista_circular concatenar(const lista_circular &lista1, const lista_circular &lista2)
    {
        lista_circular novaLista;

        if (lista1.N == 0 && lista2.N == 0)
            return novaLista;
        if (lista1.N == 0)
            return lista2;
        if (lista2.N == 0)
            return lista1;

        Iterador it;
        it.iniciar(lista1.primeiro);
        do
        {
            novaLista.adicionar(it.atual());
            it.proximo();
        } while (it.no != lista1.primeiro);

        it.iniciar(lista2.primeiro);
        do
        {
            novaLista.adicionar(it.atual());
            it.proximo();
        } while (it.no != lista2.primeiro);

        return novaLista;
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

    lista_circular listaConcatenada = lista_circular::concatenar(lista1, lista2);

    cout << "Lista concatenada: ";
    listaConcatenada.imprimir();

    return 0;
}
