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

    // Metodos

    // 2questao

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

    void adiciona_fim(int dado)
    {

        cout << "\nAdicionando valor " << dado << " no fim da lista;\n";
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

    int remover_inicio()
    {
        if (inicio == nullptr)
        {
            throw runtime_error("Lista vazia");
        }
        No *target = inicio;
        No *segundo = inicio->proximo;
        if (segundo != nullptr)
        {
            segundo->anterior = nullptr;
            inicio = segundo;
        }
        else
        {
            inicio = fim = nullptr;
        }
        int dado = target->dado;
        delete target;
        N--;
        return dado;
    };

    void imprimir_lista()
    {
        No *atual = inicio;
        while (atual != nullptr)
        {
            cout << atual->dado << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

}; // fim da classe ListaDuplamenteEncadeada

int main()
{
    ListaDuplamenteEncadeada lista;
    lista.adiciona_fim(10);
    lista.adiciona_fim(20);
    lista.adiciona_fim(30);

    cout << "Lista antes da remoção do início: ";
    lista.imprimir_lista();

    lista.remover_inicio();

    cout << "Lista apos a remoção do início: ";
    lista.imprimir_lista();

    return 0;
}