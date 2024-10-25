#include <iostream>
#include <chrono>
#include <climits>
using namespace std;

class No
{
public:
    int dado;
    No *proximo;
    No *anterior;

    No(int dado)
    {
        this->dado = dado;
    }
};

class CircularDupla
{

public:
    No *inicio;
    No *fim;
    int N;

    CircularDupla()
    {
        inicio = nullptr;
        fim = nullptr;
        N = 0;
    };
    ~CircularDupla()
    {
        delete[] inicio;
        delete[] fim;
        N = 0;
    };

    void liberar()
    {
        if (inicio == nullptr)
        {
            return;
        }

        No *atual = inicio->proximo;
        No *proximo;
        while (atual != inicio)
        {
            proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
        delete inicio;
        this->inicio = nullptr;
        this->fim = nullptr;
        N = 0;
    }

    void adicionarInicio(int valor)
    {
        No *novoNo = new No(valor);
        if (inicio == nullptr && N == 0)
        {
            novoNo->proximo = novoNo;
            novoNo->anterior = novoNo;

            this->inicio = novoNo;
            this->fim = novoNo;
        }
        else
        {
            this->inicio->anterior = novoNo;
            novoNo->anterior = fim;
            novoNo->proximo = inicio;
            this->fim->proximo = novoNo;
            this->inicio = novoNo;
        }
        this->N++;
        return;
    }
    void adicionarFim(int valor)
    {
        No *novoNo = new No(valor);
        if (inicio == nullptr)
        {
            novoNo->proximo = novoNo;
            novoNo->anterior = novoNo;
            this->inicio = novoNo;
            this->fim = novoNo;
            this->fim->proximo = inicio;
            this->N++;
            return;
        }

        novoNo->proximo = inicio;
        novoNo->anterior = fim;
        this->fim->proximo = novoNo;
        this->fim = novoNo;
        this->N++;
    }

    void adicionarMuitos(int quantidade)
    {
        for (int i = 0; i < quantidade; i++)
        {
            adicionarFim(i);
        }
    }

    void removerInicio()
    {
        if (inicio == nullptr)
        {
            cout << "Remover No inicial,\n Erro: Lista Vazia.\n";
        }
        No *novoInicio = this->inicio->proximo;
        novoInicio->anterior = fim;
        No *del = inicio;
        this->fim->proximo = novoInicio;
        this->inicio = novoInicio;
        delete del;

        N--;
    }

    void removerFinal()
    {
        if (inicio == nullptr)
        {
            cout << "\nErro ao remover ultimo elemento da lista circular, Lista vazia.\n";
            return;
        }

        //  fim<< 1(inicio),2,3,4(fim) >>inicio
        No *del = fim;
        No *aux = fim->anterior;
        aux->proximo = inicio;
        inicio->anterior = aux;
        fim = fim->anterior;
        delete del;
        N--;
    }

    void removerIdx() {}
    void removerValor(int valor)
    {
        if (inicio == nullptr)
        {
            return;
        }

        No *atual = inicio;

        while (atual->dado != valor)
        {
            atual = atual->proximo;
        }

        //  fim<< 1(inicio),2,3,4(fim) >>inicio
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
        delete atual;
        N--;
    }

    void removerTodosValores() {}

    void imprimir(bool dir = true)
    {
        if (inicio == nullptr && N == 0)
        {
            cout << "\nLista Vazia.\n ";
            return;
        }
        cout << "\nTamanho da Lista: " << this->N;

        cout << "\nLista: Inicio, ";

        No *temp;
        int qtd = N * 2;

        // imprime do inicio para o fim;
        if (dir == true)
        {
            temp = inicio;
            for (int i = 0; i < qtd; i++)
            {
                if (N == i)
                {
                    cout << "Repetindo >> Inicio, ";
                }

                cout << temp->dado << ", ";
                temp = temp->proximo;
            }
        }
        else
        {
            // imprime do fim para o inicio;
            temp = fim;
            for (int i = 0; i < qtd; i++)
            {
                if (N == i)
                {
                    cout << "Repetindo >>, Inicio, ";
                }
                cout << temp->dado << ", ";
                temp = temp->anterior;
            }
        }

        cout << "inicio ...\n\n";
    }

    void reportListaCircularDupla(int quantidade)
    {
        cout << "\n Relatorio da Lista Circular dupla.\n";
        auto start = chrono::high_resolution_clock::now();
        CircularDupla circular;
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Tempo para criar a lista: "
             << duration.count()
             << " microsegundos"
             << endl;

        start = chrono::high_resolution_clock::now();

        circular.adicionarMuitos(quantidade);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Tempo adicionar "
             << duration.count()
             << " microsegundos"
             << endl;

        start = chrono::high_resolution_clock::now();
        circular.liberar();
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Tempo limpar a lista: "
             << duration.count()
             << " microsegundos\n"
             << endl;
    }

}; // fim da classe circular dupla

int main()
{
    system("cls");
    // int quantidade = INT_MAX/30;
    // std::cout << "Quantidade de itens criados: " << quantidade << std::endl;
    CircularDupla circular;
    circular.imprimir(false);
    // circular.reportListaCircularDupla(quantidade);

    // circular.adicionarMuitos(4);
    // circular.removerInicio();

    // circular.imprimir(false);

    // adicionarInicio
    // circular.liberar();
    // circular.adicionarInicio(10);
    // circular.adicionarInicio(20);
    // circular.adicionarInicio(30);
    // circular.adicionarInicio(40);
    // circular.adicionarInicio(50);
    // circular.removerInicio();
    // circular.imprimir(true);

    circular.liberar();
    circular.adicionarFim(10);
    circular.adicionarFim(20);
    circular.adicionarFim(30);
    circular.adicionarFim(40);
    circular.adicionarFim(50);
    // circular.removerInicio();
    circular.removerValor(20);

    circular.imprimir();

    return 0;
}
