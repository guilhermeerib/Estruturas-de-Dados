#include <iostream>

using namespace std;
class No
{
public:
    int dado;
    No *prox;
};

class FilaEncadeada
{
public:
    int N;
    int erro;
    No *p_inicio;
    No *p_fim;

    void cria()
    {
        this->p_inicio = nullptr;
        this->p_fim = nullptr;
        N = 0;
    }

    bool vazia()
    {
        return this->N == 0;
    }

    int tamanho()
    {
        return N;
    }

    int frente()
    {
        if (vazia())
        {
            erro = 1;
            return -1;
        }
        erro = 0;
        return this->p_inicio->dado;
    }

    void libera()
    {
        while (!vazia())
        {
            desenfileira();
        }
    }

    void enfileira(int dado)
    {
        erro = 0;
        No *novo = new No();
        novo->dado = dado;
        novo->prox = nullptr;
        if (vazia())
        {
            this->p_inicio = novo;
            this->p_fim = novo;
        }
        else
        {
            this->p_fim->prox = novo;
            this->p_fim = novo;
        }
        N++;
    }

    int desenfileira()
    {
        erro = 0;
        if (vazia())
        {
            erro = 1;
            return -1;
        }
        No *aux = this->p_inicio;
        int dado = aux->dado;
        this->p_inicio = this->p_inicio->prox;
        delete aux;
        N--;
        return dado;
    }
};
int main()
{
    FilaEncadeada p;
    p.cria();
    p.enfileira(1);
    p.enfileira(2);
    p.enfileira(3);
    cout << p.frente() << endl;
    cout << p.desenfileira() << endl;
    p.enfileira(4);
    while (p.tamanho() > 0)
    {
        cout << p.desenfileira() << endl;
    }
    p.libera();
    return 0;
}
