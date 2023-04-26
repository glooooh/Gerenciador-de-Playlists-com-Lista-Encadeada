#ifndef LISTA_H
#define LISTA_H

#include <string>
using namespace std;

#include "No.h"

class ListaMusica
{
public:
    No *cabeca;
    No *cauda;
    int tamanho;

    // Construtores e desconstrutores
    ListaMusica();
    ~ListaMusica();

    // CRUDS
    void inserir(Musica);
    bool remover(int);

    // Função buscar por índice
    No *buscarPorIndice(int);
};

#endif;

// A QUESTÃO PEDE:
// a) Crie métodos de inserção e remoção de elementos na lista
// b) Crie métodos de busca e acesso à elementos na lista
// c) Crie os construtores e destrutores correspondentes