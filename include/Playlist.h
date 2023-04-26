#include <string>
using namespace std;

#include "ListaMusica.h"

class Playlist
{
private:
    string nome;
    ListaMusica *lista;
    No *musicaTocando;

public:
    // Construtores e desconstrutores
    Playlist(string);
    Playlist();
    ~Playlist();

    //Gets
    string getNome();

    // CRUD
    bool adicionarMusica(Musica);
    bool removerMusica(int); //por índice ou música?

    // Metodos da funcionalidade "tocando"
    Musica proximaMusica();

    // Impressão com recursão
    void imprimir();
    void impressaoRecursiva(No* celula);
};

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