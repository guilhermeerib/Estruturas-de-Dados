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
    }

    void adicionarFim(int dado)
    {
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

    void adicionarEm(int dado, int idx)
    {
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
    };

    void removerInicio()
    {
        error = false;
        if (N == 0)
        {
            error = false;
            throw("Remocao errada, Lista vazia;");
            return;
        }

        int *aux = &list[0];
        for (int i = 0; i < N - 1; i++)
        {
            list[i] = list[i + 1];
        }
        delete aux;
        N--;

    }; // fim removerInicio

    void removerFinal()
    {
        error = false;

        if (N == 0)
        {
            error = true;
            cout << "Erro na remocao, lista vazia \n";
            return;
        };

        N--;

    }; // fim removerFinal

    int removeEm(int idx)
    {
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

}; // fim da classe ArrayList;

int main()
{
    ArrayList list;
    list.cria();
    list.adicionarInicio(10);
    list.buscaIndice(10);
    list.adicionarEm(999, 1);
    list.removerInicio();
    list.adicionarInicio(20);
    list.adicionarInicio(30);
    list.adicionarInicio(40);
    list.adicionarFim(10);
    list.adicionarFim(20);
    list.adicionarFim(30);
    list.adicionarFim(40);
    list.adicionarEm(10, 1);
    list.adicionarEm(20, 3);
    list.adicionarEm(30, 5);
    list.adicionarEm(40, 7);
    return 0;
}
