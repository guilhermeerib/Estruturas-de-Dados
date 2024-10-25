#include <iostream>

using namespace std;

class No
{
public:
    int dado;
    No *proximo;

    No(int valor) : dado(valor), proximo(nullptr) {};
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

    void cria()
    {
        primeiro = nullptr;
        ultimo = nullptr;
        N = 0;
    }

    void adicionar(int dado)
    {
        No *novoNo = new No(dado);
        if (N == 0)
        {
            primeiro = novoNo;
            ultimo = novoNo;
            novoNo->proximo = novoNo; // Aponta para si mesmo
        }
        else
        {
            ultimo->proximo = novoNo;
            novoNo->proximo = primeiro;
            ultimo = novoNo;
        }
        N++;
    }

    void inverter()
    {
        if (primeiro == nullptr || primeiro->proximo == primeiro)
            return;

        Iterador it;
        it.iniciar(primeiro);

        No *anterior = ultimo;
        No *atual = primeiro;
        No *proximo = nullptr;

        do
        {
            proximo = atual->proximo;
            atual->proximo = anterior;
            anterior = atual;
            atual = proximo;
            it.proximo();
        } while (atual != primeiro);

        primeiro = anterior;
        ultimo = atual;
    }

    void imprimir()
    {
        if (primeiro == nullptr)
        {
            cout << "Lista vazia.\n";
            return;
        }

        cout << "\nImprimindo lista...\n";
        cout << "Lista: Inicio, ";
        No *atual = primeiro;
        do
        {
            cout << atual->dado << ", ";
            atual = atual->proximo;
        } while (atual != primeiro);

        cout << "Inicio ...\n";
    }
};

int main()
{
    lista_circular lista;
    lista.cria();
    lista.adicionar(10);
    lista.adicionar(20);
    lista.adicionar(30);
    lista.adicionar(40);
    lista.imprimir();

    lista.inverter();
    lista.imprimir();

    return 0;
}
