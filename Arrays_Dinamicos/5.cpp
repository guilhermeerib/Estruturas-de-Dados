#include <iostream>

using namespace std;

class No
{
public:
    int dado;
    No *proximo;

    // construtores
    No(int dado)
    {
        this->dado = dado;
        this->proximo = nullptr;
    }

    ~No()
    {
        delete[] this->proximo;
        this->proximo = nullptr;
    };
};

class Circular
{

public:
    No *inicio;
    No *fim;
    int N;

    // construtores classe circular
    Circular()
    {
        inicio = nullptr;
        fim = nullptr;
        N = 0;
    };

    ~Circular()
    {
        delete[] inicio;
        delete[] fim;
        N = 0;
        // inicio = nullptr;
        // fim = nullptr;
    };

    // Metodos

    void adicionarFim(int dado)
    {
        No *novoNo = new No(dado);
        if (N == 0 && inicio == nullptr)
        {
            inicio = novoNo;
            fim = novoNo;
            N++;
            return;
        }

        // tamanho da Circular.N >=1
        novoNo->proximo = inicio;

        fim->proximo = novoNo;

        fim = novoNo;
        N++;
    } // adiciomar fim

    void imprimir()
    {
        if (this->N == 0)
        {
            cout << "\nLista Vazia. \n";
        }

        No *aux = inicio;
        cout << "\nLista Circular: Inicio, ";
        for (int i = 0; i < N*2; i++)
        {
            if (i==N)
            {
                cout << "Repetindo >> Inicio, ";
            }
            
            cout << aux->dado << ", ";
            aux = aux->proximo;
        }

        cout << "Inicio ...\n";
    }
};

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

    // Construtor de cópia
    // recebe uma refeencia ao objetio original
    // retorna a copia independente

    ArrayList(const ArrayList &a)
    {

        this->N = a.N;
        this->list = new int[MAX];
        for (int i = 0; i < a.N; i++)
        {
            this->list[i] = a.list[i];
        }
        this->error = a.error;

        cout << "\nConstrutor de copia. \n"
             << endl;
    }

    // destrutor (forma atual);
    ~ArrayList()
    {
        delete[] list;
        N = 0;
    };

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

    Circular converterArrayParaListaCircular()
    {
        Circular circular;
        for (int i = 0; i < N; i++)
        {
            // cout << list[i] << ", ";
            circular.adicionarFim(list[i]);
        }

        return circular;
    }

}; // fim da classe ArrayList;

int main()
{

    system("cls");
    ArrayList lista1;
    lista1.adicionarFim(10);
    lista1.adicionarFim(20);
    lista1.adicionarFim(30);
    lista1.adicionarFim(40);
    Circular listaCircular = lista1.converterArrayParaListaCircular();
    listaCircular.imprimir();

    return 0;
}
