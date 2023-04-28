#ifndef NO_H
#define NO_H

#include "Musica.h"

template <typename T>
class No
{
public:
    T data;
    No *proximo;

public:
    // Construtores
    No(T data)
    {
        this->data = data;
        No *proximo = nullptr;
    }
    No() {}

    // Gets
    T getData() { return data; }
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

/*
// Destrutores
No::~No() {}

// Gets
Musica No::getMusica() { return data; }

No *No::getProxima() { return proxima; }

// Sets
void No::setProxima(No *p)
{
 proxima = p;
}

void inserir() {}
void remover(No, No)
{
}*/