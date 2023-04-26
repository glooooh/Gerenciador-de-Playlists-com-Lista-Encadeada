#ifndef NO_H
#define NO_H

#include "Musica.h"

class No
{
public:
    Musica data;
    No *proximo;

    // Construtores
    No(Musica data);
    No();

    // Gets
    Musica getMusica();
};

#endif;

// Destrutores
//    ~No();

/*
// Gets
    Musica getMusica();
    No *getProxima();

// Sets
    void setProxima(No *);
    */