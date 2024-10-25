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

    void removerTodos(int valor)
    {
        cout << "\nRemovendo todos os valores: " <<valor << "\n";
        if (primeiro == nullptr)
            return;

        Iterador it;
        it.iniciar(primeiro);
        No *anterior = nullptr;

        do
        {
            if (it.no->dado == valor)
            {
                if (it.no == primeiro)
                {
                    primeiro = primeiro->proximo;
                    ultimo->proximo = primeiro;
                    delete it.no;
                    it.no = primeiro;
                }
                else
                {
                    anterior->proximo = it.no->proximo;
                    if (it.no == ultimo)
                    {
                        ultimo = anterior;
                    }
                    delete it.no;
                    it.no = anterior->proximo;
                }
                N--;
            }
            else
            {
                anterior = it.no;
                it.proximo();
            }
        } while (it.no != primeiro);

        // Caso onde todos os nós têm o valor a ser removido
        if (N == 0)
        {
            primeiro = nullptr;
            ultimo = nullptr;
        }
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
    lista.adicionar(20);
    lista.adicionar(40);
    lista.imprimir();

    lista.removerTodos(20);
    lista.imprimir();

    lista.removerTodos(10);
    lista.imprimir();

    lista.removerTodos(30);
    lista.imprimir();

    lista.removerTodos(40);
    lista.imprimir();

    return 0;
}
