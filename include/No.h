#ifndef NO_H
#define NO_H

#include "Musica.h"

class No
{
private:
    Musica data;
    No *proximo;

public:
    // Construtores
    No(Musica data);

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