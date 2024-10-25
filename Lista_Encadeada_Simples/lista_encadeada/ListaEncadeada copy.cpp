#include <iostream>
// #include "ListaEncadeada.h"

using namespace std;
// using namespace std;

class No
{
public:
    int dado;
    No *proximo;

    No(int valor) : dado(valor), proximo(nullptr) {};
};

class ListaEncadeada
{
public:
    No *cabeca;
    ListaEncadeada() : cabeca(nullptr) {};

    // 1 questao da lista4
    void adiciona_calda(int valor)
    {

        cout << "Adicionando valor: " << valor << " no fim da lista";
        No *novoNo = new No(valor);

        if (cabeca == nullptr)
        {
            cabeca = novoNo;
        }
        else
        {
            No *temp = cabeca;
            while (temp->proximo != nullptr)
            {
                temp = temp->proximo;
            }
            temp->proximo = novoNo;
        }

        imprimir_lista();
    }

    // 2 questao da lista4
    void adiciona_cabeca(int valor)
    {
        cout << "Adicionando valor: " << valor << " no inicio";

        No *novoNo = new No(valor);
        novoNo->proximo = cabeca;
        cabeca = novoNo;

        imprimir_lista();
    }

    // 5 questao da lista4
    void adiciona_posicao(int valor, int posicao)
    {
        cout << "Inserindo valor: " << valor << " na posicao: " << posicao << endl;
        No *novoNo = new No(valor);

        if (posicao == 0)
        {
            novoNo->proximo = cabeca;
            cabeca = novoNo;
            return;
        }

        No *temp = cabeca;

        for (int i = 0; temp != nullptr && i < posicao - 1; i++)
        {
            temp = temp->proximo;
            // cout << "iteracao: " << i << endl;
        }

        if (temp == nullptr)
        {
            cout << "A posicao fornecida e invalida." << endl;
            delete novoNo;
            return;
        }

        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;

        imprimir_lista();
    }

    void imprimir_lista()
    {
        cout << "\nlista: ";
        if (cabeca == nullptr)
        {
            cout << "vazia!\n\n";
            return;
        }

        No *temp = cabeca;

        while (temp != nullptr)
        {
            // imprimir valor atual
            cout << temp->dado << ", ";
            // ir para o proximo valor
            temp = temp->proximo;
        }
        // fim da lista
        cout << "null\n\n";
    }

    void remover_no(int valor)
    {
        // a lista esta vazia;
        if (cabeca != nullptr)
        {
            return;
        }

        // o valor esta no primeiro no
        if (cabeca->dado == valor)
        {
            No *temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
            return;
        }

        No *atual = cabeca;

        // para quando encontrar o anterior ao valor a ser apagado
        while (atual->proximo != nullptr && atual->proximo->dado != valor)
        {
            No *temp = atual->proximo;
            atual = atual->proximo;
            delete temp;
        }

        // atual->dado == valor // valor a ser removido;
        if (atual->proximo != nullptr)
        {
            No *temp = atual->proximo;
            atual->proximo = atual->proximo->proximo;
            delete temp;
        }

        imprimir_lista();
    }

    //
    string busca_valor(int valor)
    {
        No *temp = cabeca;

        while (temp != nullptr)
        {
            if (temp->dado == valor)
            {
                return "Valor" + to_string(valor) + "foi encontrado";
            }

            temp = temp->proximo;
        }
        return "Valor" + to_string(valor) + " Nao Encontrado";
    }

    void remover_calda()
    {
        cout << "Removendo ultimo elemento da lista: ";

        // lista vazia;
        if (cabeca == nullptr)
        {
            cout << "Lista vazia...";
            return;
        }

        // So existe um valor na lista
        if (cabeca->proximo == nullptr)
        {

            cout << "Removendo o valor: " << cabeca->dado << endl;

            delete cabeca;
            cabeca = nullptr;

            imprimir_lista();
            return;
        }

        // mais de um elemento na lista
        No *temp = cabeca;
        // percorrer até o ultimo elemento da lista
        while (temp->proximo->proximo != nullptr)
        {
            temp = temp->proximo;
        }
        cout << temp->proximo->dado;
        delete temp->proximo;
        temp->proximo = nullptr;

        imprimir_lista();
    }

    void inverter_lista()
    {
        cout << "Invertendo a lista atual. \n\n" ;
        if (cabeca == nullptr)
        {
            cout << "Lista Vazia";
        }

        No *anterior = nullptr;
        No *atual = cabeca;
        No *proximo = nullptr;
        while (atual != nullptr)
        {
            proximo = atual->proximo;
            atual->proximo = anterior;
            anterior = atual;
            atual = proximo;
        }

        cabeca = anterior;

        imprimir_lista();
    }

}; // fim da classe ListaEncadeada 

void pontoDeParada()
{
    // Função vazia para ponto de parada
}

int main()
{
    system("cls");
    ListaEncadeada lista;
    lista.imprimir_lista();
    // Inserindo nos
    lista.adiciona_calda(10);
    lista.adiciona_calda(20);
    lista.adiciona_calda(30);
    lista.adiciona_calda(40);
    lista.adiciona_calda(999);

    // pontoDeParada();
    // Removendo o último elemento
    // lista.remover_calda();

    // inverter lista
    lista.inverter_lista();

    return 0;
}
