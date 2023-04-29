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
    this->musicaTocando = 0;
}

/**
 * @brief Construtor padrão da classe Playlist.
 */
Playlist::Playlist() {
    this->nome = "";
    this->lista = new Lista<Musica>();
    musicaTocando = 0;
}

/**
 * @brief Destrutor da classe Playlist.
 */
Playlist::~Playlist()
{
    
}

void Playlist::limpar() {
    this->lista->~Lista();
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
 * @brief Define um nome para a playlist.
 */
void Playlist::setNome(string n)
{
    nome = n;
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
void Playlist::proximaMusica()
{
    if (this->lista->tamanho <= 0)
    {
        cout << "A PLAYLIST NAO POSSUI MUSICAS" << endl;
        return;
    }

    No<Musica> *celula = new No<Musica>;
    // caso seja a primeira vez tocando a playlist ou a playlist chegou à última música
    if (this->musicaTocando == this->lista->tamanho)
    {
        cout << "A PLAYLIST IRA RECOMECAR!" << endl;
        this->musicaTocando = 0;
    }

    celula = this->lista->buscarPorIndice(musicaTocando);

    cout << "Musica tocando agora: " << celula->data.getTitulo() << endl;

    // padrão (existe uma próxima música e ela será tocada)
    this->musicaTocando++;
    return;
}

/**
 * @brief Imprime as músicas da playlist.
 */
void Playlist::imprimir()
{
    if (this->lista->cabeca == nullptr)
    {
        cout << "A Playlist esta vazia!" << endl;
        return;
    }

    impressaoRecursiva(this->lista->cabeca, 0);

    return;
}

/**
 * @brief Função auxiliar para imprimir as músicas da playlist recursivamente.
 * @param celula é a célula atual da lista encadeada.
 */
void Playlist::impressaoRecursiva(No<Musica> *celula, int indice)
{
    cout << indice + 1 << ". '" << celula->data.getTitulo() << "' de " << celula->data.getArtista() << endl;

    if (celula->proximo != nullptr)
    {
        indice++;
        impressaoRecursiva(celula->proximo, indice);
    }

    return;
}