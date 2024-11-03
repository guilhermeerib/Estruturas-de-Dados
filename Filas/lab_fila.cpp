
#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

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
        std::fill(std::begin(elementos), std::end(elementos), 0);
    };
    void libera() {

    };

    int frente()
    {
        if (this->N == 0)
        {
            return -1;
        }

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
            //
        }
    };
    int desenfileira()
    {
        if (N > 0)
        {
            int front = this->elementos[0];
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
        return this->N;
    }
        bool vazia()
        {
            return N == 0;
        };

        void imprimirFila()
        {
            if (N > 0)
            {
                cout << "\n\nInicio da Fila: ";
                for (int i = 0; i < N; i++)
                {
                    cout << elementos[i] << ", ";
                }
                cout << "FIM\n\n";
            }
        }
    };

void testarFila(Fila &fila)
{
    int acertos = 0;
    int operacoesTotais = 0;

    // Vetor para simular o estado esperado da fila
    std::vector<int> estadoEsperado;

    // Array de operações
    std::string operacoes[] = {"enfileira", "desenfileira", "frente", "tamanho", "vazia"};
    // Semente para números aleatórios
    std::srand(std::time(0));
    int conta_insercao = 0;

    // Realizar 100 operações aleatórias
    for (int i = 0; i < 100; i++)
    {
        // Escolhe uma operação aleatória
        std::string operacao = operacoes[std::rand() % 5];

        if (operacao == "enfileira")
        {
            conta_insercao++;
            int cliente_id = std::rand() % 1000; // ID de cliente aleatório
            fila.enfileira(cliente_id);
            estadoEsperado.push_back(cliente_id); // Atualiza o estado esperado
            std::cout << "Operação: enfileira(" << cliente_id << ")\n";
        }
        else if (operacao == "desenfileira")
        {
            int resultadoFila = fila.desenfileira();
            int resultadoEsperado = estadoEsperado.empty() ? -1 : estadoEsperado.front();

            // Verifica se o resultado está correto
            if (resultadoFila == resultadoEsperado)
                acertos++;
            if (!estadoEsperado.empty())
                estadoEsperado.erase(estadoEsperado.begin()); // Remove o primeiro elemento

            std::cout << "Operação: desenfileira() -> Resultado: " << resultadoFila << ", Esperado: " << resultadoEsperado << "\n";
        }
        else if (operacao == "frente")
        {
            int resultadoFila = fila.frente();
            int resultadoEsperado = estadoEsperado.empty() ? -1 : estadoEsperado.front();

            // Verifica se o resultado está correto
            if (resultadoFila == resultadoEsperado)
                acertos++;
            std::cout << "Operação: frente() -> Resultado: " << resultadoFila << ", Esperado: " << resultadoEsperado << "\n";
        }
        else if (operacao == "tamanho")
        {
            int resultadoFila = fila.tamanho();
            int resultadoEsperado = estadoEsperado.size();

            // Verifica se o resultado está correto
            if (resultadoFila == resultadoEsperado)
                acertos++;
            std::cout << "Operação: tamanho() -> Resultado: " << resultadoFila << ", Esperado: " << resultadoEsperado << "\n";
        }
        else if (operacao == "vazia")
        {
            bool resultadoFila = fila.vazia();
            bool resultadoEsperado = estadoEsperado.empty();

            // Verifica se o resultado está correto
            if (resultadoFila == resultadoEsperado)
                acertos++;
            std::cout << "Operação: vazia() -> Resultado: " << (resultadoFila ? "true" : "false") << ", Esperado: " << (resultadoEsperado ? "true" : "false") << "\n";
        }

        operacoesTotais++;
    }

    // Calcula e imprime a taxa de acerto
    double taxaAcerto = (static_cast<double>(acertos) / (operacoesTotais - conta_insercao)) * 100;
    std::cout << "\nTaxa de acerto: " << taxaAcerto << "%\n";
}

int main()
{
    Fila filaSuporteTecnico;
    Fila filaPedidosLanchonete;

    std::cout << "Teste: Sistema de Atendimento de Suporte Técnico\n";
    testarFila(filaSuporteTecnico);

    std::cout << "\nTeste: Sistema de Fila de Pedidos em uma Lanchonete\n";
    testarFila(filaPedidosLanchonete);

    return 0;
}
