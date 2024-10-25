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

    void remover_valor(int valor)
    {
        No *atual = inicio;
        while (atual != nullptr && atual->dado != valor)
        {
            atual = atual->proximo;
        }
        if (atual == nullptr)
        {
            throw runtime_error("Valor não encontrado na lista");
        }
        if (atual->anterior != nullptr)
        {
            atual->anterior->proximo = atual->proximo;
        }
        else
        {
            inicio = atual->proximo;
        }
        if (atual->proximo != nullptr)
        {
            atual->proximo->anterior = atual->anterior;
        }
        else
        {
            fim = atual->anterior;
        }
        delete atual;
        N--;
    }

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
    lista.adiciona_fim(40);

    cout << "Lista antes da remocao do valor 30: ";
    lista.imprimir_lista();

    lista.remover_valor(30);

    cout << "Lista aps a remocao do valor 30: ";
    lista.imprimir_lista();

    return 0;
}