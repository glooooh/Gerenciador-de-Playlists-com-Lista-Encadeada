#ifndef LISTA_H
#define LISTA_H

#include <string>
#include <cstring>
using namespace std;

#include "No.h"

template <typename T>
class ListaMusica
{
public:
    No<T> *cabeca;
    No<T> *cauda;
    int tamanho;

public:
    // Construtores e desconstrutores
    ListaMusica()
    {
        this->cabeca = nullptr;
        this->cauda = nullptr;
        this->tamanho = 0;
    }

    ~ListaMusica()
    {
        cout << "CAIU" << endl;
    }

    // CRUDS
    void inserir(T data)
    {
        No<T> *nova = new No<T>(data);

        if (this->cauda == nullptr)
        {
            this->cabeca = nova;
            this->cauda = nova;
        }
        else
        {
            this->cauda->proximo = nova;
            this->cauda = nova;
        }
        this->tamanho++;
    }

    bool remover(int indiceParaRemover)
    {
        No<T> *noAtual, *noProximo, *noExcluido;
        noAtual = this->cabeca;
        noProximo = noAtual->proximo;

        // checa se a lista tem o tamanho menor que o índice
        if (indiceParaRemover > this->tamanho - 1)
        {
            return false;
        }

        // caso o ínice excluído seja a cabeça
        if (indiceParaRemover == 0)
        {
            // Definino que o nó a ser excluído é a cabeça
            noExcluido = this->cabeca;
            // Substituindo endereço da cabeça da lista
            this->cabeca = this->cabeca->proximo;

            // liberando célula desejada
            delete noExcluido;
            this->tamanho--;

            return true;
        }

        // caso o índice excluído seja a cauda
        if (indiceParaRemover == this->tamanho - 1)
        {
            // alterando endereço da célula anterior
            for (int i = 0; i != indiceParaRemover - 1; i++)
            {
                noAtual = noAtual->proximo;
            }

            noAtual->proximo = nullptr;

            // liberando célula desejada
            noExcluido = this->cauda;
            delete noExcluido;
            this->tamanho--;

            // alterando a cauda da lista para penúltima célula
            this->cauda = noAtual;

            return true;
        }

        // loop se repete até achar o indíce anterior ao que será excluído
        for (int i = 0; i != indiceParaRemover - 1; i++)
        {
            noAtual = noAtual->proximo;
            noProximo = noAtual->proximo;
        }

        // altera o endereço armazenado no índice para pular o que foi excluído
        noAtual->proximo = noProximo->proximo;

        // libera o espaço do índice que será excluído
        noExcluido = noProximo;
        delete noExcluido;
        this->tamanho--;

        return true;
    }

    // Função busca nó por índice e retorna o valor armazenado nele
    No<T> *buscarPorIndice(int indiceBuscado)
    {
        No<T> *noAtual;
        noAtual = this->cabeca;

        // checa se a lista tem o tamanho menor que o índice
        if (indiceBuscado > this->tamanho - 1)
        {
            return nullptr;
        }

        // loop se repete até achar o indíce buscado
        for (int i = 0; i != indiceBuscado; i++)
        {
            noAtual = noAtual->proximo;
        }

        return noAtual;
    }
};

#endif;

// A QUESTÃO PEDE:
// a) Crie métodos de inserção e remoção de elementos na lista
// b) Crie métodos de busca e acesso à elementos na lista
// c) Crie os construtores e destrutores correspondentes