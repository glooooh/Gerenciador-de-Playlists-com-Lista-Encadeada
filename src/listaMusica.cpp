#include <iostream>

using namespace std;

#include "listaMusica.h"

// Construtores
listaMusica::listaMusica(Musica d)
{
    // talvez precise de "this->"
    data = d;
    proxima = NULL;
}

// Destrutores
listaMusica::~listaMusica() {}

// Gets
Musica listaMusica::getMusica() { return data; }

listaMusica *listaMusica::getProxima() { return proxima; }

// Sets
void listaMusica::setProxima(listaMusica *p)
{
    proxima = p;
};

// Função buscar
listaMusica *buscar(listaMusica *c, string n, string a)
{
    listaMusica *p, *prox;
    p = c;
    prox = p->getProxima();

    // o loop vai se repetir até o ponteiro ser igual a NULL (última célula) e vai continuar comparando
    while (prox != NULL)
    {
        p = prox;
        prox = prox->getProxima();

        if (prox->getMusica().getTitulo().compare(n) == 0 && prox->getMusica().getArtista().compare(a) == 0)
        {
            return prox;
        }
    }

    return NULL;
}

void inserir() {}
void remover(listaMusica, listaMusica)
{
}