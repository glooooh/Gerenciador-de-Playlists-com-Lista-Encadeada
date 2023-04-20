#include <iostream>
#include <string>
#include <cstring>

using namespace std;

using std::cout; using std::cin;
using std::endl; using std::string;

#include "Playlist.h"

Playlist::Playlist(string n)
{
    nome = n;
    cabeca = NULL;
    cauda = NULL;
}

void Playlist::inserir(Musica m)
{
    listaMusica* nova = new listaMusica(m);

    if (cabeca == NULL)
    {
        cabeca = nova;
        cauda = nova;
    }else{
        cauda->setProxima(nova);
        cauda = nova;
    }
}

void Playlist::remover(string n, string a) {

    listaMusica* nova;
    nova = cabeca;
    
    while(nova != NULL){
        if(a.compare(nova->getMusica().getArtista()) == 0){
            if(n.compare(nova->getMusica().getTitulo()) == 0){
                return nova;
                break;
            }
        }
        nova = nova->getProxima();
    }
}

void imprimir() {
}