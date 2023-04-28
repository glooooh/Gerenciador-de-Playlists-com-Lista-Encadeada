#include <iostream>
#include <string>

#include "Playlist.h"

// Função voltar do menu
void voltar()
{
    // checar erros
    return;
}

// Pedir a música para o usuário
Musica pedirMusica()
{
    string nome;
    string artista;

    cout << "Insira o nome da música:" << endl;
    getline(cin, nome);

    cout << "Insira o artista:" << endl;
    getline(cin, nome);

    Musica musica(nome, artista);

    return musica;
}

// Adiciona música a playlist
void adicionarMusicaPlaylist(ListaMusica<Playlist> *listaPlaylist, ListaMusica<Musica> *listaMusicasCadastradas, int i)
{
    // Receber música nova dentro da função !!!!!!!!!!!!!!!!!!!!!!

    No<Musica> *listaTemp = new No<Musica>;
    listaTemp = listaMusicasCadastradas->cabeca;

    Musica musicaNova;
    musicaNova = pedirMusica();

    // Pensar se é melhor substituir listaPlaylist->buscarPorIndice(i)->data por uma variável ponteiro
    // Playlist *playlistEscolhida = new Playlist;
    // *playlistEscolhida = listaPlaylist->buscarPorIndice(i)->data;

    // percorre a lista encadeada de músicas já cadastradas e confere se a música a ser cadastrada
    // ainda não existe na lista
    for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
    {
        // comparação de titulo
        if (listaTemp->data.getTitulo().compare(musicaNova.getTitulo()) == 0)
        {
            // comparação de artista
            if (listaTemp->data.getArtista().compare(musicaNova.getArtista()) == 0)
            {
                // cadastro da música apenas na playlist
                listaPlaylist->buscarPorIndice(i)->data.adicionarMusica(musicaNova);
                return;
            }
        }
        listaTemp = listaTemp->proximo;
    }

    // cadastro da música na playlist e no sistema
    listaPlaylist->buscarPorIndice(i)->data.adicionarMusica(musicaNova);
    listaMusicasCadastradas->inserir(musicaNova);
    return;
}

// Remover musica da playlist
void removerMusicaPlaylist(ListaMusica<Playlist> *listaPlaylists, int playlistEscolhida)
{
    ListaMusica<Musica> *listaMusicaTemporaria = new ListaMusica<Musica>;
    No<Musica> *noTemp = new No<Musica>;

    bool removidoDePlaylist = false;

    Musica musicaRemovida;
    musicaRemovida = pedirMusica();

    // pegando lista ligada de playlist
    listaMusicaTemporaria = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista();

    // pegando o nó cabeca da lista ligada
    noTemp = listaMusicaTemporaria->cabeca;

    // percorrendo a lista ligada dentro de playlists
    for (int j = 0; j < listaMusicaTemporaria->tamanho; j++)
    {
        // comparação de titulo
        if (noTemp->data.getTitulo().compare(musicaRemovida.getTitulo()) == 0)
        {
            // comparação de artista
            if (noTemp->data.getArtista().compare(musicaRemovida.getArtista()) == 0)
            {
                // remover musica da playlist
                removidoDePlaylist = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.removerMusica(j);
                break;
            }
        }
        noTemp = noTemp->proximo;
    }

    // aviso de que a música foi removida de tal playlist
    if (removidoDePlaylist)
    {
        cout << musicaRemovida.getTitulo() << " foi removido da playlist " << listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getNome() << endl;
        removidoDePlaylist = false;
    }
}

// Listar músicas da playlist
void listarMusicasPlaylist(ListaMusica<Playlist> *listaPlaylists, int playlistEscolhida)
{
    listaPlaylists->buscarPorIndice(playlistEscolhida)->data.imprimir();
}

// Listar músicas da playlist
void moverMusicaPlaylist(ListaMusica<Playlist> *listaPlaylists, int playlistEscolhida)
{
    int musicaIndice, indiceNovo;

    cout << "Musicas: " << endl;
    listarMusicasPlaylist(listaPlaylists, playlistEscolhida);
    listaPlaylists->buscarPorIndice(playlistEscolhida)->data.imprimir();

    cout << "Digite o número da música escolhida: " << endl;
    cin >> musicaIndice;
    musicaIndice--;

    cout << "Digite para qual posicao voce deseja move-la: " << endl;
    cin >> indiceNovo;
    indiceNovo--;

    if (musicaIndice == indiceNovo)
    {
        return;
    }

    No<Musica> *noTemp = new No<Musica>;
    No<Musica> *noMusicaMovida = new No<Musica>;

    if (musicaIndice != 0 && indiceNovo != 0)
    {
        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice - 1);
        noMusicaMovida = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice);
        noTemp->proximo = noMusicaMovida->proximo;

        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(indiceNovo);
        noMusicaMovida->proximo = noTemp;

        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(indiceNovo - 1);
        noTemp->proximo = noMusicaMovida;
    }
    if (indiceNovo == 0)
    {
        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice - 1);
        noMusicaMovida = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice);
        noTemp->proximo = noMusicaMovida->proximo;

        noMusicaMovida->proximo = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->cabeca;

        listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->cabeca = noMusicaMovida;
    }
    if (musicaIndice == 0)
    {
        noMusicaMovida = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(musicaIndice);
        listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->cabeca = noMusicaMovida->proximo;

        noTemp = listaPlaylists->buscarPorIndice(playlistEscolhida)->data.getLista()->buscarPorIndice(indiceNovo - 1);
        noMusicaMovida->proximo = noTemp->proximo;
        noTemp->proximo = noMusicaMovida;
    }
}

void gerenciarMusicasEmPlaylists(ListaMusica<Playlist> *listaPlaylistsCadastradas, ListaMusica<Musica> *listaMusicasCadastradas)
{
    int playlistEscolhida;

    cout << "Digite o número da playlist que deseja gerenciar: " << endl;
    // imprimir playlists cadastradas
    listarPlaylists(listaPlaylistsCadastradas);

    cin >> playlistEscolhida;
    playlistEscolhida--;

    // Menu para alterar playlist escolhida
    int continuar = 1;

    do
    {
        cout << "MENU! O que você deseja fazer? (Digite o número apenas)" << endl;
        cout << "1 - Adicionar musicas à playlist" << endl;
        cout << "2 - Remover musicas da playlista" << endl;
        cout << "3 - Listar musicas da playlist" << endl;
        cout << "4 - Mover musica da playlist" << endl;
        cout << "5 - Voltar" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:
            adicionarMusicaPlaylist(listaPlaylistsCadastradas, listaMusicasCadastradas, playlistEscolhida);
            break;
        case 2:
            removerMusicaPlaylist(listaPlaylistsCadastradas, playlistEscolhida);
            break;
        case 3:
            listarMusicasPlaylist(listaPlaylistsCadastradas, playlistEscolhida);
            break;
        case 4:
            moverMusicaPlaylist(listaPlaylistsCadastradas, playlistEscolhida);
            break;
        case 5:
            voltar();
            break;
        default:
            cout << "Digite uma opção válida!" << endl;
            break;
        }

    } while (continuar);
}

void cadastrarMusica(ListaMusica<Musica> *listaMusicasCadastradas)
{
    No<Musica> *listaTemp = new No<Musica>;
    listaTemp = listaMusicasCadastradas->cabeca;
    Musica musicaNova;

    musicaNova = pedirMusica();

    // percorre a lista encadeada de músicas já cadastradas e confere se a música a ser cadastrada
    // ainda não existe na lista
    for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
    {
        // comparação de titulo
        if (listaTemp->data.getTitulo().compare(musicaNova.getTitulo()) == 0)
        {
            // comparação de artista
            if (listaTemp->data.getArtista().compare(musicaNova.getArtista()) == 0)
            {
                cout << "Cadastro inválido! Música já foi cadastrada anteriormente" << endl;
                return;
            }
        }
        listaTemp = listaTemp->proximo;
    }

    // cadastro da música no sistema
    listaMusicasCadastradas->inserir(musicaNova);
    return;
}

void removerMusica(ListaMusica<Playlist> *listaPlaylists, ListaMusica<Musica> *listaMusicasCadastradas)
{
    bool removidoDePlaylist = false;
    No<Musica> *noTemp = new No<Musica>;
    ListaMusica<Musica> *listaMusicaTemporaria = new ListaMusica<Musica>;

    Musica musicaRemovida;
    musicaRemovida = pedirMusica();

    // removendo da lista de músicas
    noTemp = listaMusicasCadastradas->cabeca;

    for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
    {
        // comparação de titulo
        if (noTemp->data.getTitulo().compare(musicaRemovida.getTitulo()) == 0)
        {
            // comparação de artista
            if (noTemp->data.getArtista().compare(musicaRemovida.getArtista()) == 0)
            {
                // remoção da música apenas na playlist
                listaMusicasCadastradas->remover(i);
                break;
            }
        }
        noTemp = noTemp->proximo;
    }

    // removendo musica das playlists:

    // percorrendo todas as playlists
    for (int i = 0; i < listaPlaylists->tamanho; i++)
    {
        // pegando lista ligada de playlist
        listaMusicaTemporaria = listaPlaylists->cabeca->data.getLista();

        // pegando o nó cabeca da lista ligada
        noTemp = listaMusicaTemporaria->cabeca;

        // percorrendo a lista ligada dentro de playlists
        for (int j = 0; j < listaMusicaTemporaria->tamanho; j++)
        {
            // comparação de titulo
            if (noTemp->data.getTitulo().compare(musicaRemovida.getTitulo()) == 0)
            {
                // comparação de artista
                if (noTemp->data.getArtista().compare(musicaRemovida.getArtista()) == 0)
                {
                    // remover musica da playlist
                    removidoDePlaylist = listaPlaylists->buscarPorIndice(i)->data.removerMusica(j);
                }
            }
            noTemp = noTemp->proximo;
        }

        // aviso de que a música foi removida de tal playlist
        if (removidoDePlaylist)
        {
            cout << musicaRemovida.getTitulo() << " foi removido da playlist " << listaPlaylists->buscarPorIndice(i)->data.getNome() << endl;
            removidoDePlaylist = false;
        }
    }

    return;
}

void listarMusicas(ListaMusica<Musica> *listaMusicasCadastradas)
{
    No<Musica> *listaTemp = new No<Musica>;
    listaTemp = listaMusicasCadastradas->cabeca;

    // percorre a lista encadeada de músicas já cadastradas e confere se a música a ser cadastrada
    // ainda não existe na lista
    for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
    {
        cout << i + 1 << ". " << listaTemp->data.getTitulo() << endl;
        listaTemp = listaTemp->proximo;
    }
    return;
}

void gerenciarMusicas(ListaMusica<Musica> *listaMusicasCadastradas, ListaMusica<Playlist> *listaPlaylists)
{
    int continuar = 1;

    do
    {
        cout << "MENU! O que você deseja fazer? (Digite o número apenas)" << endl;
        cout << "1 - Adicionar musicas" << endl;
        cout << "2 - Remover musicas" << endl;
        cout << "3 - Listar musicas" << endl;
        cout << "4 - Voltar" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:
            // ainda não existe a função
            cadastrarMusica(listaMusicasCadastradas);
            break;
        case 2:
            removerMusica(listaPlaylists, listaMusicasCadastradas);
            break;
        case 3:
            listarMusicas(listaMusicasCadastradas);
            break;
        case 4:
            voltar();
            break;
        default:
            cout << "Digite uma opção válida!" << endl;
            break;
        }

    } while (continuar);
}

void adicionarPlaylist(ListaMusica<Playlist> *listaPlaylistsCadastradas)
{
    string nome;

    cout << "Insira o nome da playlist a ser adicionada:" << endl;
    getline(cin, nome);

    Playlist playlistNova(nome);

    listaPlaylistsCadastradas->inserir(playlistNova);
}

void removerPlaylist(ListaMusica<Playlist> *listaPlaylistsCadastradas, int i)
{
    listaPlaylistsCadastradas->remover(i);
}

void listarPlaylists(ListaMusica<Playlist> *listaPlaylistsCadastradas)
{
    No<Playlist> *listaTemp = new No<Playlist>;
    listaTemp = listaPlaylistsCadastradas->cabeca;

    // percorre a lista encadeada de músicas já cadastradas e confere se a música a ser cadastrada
    // ainda não existe na lista
    for (int i = 0; i < listaPlaylistsCadastradas->tamanho; i++)
    {
        cout << i + 1 << ". " << listaTemp->data.getNome() << endl;
        listaTemp = listaTemp->proximo;
    }
    return;
}

void gerenciarPlaylists(ListaMusica<Playlist> *listaPlaylistsCadastradas, ListaMusica<Musica> *listaMusicasCadastradas)
{
    int playlistEscolhida;

    // Menu para alterar playlist escolhida
    int continuar = 1;

    do
    {
        cout << "MENU! O que você deseja fazer? (Digite o número apenas)" << endl;
        cout << "1 - Adicionar playlists" << endl;
        cout << "2 - Remover playlists" << endl;
        cout << "3 - Listar playlists" << endl;
        cout << "4 - Voltar" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:
            // ainda não existe a função
            adicionarPlaylist(listaPlaylistsCadastradas);
            break;
        case 2:
            cout << "Digite o número da playlist que deseja excluir: " << endl;

            cin >> playlistEscolhida;
            playlistEscolhida--;

            if (playlistEscolhida < 0 || playlistEscolhida > listaPlaylistsCadastradas->tamanho)
            {
                cout << "Playlist inválida" << endl;
            }
            else
            {
                removerPlaylist(listaPlaylistsCadastradas, playlistEscolhida);
            }
            break;
        case 3:
            listarPlaylists(listaPlaylistsCadastradas);
            break;
        case 4:
            voltar();
            break;
        default:
            cout << "Digite uma opção válida!" << endl;
            break;
        }

    } while (continuar);
}

void estaTocandoAgora(ListaMusica<Playlist> *listaPlaylistsCadastradas, int playlistTocando)
{
    Musica musicaTocando;
    musicaTocando = listaPlaylistsCadastradas->buscarPorIndice(playlistTocando)->data.proximaMusica();

    cout << "Música tocando agora: " << musicaTocando.getTitulo() << endl;
}

int escolherPlaylist(ListaMusica<Playlist> *listaPlaylistsCadastradas)
{
    int playlistEscolhida;

    cout << "Digite o número da playlist que deseja tocar: " << endl;

    // imprimir playlists cadastradas
    listarPlaylists(listaPlaylistsCadastradas);

    cin >> playlistEscolhida;
    playlistEscolhida--;

    cout << listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida)->getData().getNome() << " está tocando agora." << endl;

    return playlistEscolhida;
}

void sair()
{
    // Verificar falhas no vazamento de memória
    exit(0);
}

int main(int argc, char *argv[])
{
    // Declarando a variavel da lista de músicas cadastradas
    ListaMusica<Musica> *listaMusicasCadastradas;
    listaMusicasCadastradas = new ListaMusica<Musica>;

    // Declarando a variável da lista de playlists cadastradas
    ListaMusica<Playlist> *listaPlaylistsCadastradas;
    listaPlaylistsCadastradas = new ListaMusica<Playlist>;

    // MENU

    int continuar = 1;
    int playlistTocando = NULL;

    do
    {
        cout << "MENU! O que você deseja fazer? (Digite o número apenas)" << endl;
        cout << "1 - Gerenciar músicas" << endl;
        cout << "2 - Gerenciar playlists" << endl;
        cout << "3 - Gerenciar musicas em playlists" << endl;
        cout << "4 - Selecione uma playlist para tocar" << endl;
        cout << "5 - O que está tocando agora?" << endl;
        cout << "6 - Sair" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:
            gerenciarMusicas(listaMusicasCadastradas, listaPlaylistsCadastradas);
            break;
        case 2:
            gerenciarPlaylists(listaPlaylistsCadastradas, listaMusicasCadastradas);
            break;
        case 3:
            gerenciarMusicasEmPlaylists(listaPlaylistsCadastradas, listaMusicasCadastradas);
            break;
        case 4:
            playlistTocando = escolherPlaylist(listaPlaylistsCadastradas);
            break;
        case 5:
            if (playlistTocando)
            {
                estaTocandoAgora(listaPlaylistsCadastradas, playlistTocando);
            }
            break;
        case 6:
            sair();
            break;
        default:
            cout << "Digite uma opção válida!" << endl;
            break;
        }

    } while (continuar);

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