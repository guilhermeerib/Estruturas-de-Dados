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

    void anteriorNo()
    {
        if (no != nullptr)
        {
            No *temp = primeiro;
            while (temp->proximo != no)
            {
                temp = temp->proximo;
            }
            anterior = temp;
            no = temp;
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

    bool ehPalindromo()
    {
        if (primeiro == nullptr || primeiro->proximo == primeiro)
            return true;

        Iterador itInicio, itFim;
        itInicio.iniciar(primeiro);
        itFim.iniciar(primeiro);
        for (int i = 0; i < N - 1; i++)
        {
            itFim.proximo();
        }

        for (int i = 0; i < N / 2; i++)
        {
            if (itInicio.atual() != itFim.atual())
            {
                return false;
            }
            itInicio.proximo();
            itFim.anteriorNo();
        }
        return true;
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
    lista.adicionar(20);
    lista.imprimir();

    if (lista.ehPalindromo())
    {
        cout << "A lista é um palíndromo.\n";
    }
    else
    {
        cout << "A lista não é um palíndromo.\n";
    }

    return 0;
}
