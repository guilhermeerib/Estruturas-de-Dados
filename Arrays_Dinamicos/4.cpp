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

    static ArrayList criaCopiaConstante(ArrayList array)
    {
        cout << "Funcao para gerar copia. \n";
        return array;
    }

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
    ArrayList lista1;
    lista1.adicionarFim(10);
    lista1.adicionarFim(20);
    lista1.adicionarFim(30);
    lista1.adicionarFim(40);
    // lista1.imprimirLista();

    // usando o método estatico da classe que usa o construtor de copia
    cout << "Criando Lista2 (metodo copia) ";
    ArrayList lista2 = ArrayList::criaCopiaConstante(lista1);
    lista2.imprimirLista();
    
    // usando o construtor de cópia diretamente
    cout << "Criando Lista3 (construtor copia diretamente) ";

    ArrayList lista3 = ArrayList(lista2);
    lista3.imprimirLista();

    return 0;
}
