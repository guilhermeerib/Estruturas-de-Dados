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
    // lista_circular() : primeiro(nullptr), ultimo(nullptr), N(0) {};
    // ~lista_circular();

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
        }
        else
        {

            ultimo->proximo = novoNo;
            novoNo->proximo = primeiro;
            ultimo = novoNo;
        }
        N++;
    }

    Iterador busca(int chave)
    {

        Iterador it;

        it.iniciar(primeiro);
        while (!it.terminou())
        {
            if (it.atual() == chave)
            {
                it.encontrado = true;
                break;
            }
            it.proximo();
        }
        return it;
    };

    void remover(int chave)
    {
        Iterador it = busca(chave);
        if (!it.encontrado)
        {
            cout << "Alvo de remoção não encontrado.";
            return;
        }

        if (it.no == primeiro)
        {
            cout << "Removendo o primeiro elemento da lista";

            primeiro = primeiro->proximo;
        }
        else if (it.anterior != nullptr)
        {
            it.anterior->proximo = it.no->proximo;
        }

        N--;
        delete it.no;
        it.no = nullptr;
    };

    void limpar()
    {
        No *c = primeiro;
        while (c != nullptr)
        {
            No *aux = c;
            c = c->proximo;
            delete aux;
        }
        N = 0;
    };

    void imprimir()
    {
        cout << "\nImprimindo lista...\n";
        cout << "Lista: Inicio, ";
        No *atual = primeiro;
        do
        {
            cout << atual->dado << ", ";
            atual = atual->proximo;
        } while (atual != primeiro);

        cout << "Inicio ...\n";
    };

}; // fim da classe lista_circular;
int main()
{

    system("cls");

    lista_circular lista;
    lista.cria();
    lista.adicionar(10);
    lista.adicionar(20);
    lista.adicionar(30);
    lista.adicionar(40);
    lista.imprimir();

    lista.remover(40);
    cout << "\nNumero de elementos na lista: " << lista.N;
    lista.imprimir();
    return 0;
}
