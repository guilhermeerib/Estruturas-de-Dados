// ListaDuplamenteEncadeada

#include <iostream>

using namespace std;

class No
{
public:
    int dado;
    No *proximo;
    No *anterior;

    // No(int valor) : dado(valor), proximo(nullptr), anterior(nullptr) {};
};

class Iterador
{
public:
    No *no = nullptr;
    bool reverso = false;
    No *inicio;
    No *fim;
    int N;
    bool found;

    int atual()
    {
        return this->no->dado;
    }

    bool terminou()
    {
        return this->no == nullptr;
    }
    void proximo()
    {
        if (this->no != nullptr)
        {
            no = no->proximo;
        }
    }

    void anterior()
    {
        if (this->no != nullptr)
        {
            no = no->anterior;
        }
    }

    void cria()
    {
        this->inicio = nullptr;
        this->fim = nullptr;
        this->N = 0;
    }

    void adiciona_inicio(int dado)
    {
        auto *no = new No{.dado = dado, .proximo = nullptr, .anterior = nullptr};
        if (this->N == 0)
        {
            this->inicio = no;
            this->fim = no;
        }
        else
        {
            no->proximo = this->inicio;
            this->inicio->anterior = no;
            this->inicio = no;
        }
        this->N++;
    };

    Iterador iterador(bool reverso)
    {
        Iterador it{.no = nullptr, .found = false, .reverso = reverso};
        if (reverso)
        {
            it.no = fim;
        }
        else
        {
            it.no = inicio;
        }
        return it;
    }

    int remover_fim()
    {
        if (this->fim == nullptr)
        {
            return std::numeric_limits<int>::min();
        }
        No *target = this->fim;
        No *penultimo = this->fim->anterior;
        if (penultimo != nullptr)
        {
            penultimo->proximo = nullptr;
            this->fim = penultimo;
        }
        else
        {
            this->inicio = nullptr;
            this->fim = nullptr;
        }
        int dado = target->dado;
        delete target;
        this->N--;
        return dado;
    }

    Iterador busca(int dado, bool reverso)
    {
        Iterador it = iterador(reverso);
        while (!it.terminou())
        {
            if (it.atual() == dado)
            {
                it.found = true;
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
    };
}; // fim da classe Iterador
