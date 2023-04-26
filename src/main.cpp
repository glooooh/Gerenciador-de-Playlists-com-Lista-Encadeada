#include <iostream>

#include "ListaMusica.h"
#include "Playlist.h"

void adicionarMusicaPlaylist(Playlist vetorPlaylists, ListaMusica *listaMusicasCadastradas, Musica musicaNova)
{
    No *listaTemp = new No;
    listaTemp = listaMusicasCadastradas->cabeca;

    // percorre a lista encadeada de músicas já cadastradas e confere se a música a ser cadastrada 
    // ainda não existe na lista
    for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
    {
        //comparação de titulo
        if (listaTemp->data.getTitulo().compare(musicaNova.getTitulo()) == 0)
        {
            //comparação de artista
            if (listaTemp->data.getArtista().compare(musicaNova.getArtista()) == 0)
            {
                //cadastro da música apenas na playlist
                vetorPlaylists.adicionarMusica(musicaNova);
                return;
            }
        }
        listaTemp = listaTemp->proximo;
    }

    //cadastro da música na playlist e no sistema
    vetorPlaylists.adicionarMusica(musicaNova);
    listaMusicasCadastradas->inserir(musicaNova);
    return;
}

int main(int argc, char *argv[])
{
    // Declarando a variavel da lista de músicas cadastradas
    ListaMusica *listaMusicasCadastradas;
    listaMusicasCadastradas = new ListaMusica;

    // Declarando variável da lista de playlists cadastradas
    int qntPlaylists = 50;
    Playlist *vetorPlaylists;
    vetorPlaylists = new Playlist[qntPlaylists];

    // Variável temporária para música a ser adicionada
    Musica musicaTemp;

    // Cadastrar nova música em playlist
    string nomeTemp;

    cout << "Digite o nome da playlist que você quer adicionar: " << endl;
    getline(cin, nomeTemp);

    for (int i = 0; i < qntPlaylists; i++)
    {
        if(nomeTemp.compare(vetorPlaylists->getNome())){
            adicionarMusicaPlaylist(vetorPlaylists[i], listaMusicasCadastradas, musicaTemp);
        }
    }

    // Remover uma música em playlist

    /*
    INSTRUÇÕES
    4) Implemente uma forma de gerenciar músicas do sistema (adicionar, remover e listar), músicas
    cadastradas devem ser armazenadas usando uma lista ligada.
        a) Caso uma música seja removida, ela também deve ser removida de qualquer playlist que
        ela tenha sido adicionada.

    5) Implemente uma forma de gerenciar playlists do sistema (adicionar, remover e listar), playlists
    podem ser armazenadas no formato de arrays ou usando outra lista ligada(precisa ser
    implementada).
    
    6) Implemente uma forma de gerenciar músicas em uma playlist (adicionar, remover, mover) Para
    a sua solução, você deve, obrigatoriamente:
        - Utilizar modularização nas classes e no main: cada classe deve ser um arquivo separado do
        main. Modularize funções se achar necessário.
        - Toda a compilação deve ser feita utilizando-se makefiles, utilize o cmake para .
    */
}