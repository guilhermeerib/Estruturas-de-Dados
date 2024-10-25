#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <lista_encadeada/No.h>;

class ListaEncadeada
{
private:
    

public:
    No *cabeca;
    ListaEncadeada();
    void adiciona_calda(int valor) {};
    void adiciona_cabeca(int valor) {};
    void imprimir_lista() {};
    void remover_no(int valor) {};
    string busca_valor(int valor) {};
    void adiciona_posicao(int valor, int posicao) {};
    void remover_calda() {};
    void inverter_lista() {};
    void obter_quantidade_lista() {};
    void remover_duplicados() {};
    void ordenar_duas_lista_em_uma(ListaEncadeada lista1, ListaEncadeada lista2);
    void converter_em_lista_circular(ListaEncadeada lista);
    void concatenar_duas_listar(ListaEncadeada lista1, ListaEncadeada lista2);
    void separa_par_impar(ListaEncadeada &lista_par, ListaEncadeada &lista_impar);
};

#endif // LINKEDLIST_H