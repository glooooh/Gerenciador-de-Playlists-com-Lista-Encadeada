#include <iostream>
#include <string>
#include <cstring>

using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::string;

#include "ListaMusica.h"

// Construtor
ListaMusica::ListaMusica()
{
    this->cabeca = nullptr;
    this->cauda = nullptr;
    this->tamanho = 0;
}

// Destrutor
ListaMusica::~ListaMusica()
{
    cout << "CAIU" << endl;
}

// Funções CRUD
void ListaMusica::inserir(Musica m)
{
    No *nova = new No(m);

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

bool ListaMusica::remover(int indiceParaRemover) {
    No *noAtual, *noProximo, *noExcluido;
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
        free(noExcluido);
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
        free(noExcluido);
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
    free(noExcluido);
    this->tamanho--;

    return true;
}

// Função busca nó por índice e retorna o valor armazenado nele
No *ListaMusica::buscarPorIndice(int indiceBuscado)
{
    No *noAtual;
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