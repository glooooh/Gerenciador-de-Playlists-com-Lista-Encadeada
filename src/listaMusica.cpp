#include <iostream>

using namespace std;

#include "listaMusica.h"

listaMusica::listaMusica(Musica d)
{
    data = d;
    proxima = nullptr;
}

Musica listaMusica::getMusica() { return data; }

listaMusica* listaMusica::getProxima() { return proxima; }

void listaMusica::setProxima(listaMusica* pro){
    proxima = pro;
};