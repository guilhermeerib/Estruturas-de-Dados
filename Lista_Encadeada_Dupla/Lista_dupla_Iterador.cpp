#include <iostream>
#include <limits>

using namespace std;

class No
{
public:
    int dado;
    No *proximo;
    No *anterior;

    No(int valor) : dado(valor), proximo(nullptr), anterior(nullptr) {}
};

class ListaDuplamenteEncadeada
{
public:
    class Iterador
    {
    public:
        No *no;
        bool reverso;

        Iterador(No *no_inicial, bool reverso) : no(no_inicial), reverso(reverso) {}

        int atual()
        {
            return no->dado;
        }

        bool terminou()
        {
            return no == nullptr;
        }

        void proximo()
        {
            if (no != nullptr)
            {
                no = no->proximo;
            }
        }

        void anterior()
        {
            if (no != nullptr)
            {
                no = no->anterior;
            }
        }
    };
    
    No *inicio;
    No *fim;
    int N;

    ListaDuplamenteEncadeada() : inicio(nullptr), fim(nullptr), N(0) {}

    ~ListaDuplamenteEncadeada()
    {
        while (inicio != nullptr)
        {
            No *temp = inicio;
            inicio = inicio->proximo;
            delete temp;
        }
    }

    void adiciona_inicio(int dado)
    {
        No *no = new No(dado);
        if (N == 0)
        {
            inicio = fim = no;
        }
        else
        {
            no->proximo = inicio;
            inicio->anterior = no;
            inicio = no;
        }
        N++;
    }

    int remover_fim()
    {
        if (fim == nullptr)
        {
            throw runtime_error("Lista vazia");
        }
        No *target = fim;
        No *penultimo = fim->anterior;
        if (penultimo != nullptr)
        {
            penultimo->proximo = nullptr;
            fim = penultimo;
        }
        else
        {
            inicio = fim = nullptr;
        }
        int dado = target->dado;
        delete target;
        N--;
        return dado;
    }

    Iterador criar_iterador(bool reverso)
    {
        return Iterador(reverso ? fim : inicio, reverso);
    }

    Iterador busca(int dado, bool reverso)
    {
        Iterador it = criar_iterador(reverso);
        while (!it.terminou())
        {
            if (it.atual() == dado)
            {
                break;
            }
            if (!it.reverso)
            {
                it.proximo();
            }
            else
            {
                it.anterior();
            }
        }
        return it;
    }
};

int main()
{
    ListaDuplamenteEncadeada lista;
    lista.adiciona_inicio(10);
    lista.adiciona_inicio(20);
    lista.adiciona_inicio(30);

    ListaDuplamenteEncadeada::Iterador it = lista.criar_iterador(false);
    while (!it.terminou())
    {
        cout << it.atual() << " ";
        it.proximo();
    }
    cout << endl;

    return 0;
}
