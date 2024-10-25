#include <iostream>
#include <unordered_set>

using namespace std;

class No
{
public:
    char dado;
    No *proximo;
    No *anterior;

    No(char valor) : dado(valor), proximo(nullptr), anterior(nullptr) {}
};

class Iterador
{
public:
    No *no;
    bool reverso;

    Iterador(No *no_inicial, bool reverso) : no(no_inicial), reverso(reverso) {}

    char atual()
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

class ListaDuplamenteEncadeada
{
public:
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

    void adiciona_inicio(char dado)
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

    void adiciona_fim(char dado)
    {
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

    void imprimir_ordem_direta()
    {
        No *atual = inicio;
        while (atual != nullptr)
        {
            cout << atual->dado << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    bool eh_palindromo()
    {
        if (inicio == nullptr)
        {
            return true;
        }

        No *esquerda = inicio;
        No *direita = fim;

        while (esquerda != direita && esquerda->anterior != direita)
        {
            if (esquerda->dado != direita->dado)
            {
                return false;
            }
            esquerda = esquerda->proximo;
            direita = direita->anterior;
        }

        return true;
    }
};

int main()
{
    ListaDuplamenteEncadeada lista;
    lista.adiciona_fim('r');
    lista.adiciona_fim('a');
    lista.adiciona_fim('d');
    lista.adiciona_fim('a');
    lista.adiciona_fim('r');

    cout << "Lista: ";
    lista.imprimir_ordem_direta();

    if (lista.eh_palindromo())
    {
        cout << "A lista forma um palíndromo." << endl;
    }
    else
    {
        cout << "A lista não forma um palíndromo." << endl;
    }

    return 0;
}
