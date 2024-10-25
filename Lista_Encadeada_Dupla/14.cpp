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

    void adiciona_fim(int dado)
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

    void adiciona_apos(int valor, int novo_dado)
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
        No *novo_no = new No(novo_dado);
        novo_no->proximo = atual->proximo;
        novo_no->anterior = atual;
        if (atual->proximo != nullptr)
        {
            atual->proximo->anterior = novo_no;
        }
        else
        {
            fim = novo_no;
        }
        atual->proximo = novo_no;
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

    void imprimir_ordem_inversa()
    {
        No *atual = fim;
        while (atual != nullptr)
        {
            cout << atual->dado << " ";
            atual = atual->anterior;
        }
        cout << endl;
    }

    int tamanho()
    {
        return N;
    }

    bool esta_vazia()
    {
        return inicio == nullptr;
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

    No *buscar_no(int valor)
    {
        No *atual = inicio;
        while (atual != nullptr)
        {
            if (atual->dado == valor)
            {
                return atual;
            }
            atual = atual->proximo;
        }
        return nullptr;
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
    lista.adiciona_fim(10);
    lista.adiciona_fim(20);
    lista.adiciona_fim(30);
    lista.adiciona_fim(40);
    lista.adiciona_fim(50);

    cout << "Lista na ordem direta: ";
    lista.imprimir_ordem_direta();

    int valor_busca = 30;
    No *resultado = lista.buscar_no(valor_busca);
    if (resultado != nullptr)
    {
        cout << "Valor " << valor_busca << " encontrado  no com endereco: " << resultado << endl;
    }
    else
    {
        cout << "Valor " << valor_busca << " nao encontrado na lista." << endl;
    }

    return 0;
}
