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
    this->nome = n;
    this->lista = new ListaMusica();
    this->musicaTocando = nullptr;
}

Playlist::~Playlist()
{
}

// Gets
string Playlist::getNome() {
    return nome;
}

// CRUD

bool Playlist::adicionarMusica(Musica m)
{
    this->lista->inserir(m);
    return true;
}

bool Playlist::removerMusica(int indice)
{
    bool statusOperacao;
    statusOperacao = this->lista->remover(indice);
    return statusOperacao;
}

// Metodos da funcionalidade "tocando"
Musica Playlist::proximaMusica()
{
    // caso seja a primeira vez tocando a playlist ou a playlist chegou à última música
    if (this->musicaTocando == nullptr || this->musicaTocando->proximo == nullptr)
    {
        this->musicaTocando = this->lista->cabeca;

        if (this->musicaTocando != nullptr)
        {
            cout << "A PLAYLIST IRÁ RECOMEÇAR!" << endl;
        }

        return this->musicaTocando->data;
    }

    // padrão (existe uma próxima música e ela será tocada)
    this->musicaTocando = this->musicaTocando->proximo;
    return this->musicaTocando->data;
}

// Impressão com recursão
void Playlist::imprimir()
{
    if (this->lista->cabeca == nullptr)
    {
        cout << "A Playlist está vazia!" << endl;
        return;
    }

    impressaoRecursiva(this->lista->cabeca);

    return;
}

void Playlist::impressaoRecursiva(No *celula)
{
    cout << "Título da música:" << celula->data.getTitulo() << endl
         << "Artista:" << celula->data.getArtista() << endl;

    if (celula->proximo != nullptr)
    {
        impressaoRecursiva(celula->proximo);
    }

    return;
}