/**
 * @file Playlist.cpp
 * @brief Implementação dos métodos da classe Playlist
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#include "Playlist.h"

/**
 * @brief Construtor da classe Playlist.
 * @param nome é o nome da playlist.
 */
Playlist::Playlist(string n)
{
    this->nome = n;
    this->lista = new Lista<Musica>();
    this->musicaTocando = nullptr;
}

/**
 * @brief Construtor padrão da classe Playlist.
 */
Playlist::Playlist() {}

/**
 * @brief Destrutor da classe Playlist.
 */
Playlist::~Playlist()
{
    delete lista;
    delete musicaTocando;
}

/**
 * @brief Retorna o nome da playlist.
 * @return o nome da playlist.
 */
string Playlist::getNome()
{
    return nome;
}

/**
 * @brief Retorna a lista de músicas da playlist.
 * @return a lista de músicas da playlist.
 */
Lista<Musica> *Playlist::getLista()
{
    return lista;
}

/**
 * @brief Adiciona uma música à playlist.
 * @param musica é a música a ser adicionada.
 * @return true se a música foi adicionada com sucesso.
 */
bool Playlist::adicionarMusica(Musica m)
{
    this->lista->inserir(m);
    return true;
}

/**
 * @brief Remove uma música da playlist.
 * @param indice é o índice da música a ser removida.
 * @return true se a música foi removida com sucesso, false caso contrário.
 */
bool Playlist::removerMusica(int indice)
{
    bool statusOperacao;
    statusOperacao = this->lista->remover(indice);
    return statusOperacao;
}

/**
 * @brief Toca a próxima música da playlist.
 * @return a próxima música da playlist.
 */
Musica Playlist::proximaMusica()
{
    // caso seja a primeira vez tocando a playlist ou a playlist chegou à última música
    if (this->musicaTocando == nullptr || this->musicaTocando->proximo == nullptr)
    {
        this->musicaTocando = this->lista->cabeca;

        if (this->musicaTocando != nullptr)
        {
            cout << "A PLAYLIST IRÁ RECOMEÇAR!" << endl;
        }

        return this->musicaTocando->data;
    }

    // padrão (existe uma próxima música e ela será tocada)
    this->musicaTocando = this->musicaTocando->proximo;
    return this->musicaTocando->data;
}

/**
 * @brief Imprime as músicas da playlist.
 */
void Playlist::imprimir()
{
    if (this->lista->cabeca == nullptr)
    {
        cout << "A Playlist está vazia!" << endl;
        return;
    }

    impressaoRecursiva(this->lista->cabeca);

    return;
}

/**
 * @brief Função auxiliar para imprimir as músicas da playlist recursivamente.
 * @param celula é a célula atual da lista encadeada.
 */
void Playlist::impressaoRecursiva(No<Musica> *celula)
{
    cout << "Título da música:" << celula->data.getTitulo() << endl
         << "Artista:" << celula->data.getArtista() << endl;

    if (celula->proximo != nullptr)
    {
        impressaoRecursiva(celula->proximo);
    }

    return;
}