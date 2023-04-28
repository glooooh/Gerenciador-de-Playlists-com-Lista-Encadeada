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