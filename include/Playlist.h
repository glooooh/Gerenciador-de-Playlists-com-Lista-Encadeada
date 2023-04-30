/**
 * @file Playlist.h
 * @brief Arquivo header da classe Playlist.
 */

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
using namespace std;

#include "Lista.h"

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

    void setNome(string);

    // CRUD
    bool adicionarMusica(Musica);
    bool removerMusica(int);

    // Metodos da funcionalidade "tocando"
    No<Musica> *proximaMusica();

    // Impressão com recursão
    void imprimir();
    // Chamado pela função imprimir()
    void impressaoRecursiva(No<Musica> *, int);
};

#endif