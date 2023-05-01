/**
 * @file Playlist.h
 * @brief Arquivo header da classe Playlist.
 */

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

#include "Lista.h"  /**< Inclui a classe Lista. */
#include "Musica.h" /**< Inclui a classe Musica. */

using namespace std;

/**
 * @class Playlist
 * @brief Classe que representa uma playlist.
 */
class Playlist
{
private:
    string nome;          /*!< Nome da playlist */
    Lista<Musica> *lista; /*!< Lista ligada de músicas da playlist */
    int musicaTocando;    /*!< Ponteiro para a música tocando atualmente */

public:
    // Construtores
    Playlist(string);
    Playlist();

    // Destrutor
    ~Playlist();
    void limpar();

    // Gets
    string getNome();
    Lista<Musica> *getLista();

    // CRUD
    bool adicionarMusica(Musica);
    bool removerMusica(int);

    // Metodos da funcionalidade "tocando"
    No<Musica> *proximaMusica();

    // Impressão com recursão
    void imprimir();
    // Chamado pela função 'imprimir'
    void impressaoRecursiva(No<Musica> *, int);
};

#endif