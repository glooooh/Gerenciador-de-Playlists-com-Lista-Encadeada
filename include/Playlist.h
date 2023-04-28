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
    string nome;               /*!< Nome da playlist */
    Lista<Musica> *lista;      /*!< Lista ligada de músicas da playlist */
    No<Musica> *musicaTocando; /*!< Ponteiro para a música tocando atualmente */

public:
    //Construtores
    Playlist(string);
    Playlist();
    
    //Destrutor
    ~Playlist();

    // Gets
    string getNome();
    Lista<Musica> *getLista();

    // CRUD
    bool adicionarMusica(Musica);
    bool removerMusica(int); 

    // Metodos da funcionalidade "tocando"
    Musica proximaMusica();

    // Impressão com recursão
    void imprimir();
    //Chamado pela função imprimir()
    void impressaoRecursiva(No<Musica> *celula);
};

#endif;

// a) Crie os construtores e destrutores correspondentes à classe
// b) Crie métodos de adição e remoção de músicas à uma playlist (músicas devem ser
// armazenadas em uma lista ligada)
// c) Crie métodos de retornar a próxima música a ser tocada
//    i) Para cada chamada deste método a música retornada deve ser a próxima da lista de
//    músicas na playlist (começando pela primeira, depois a segunda e assim por
//    diante). Caso não haja mais músicas para ser tocadas, o método deve retornar
//    NULL.
// d) Crie um método, usando recursão, para imprimir todas as músicas que formam a
// playlist.