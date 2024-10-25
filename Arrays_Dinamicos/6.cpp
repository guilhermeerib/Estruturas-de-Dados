#include <iostream>
using namespace std;

class ArrayList
{
public:
    static const int MAX = 100;
    int N;
    int *list;
    bool error;

    // Construtor
    ArrayList()
    {
        list = new int[MAX];
        N = 0;
        error = false;
    }

    // Construtor de cópia
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

    // Destrutor
    ~ArrayList()
    {
        delete[] list;
        N = 0;
    }

    void adicionarFim(int dado)
    {
        cout << "\nInserindo elemento " << dado << " no fim da lista.\n";
        error = false;

        if (N >= MAX)
        {
            cout << "Limite de elementos atingidos;";
            error = true;
            return;
        }
        list[N] = dado;
        N++;
    }

    void imprimirLista()
    {
        if (N == 0)
        {
            cout << "Lista vazia.\n\n";
            return;
        }

        cout << "\nLista: ";

        for (int i = 0; i < N; i++)
        {
            cout << list[i] << ", ";
        }
        cout << "Fim\n"
             << endl;
    }

    // Função para rotacionar elementos
    void rotacionar(int k, bool direita)
    {
        if (N == 0)
            return;

        k = k % N; // Para evitar rotações desnecessárias
        if (direita)
            k = N - k; // Para rotacionar para a direita

        int *temp = new int[k];
        for (int i = 0; i < k; ++i)
        {
            temp[i] = list[i];
        }

        for (int i = 0; i < N - k; ++i)
        {
            list[i] = list[i + k];
        }

        for (int i = 0; i < k; ++i)
        {
            list[N - k + i] = temp[i];
        }

        delete[] temp;
    }
};

int main()
{
    ArrayList lista;
    lista.adicionarFim(10);
    lista.adicionarFim(20);
    lista.adicionarFim(30);
    lista.adicionarFim(40);
    lista.adicionarFim(50);

    cout << "Lista original:";
    lista.imprimirLista();

    // Rotacionar 2 posições para a esquerda
    lista.rotacionar(2, true);
    cout << "Lista após rotacionar 2 posições para a esquerda:";
    lista.imprimirLista();

    // Rotacionar 2 posições para a direita
    lista.rotacionar(2, true);
    cout << "Lista após rotacionar 2 posições para a direita:";
    lista.imprimirLista();

    return 0;
}
