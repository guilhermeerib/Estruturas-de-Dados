/*
3. Implemente uma função que concatena dois arrays dinâmicos,
 criando um novo array com todos
os elementos dos dois arrays originais.
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

    static ArrayList concatenar(const ArrayList &lista1, const ArrayList &lista2)
    {
        cout << "Concatenando listas ...\n";

        ArrayList lista_concatenada;

        for (int i = 0; i < (lista1.N); i++)
        {

            // lista_concatenada.adicionarFim(lista1.list[i]); // forma mais fácil
            lista_concatenada.list[i] = lista1.list[i];
            lista_concatenada.N++;
        }

        for (int i = 0; i < (lista2.N); i++)
        {

            // lista_concatenada.adicionarFim(lista2.list[i]); //forma mais fácil
            lista_concatenada.list[lista1.N + i] = lista2.list[i];
            lista_concatenada.N++;
        }

        return lista_concatenada;
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

    ArrayList lista2;
    lista2.adicionarFim(50);
    lista2.adicionarFim(60);
    lista2.adicionarFim(70);
    lista2.adicionarFim(80);

    ArrayList lista_concatenada = ArrayList::concatenar(lista1, lista2);

    lista_concatenada.imprimirLista();
    return 0;
}
