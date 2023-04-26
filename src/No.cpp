#include <iostream>

using namespace std;

#include "No.h"

// Construtores
No::No(Musica data)
{
    this->data = data;
    No *proximo = nullptr;
}

No::No() {}

// Gets
Musica No::getMusica() { return data; }

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