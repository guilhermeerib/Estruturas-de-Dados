#include <iostream>
#include "ListaEncadeada.h"

using namespace std;
using namespace std;

ListaEncadeada::ListaEncadeada() : cabeca(nullptr) {}

// 1 questao da lista4
void ListaEncadeada::adiciona_calda(int valor)
{
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
}

// 2 questao da lista4
void ListaEncadeada::adiciona_cabeca(int valor)
{
    No *novoNo = new No(valor);
    novoNo->proximo = cabeca;
    cabeca = novoNo;
}

// 5 questao da lista4
void ListaEncadeada::adiciona_posicao(int valor, int posicao)
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

void ListaEncadeada::imprimir_lista()
{
    No *temp = cabeca;
    cout << endl;
    while (temp->proximo != nullptr)
    {
        cout << temp->dado << " ";
        temp = temp->proximo;
    }
    cout << "nullptr" << endl;
}

void ListaEncadeada::remover_no(int valor)
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

string ListaEncadeada::busca_valor(int valor)
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

void ListaEncadeada::remover_calda()
{

    // lista vazia;
    if (cabeca == nullptr)
    {
        cout << "Lista vazia...";
        return;
    }

    No *temp = cabeca;

    // percorrer até o ultimo elemento da lista
    while (temp->proximo != nullptr)
    {
        temp = temp->proximo;
    }

    delete temp;

    imprimir_lista();
}