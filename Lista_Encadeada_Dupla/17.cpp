#include <iostream>
#include <unordered_set>

using namespace std;

class No
{
public:
    int dado;
    No *proximo;
    No *anterior;

    No(int valor) : dado(valor), proximo(nullptr), anterior(nullptr) {}
};

class ListaDuplamenteEncadeada
{
public:
    class Iterador
    {
    public:
        No *no;
        bool reverso;

        Iterador(No *no_inicial, bool reverso) : no(no_inicial), reverso(reverso) {}

        int atual()
        {
            return no->dado;
        }

        bool terminou()
        {
            return no == nullptr;
        }

        void proximo()
        {
            if (no != nullptr)
            {
                no = no->proximo;
            }
        }

        void anterior()
        {
            if (no != nullptr)
            {
                no = no->anterior;
            }
        }
    };

    No *inicio;
    No *fim;
    int N;

    ListaDuplamenteEncadeada() : inicio(nullptr), fim(nullptr), N(0) {}

    ~ListaDuplamenteEncadeada()
    {
        while (inicio != nullptr)
        {
            No *temp = inicio;
            inicio = inicio->proximo;
            delete temp;
        }
    }

    // Metodos

    Iterador criar_iterador(bool reverso)
    {
        return Iterador(reverso ? fim : inicio, reverso);
    }

    Iterador busca(int dado, bool reverso)
    {
        Iterador it = criar_iterador(reverso);
        while (!it.terminou())
        {
            if (it.atual() == dado)
            {
                break;
            }
            if (!it.reverso)
            {
                it.proximo();
            }
            else
            {
                it.anterior();
            }
        }
        return it;
    }

    void adiciona_fim(int dado)
    {
        No *no = new No(dado);
        if (N == 0)
        {
            inicio = fim = no;
        }
        else
        {
            no->anterior = fim;
            fim->proximo = no;
            fim = no;
        }
        N++;
    }

    void remover_duplicados()
    {
        unordered_set<int> valores;
        No *atual = inicio;
        while (atual != nullptr)
        {
            if (valores.find(atual->dado) != valores.end())
            {
                No *temp = atual;
                if (atual->anterior != nullptr)
                {
                    atual->anterior->proximo = atual->proximo;
                }
                else
                {
                    inicio = atual->proximo;
                }
                if (atual->proximo != nullptr)
                {
                    atual->proximo->anterior = atual->anterior;
                }
                else
                {
                    fim = atual->anterior;
                }
                atual = atual->proximo;
                delete temp;
                N--;
            }
            else
            {
                valores.insert(atual->dado);
                atual = atual->proximo;
            }
        }
    }

    void imprimir_lista_esq_p_dir()
    {
        No *atual = inicio;
        while (atual != nullptr)
        {
            cout << atual->dado << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    // Função de particionamento
    pair<ListaDuplamenteEncadeada, ListaDuplamenteEncadeada> particionar(int pivot)
    {
        ListaDuplamenteEncadeada menores;
        ListaDuplamenteEncadeada maiores_ou_iguais;

        No *atual = inicio; // Começando do início da lista original
        while (atual != nullptr)
        {
            No *proximo = atual->proximo; // Guardar o próximo nó antes de modificar a lista

            if (atual->dado < pivot)
            {
                menores.adiciona_fim(atual->dado); // Adicionar o valor em 'menores'
            }
            else
            {
                maiores_ou_iguais.adiciona_fim(atual->dado); // Adicionar o valor em 'maiores ou iguais'
            }

            atual = proximo; // Avançar para o próximo nó
        }

        return make_pair(menores, maiores_ou_iguais); // Retornar as duas listas
    }
};

int main()
{
    system("cls");

    ListaDuplamenteEncadeada lista;

    lista.adiciona_fim(10);
    lista.adiciona_fim(20);
    lista.adiciona_fim(30);
    lista.adiciona_fim(40);
    lista.adiciona_fim(50);

    cout << "Lista original: ";
    lista.imprimir_lista_esq_p_dir();

    int pivot = 30;
    auto listas = lista.particionar(pivot);

    cout << "Lista com elementos menores que " << pivot << ": ";
    listas.first.imprimir_lista_esq_p_dir();

    cout << "Lista com elementos maiores ou iguais a " << pivot << ": ";
    listas.second.imprimir_lista_esq_p_dir();

    return 0;
}
