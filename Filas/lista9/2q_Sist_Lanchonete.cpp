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

    bool filaVazia()
    {
        return this->N == 0;
    }

    int totalPedidos()
    {
        return N;
    }

    int proximoPedido()
    {
        if (filaVazia())
        {
            erro = 1;
            return -1;
        }
        erro = 0;
        return this->p_inicio->dado;
    }

    void libera()
    {
        while (!filaVazia())
        {
            processaPedido();
        }
    }

    void adicionaPedido(int dado)
    {
        erro = 0;
        No *novo = new No();
        novo->dado = dado;
        novo->prox = nullptr;
        if (filaVazia())
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

    int processaPedido()
    {
        erro = 0;
        if (filaVazia())
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

    void imprimirFila()
    {

        cout << "Fila de pedidos: ";

        No *temp = this->p_inicio;
        while (temp != nullptr)
        {

            cout << temp->dado << ", ";
            temp = temp->prox;
        }
        cout << "FIM\n\n";
    }
};

int main()
{
    cout << "\nSistema de Atendimento de Suporte Técnico\n";

    FilaEncadeada fila;
    cout << "Iniciar atendimentos.\n";
    fila.cria();

    cout << "Adicionar Pedido 101\n";
    fila.adicionaPedido(101);

    cout << "Adicionar Pedido 202\n";
    fila.adicionaPedido(202);

    cout << "Adicionar Pedido 303\n";
    fila.adicionaPedido(303);
    fila.imprimirFila();

    cout << "\nProximo Cliente: " << fila.proximoPedido() << "\n";
    cout << "Atender Cliente " << fila.processaPedido() << "\n";
    cout << "Tamanho da fila: " << fila.totalPedidos() << "\n";
    fila.imprimirFila();

    cout << "\nProximo Cliente: " << fila.proximoPedido() << "\n";
    cout << "Atender Cliente " << fila.processaPedido() << "\n";
    cout << "Tamanho da fila: " << fila.totalPedidos() << "\n";
    fila.imprimirFila();

    cout << "\nProximo Cliente: " << fila.proximoPedido() << "\n";
    cout << "Atender Cliente " << fila.processaPedido() << "\n";
    cout << "Tamanho da fila: " << fila.totalPedidos() << "\n";
    fila.imprimirFila();

    cout << "Sistema Encerrado.\n";
    return 0;
}
