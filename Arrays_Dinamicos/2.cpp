/*
2. Implemente as seguintes operações em um array dinâmico que simula uma lista:
a) Inserir um elemento no início da lista.
b) Inserir um elemento no final da lista.
c) Inserir um elemento em uma posição específica da lista.
d) Remover o primeiro elemento da lista.
e) Remover o último elemento da lista.
f) Remover um elemento em uma posição específica da lista.
 */

#include <iostream>

using namespace std;

class ArrayList
{

public:
    static const int MAX = 100;
    int N;
    int *list;
    bool error;

    // construtor
    ArrayList()
    {
        list = new int[MAX];
        N = 0;
        error = false;
    }
    // mesma coisa que
    void cria()
    {
        list = new int[MAX];
        N = 0;
        error = false;
    }

    // destrutor (forma atual);
    ~ArrayList()
    {
        delete[] list;
        N = 0;
    };

    // destrutor manual (forma obsoleta)
    void libera()
    {
        delete[] list;
        N = 0;
    }

    void adicionarInicio(int dado)
    {
        cout << "\nInserindo elemento "
             << dado
             << " no inicio da lista.\n";
             
        error = false;
        if (N >= MAX)
        {
            cout << "Limite de elementos atingidos;";
            error = true;
            return;
        }

        for (int i = N; i > 0; i--)
        {
            list[i] = list[i - 1];
        }
        list[0] = dado;
        N++;

        imprimirLista();
    }

    void adicionarFim(int dado)
    {
        cout << "\nInserindo elemento "
             << dado
             << " no fim da lista.\n";
        error = false;

        if (N >= MAX)
        {
            cout << "Limite de elementos atingidos;";
            error = true;
            return;
        }
        list[N] = dado;
        N++;

        imprimirLista();
    }

    void adicionarEm(int dado, int idx)
    {
        cout << "\nInserindo elemento "
             << dado
             << " no indice "
             << idx
             << " da lista.\n";
        error = false;

        if (N >= MAX || idx < 0 || idx > N)
        {
            cout << "Erro ao inserir na posicao: " << idx << endl;
            error = true;
            return;
        }

        // Desloca os elementos para a direita a partir de N
        for (int i = N; i > idx; i--)
        {
            list[i] = list[i - 1];
        }

        // Insere o novo dado no valor desejado;
        list[idx] = dado;
        // incrementa o numero de elementos
        N++;

        imprimirLista();
    };

    void removerInicio()
    {
        cout << "\nRemovendo elemento no inicio da lista.";
        error = false;
        if (N == 0)
        {
            error = false;
            throw("Remocao errada, Lista vazia;");
            return;
        }

        for (int i = 0; i < N - 1; i++)
        {
            list[i] = list[i + 1];
        }

        N--;
        imprimirLista();

    }; // fim removerInicio

    void removerFinal()
    {

        cout << "Removendo elemento no final da lista.";
        error = false;

        if (N == 0)
        {
            error = true;
            cout << "Erro na remocao, lista vazia \n";
            return;
        };

        N--;

        imprimirLista();

    }; // fim removerFinal

    int removerEm(int idx)
    {
        cout << "Removendo elemento no indice "
             << idx
             << " da lista.";

        error = false;
        if (idx < 0 || idx > N - 1 || N == 0)
        {
            error = true;
            return 0;
        }

        int dado = list[idx];
        for (int i = idx; i < N; i++)
        {
            list[i] = list[i + 1];
        }
        N--;
        imprimirLista();
        return dado;

    } // fim removerEm();

    // Retorna o indice em que o argumento foi achadao
    int buscaIndice(int dado)
    {

        for (int i = 0; i < N; i++)
        {
            if (list[i] == dado)
            {
                return i;
            }
        }
        return -1;
    } // fim da Busca()

    void imprimirLista()
    {

        if (N == 0)
        {
            cout << "Lista vazia.\n\n";
        }

        cout << "\nLista: ";

        for (int i = 0; i < N; i++)
        {
            cout << list[i] << ", ";
        }
        cout << "Fim\n"
             << endl;
    }

}; // fim da classe ArrayList;

int main()
{

    system("cls");
    ArrayList list;
    list.cria();
    list.adicionarInicio(10);
    list.adicionarFim(20);
    list.adicionarEm(999, 2);
    list.adicionarFim(30);
    list.adicionarEm(999, 4);
    list.adicionarFim(40);
    list.removerInicio();
    list.removerFinal();
    list.removerEm(4);
    // list.removerInicio();

    return 0;
}
