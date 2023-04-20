#include <string>
using namespace std;

#include "Musica.h"

// A QUESTÃO PEDE:
// a) Crie métodos de inserção e remoção de elementos na lista
// b) Crie métodos de busca e acesso à elementos na lista
// c) Crie os construtores e destrutores correspondentes

class listaMusica
{
private:
    Musica data;
    listaMusica *proxima;

public:
// Construtores
    listaMusica(Musica);

// Destrutores
    ~listaMusica();

// Gets
    Musica getMusica();
    listaMusica *getProxima();

// Sets
    void setProxima(listaMusica *);

// Função buscar
    listaMusica *buscar(string n, string a);
    // Falta o acesso????

// Insercao e remocao
    void inserir();
    void remover(listaMusica, listaMusica);
};