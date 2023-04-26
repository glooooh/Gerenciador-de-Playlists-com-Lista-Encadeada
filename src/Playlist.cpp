#include <iostream>
#include <string>
#include <cstring>

using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::string;

#include "Playlist.h"

Playlist::Playlist(string n)
{
    nome = n;
}

Playlist::~Playlist(){

}

// CRUD
bool Playlist::adicionarMusica(Musica){

}
bool Playlist::removerMusica(int){

} // por índice ou música?

// Metodos da funcionalidade "tocando"
Musica Playlist::proximaMusica(){

}

// Impressão com recursão
void Playlist::imprimir(){

}