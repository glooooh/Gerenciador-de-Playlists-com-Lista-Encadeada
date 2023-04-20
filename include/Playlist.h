#include <string>
using namespace std;

#include "listaMusica.h"

class Playlist
{
private:
    string nome;
    listaMusica* cabeca;
    listaMusica* cauda;

public:
// Construtores e desconstrutores
    Playlist(string);
    ~Playlist();

// CRUDS
    void inserir(Musica);
    void remover(string, string);
    
    void imprimir();
};