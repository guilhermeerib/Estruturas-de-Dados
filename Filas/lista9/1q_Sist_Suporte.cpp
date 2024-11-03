#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

constexpr int MAXN = 100;
class Fila
{
public:
    int elementos[MAXN];
    int N;
    void cria()
    {
        this->N = 0;
    };
    void libera() {

    };

    int frente()
    {
        return elementos[0];
    }

    void enfileira(int cliente_id)
    {
        if (N < MAXN)
        {
            elementos[N] = cliente_id;
            N++;
        }
        else
        {
            cout << "\nLimite de clientes atingido. \n";
        }
    };
    int desenfileira()
    {
        if (N > 0)
        {
            int front = elementos[0];
            for (int i = 1; i < N; i++)
            {
                elementos[i - 1] = elementos[i];
            }
            N--;
            // cout << "Cliente " << front << ", atendido e removido\n";
            return front;
        }
        else
        {
            // Queue is empty, handle accordingly
            return -1;
        };
    }
    int tamanho()
    {
        if (this->N)
        {
            return this->N;
        }

        return 0;
    };
    bool vazia()
    {
        return N == 0;
    };

    void imprimirFila()
    {
        if (N > 0)
        {
            cout << "\n\n Pedidos agendados: ";
            for (int i = 0; i < N; i++)
            {
                cout << elementos[i] << ", ";
            }
            cout << "FIM\n\n";
        }
    }
};

int main()
{

    cout << "\nSistema de Atendimento de Suporte Técnico\n";
    cout << "Iniciando sistema: \n";
    Fila fila;
    fila.cria();

    cout << "Quantidade de agendamentos: " << fila.tamanho() << "\n";

    for (int i = 1; i < 11; i++)
    {
        cout << "Adicionar cliente " << i << "\n";
        fila.enfileira(i);
    }
    fila.imprimirFila();

    while (!fila.vazia())
    {
        cout << "\nProximo Cliente: " << fila.frente() << "\n";
        cout << "Atender Cliente " << fila.desenfileira() << "\n";
        cout << "Tamanho da fila: " << fila.tamanho() << "\n";
        fila.imprimirFila();
    }

    cout << "Sistema encerrado";
    return 0;
}
