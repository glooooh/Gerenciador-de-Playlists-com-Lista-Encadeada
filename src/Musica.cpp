#include <iostream>
#include "Musica.h"

using namespace std;

// Construtores
Musica::Musica(string tit, string art)
{
    titulo = tit;
    artista = art;
}
Musica::Musica() {}

// Destrutores
Musica::~Musica() {}

// Gets
string Musica::getTitulo() { return titulo; }

string Musica::getArtista() { return artista; }
