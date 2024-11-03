#include <iostream>

using namespace std;

constexpr int MAXN = 100;

class Fila
{

public:
    int elementos[MAXN];
    int N;
    void cria () {
        this->N =0;
    };
    void libera () {

    };

    int frente() 
    {
        return elementos[0];
    }

    void enfileira(int dado){
        if (N<MAXN)
        {
            elementos[N]=dado;
            N++;
        }else{
            //
        }
        

    };
    int desenfileira () {
        if (N>0)
        {
            int front = elementos[0];
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
    bool vazia(){
        return N==0;

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
    cout << "Fila Vazia: "<< fila.vazia();
    fila.enfileira(1);
    fila.enfileira(2);
    fila.enfileira(1);
    fila.enfileira(2);
    fila.enfileira(1);
    fila.enfileira(2);
    fila.imprimirFila();
    cout << "Fila Vazia: " << fila.vazia();

    return 0;
}
