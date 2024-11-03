#include <iostream>

using namespace std;

constexpr int MAXN = 100;

class Fila
{

public:
    char elementos[MAXN];
    int N;
    void cria () {
        this->N =0;
    };
    void libera () {

    };

    char frente() 
    {
        return elementos[0];
    }

    void enfileira(char dado){
        if (N<MAXN)
        {
            elementos[N]=dado;
            N++;
        }else{
            //
        }
        

    };
    char desenfileira () {
        if (N>0)
        {
            char front = elementos[0];
        for (int i = 0; i < N; i++)
        {
            elementos[i-1] =elementos[i];
        }
        N--;
        return front;
        }else{

        }
        
        
    };
    int tamanho() {
        if (this->N)
        {
            return this->N;
            
        }
        
        return 0;
    };

    void imprimirFila(){
        if(N>0){
            cout << "\n\nInicio da Fila: ";
            for (int i = 0; i < N; i++)
            {
                cout << elementos[i] << ", "
                ;
            }
            cout << "FIM\n\n";
            
        }
    }
};

int main()
{
    Fila fila;
    fila.cria();
    fila.enfileira('a');
    fila.enfileira('b');
    fila.enfileira('c');
    fila.enfileira('d');
    fila.enfileira('e');
    fila.enfileira('f');
    fila.imprimirFila();
    return 0;
}
