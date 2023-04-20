#include <string>
using namespace std;

#include "Musica.h"

class listaMusica
{
private:
    Musica data;
    listaMusica* proxima;

public:
    listaMusica(Musica d);

    Musica getMusica();
    listaMusica* getProxima();

    void setProxima(listaMusica* pro);
};