#include <iostream>
#include "Musica.h"

using namespace std;

Musica::Musica(string tit, string art)
{
    titulo = tit;
    artista = art;
}

string Musica::getTitulo() { return titulo; }

string Musica::getArtista() { return artista; }
