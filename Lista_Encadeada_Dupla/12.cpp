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

    void inverter()
    {
        No *atual = inicio;
        No *temp = nullptr;
        while (atual != nullptr)
        {
            temp = atual->anterior;
            atual->anterior = atual->proximo;
            atual->proximo = temp;
            atual = atual->anterior;
        }
        if (temp != nullptr)
        {
            inicio = temp->anterior;
        }
    }

    void imprimir_lista_esq_p_dir()
    {
        cout << "\nImprimindo Lista do inicio ao fim, da esquerda para direita.\nLista: ";
        No *atual = inicio;
        while (atual != nullptr)
        {
            cout << atual->dado << ", ";
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
    lista.adiciona_fim(50);
    cout << "Lista na ordem direta: ";
    lista.imprimir_lista_esq_p_dir();

    lista.inverter();

    cout << "Lista após inversão: ";
    lista.imprimir_lista_esq_p_dir();

    return 0;
}