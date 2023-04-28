#include <iostream>
#include <string>
#include <locale>

using namespace std;

#include "Playlist.h"

/**
 * @brief Função voltar ao menu principal.
 *
 */
void voltar()
{
    // checar erros
    return;
}

/**
 * @brief Pedir informações de uma música para o usuário.
 *
 * @return a musica que o usuário informou.
 */
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

/**
 * @brief Cadastra uma nova música na lista de músicas cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 */
void cadastrarMusica(Lista<Musica> *listaMusicasCadastradas)
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

/**
 * @brief Remove uma música da lista de músicas cadastradas e das playlists em que está presente.
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 */
void removerMusica(Lista<Playlist> *listaPlaylists, Lista<Musica> *listaMusicasCadastradas)
{
    bool removidoDePlaylist = false;
    No<Musica> *noTemp = new No<Musica>;
    Lista<Musica> *listaMusicaTemporaria = new Lista<Musica>;

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

/**
 * @brief Lista as músicas cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 */
void listarMusicas(Lista<Musica> *listaMusicasCadastradas)
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

/**
 * @brief Gerencia as músicas cadastradas.
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 * @details Esta função permite ao usuário adicionar, remover ou listar as músicas cadastradas.
 * O usuário escolhe a ação que deseja realizar.
 */
void gerenciarMusicas(Lista<Musica> *listaMusicasCadastradas, Lista<Playlist> *listaPlaylists)
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

/**
 * @brief Adiciona uma nova playlist à lista de playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 */
void adicionarPlaylist(Lista<Playlist> *listaPlaylistsCadastradas)
{
    string nome;

    cout << "Insira o nome da playlist a ser adicionada:" << endl;
    getline(cin, nome);

    Playlist playlistNova(nome);

    listaPlaylistsCadastradas->inserir(playlistNova);
}

/**
 * @brief Remove uma playlist da lista de playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @param i O índice da playlist selecionada pelo usuário.
 */
void removerPlaylist(Lista<Playlist> *listaPlaylistsCadastradas, int i)
{
    listaPlaylistsCadastradas->remover(i);
}

/**
 * @brief Lista as playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 */
void listarPlaylists(Lista<Playlist> *listaPlaylistsCadastradas)
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

/**
 * @brief Gerencia as playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 * @details Esta função permite ao usuário adicionar, remover ou listar as playlists cadastradas.
 * O usuário escolhe a ação que deseja realizar por meio de um menu.
 */
void gerenciarPlaylists(Lista<Playlist> *listaPlaylistsCadastradas, Lista<Musica> *listaMusicasCadastradas)
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

/**
 * @brief Exibe a música que está tocando atualmente.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @param playlistTocando O índice da playlist selecionada pelo usuário.
 * @details Esta função busca a próxima música da playlist escolhida e exibe o título dela.
 * @note A função não retorna nenhum valor, apenas exibe-o para o usuário.
 */
void estaTocandoAgora(Lista<Playlist> *listaPlaylistsCadastradas, int playlistTocando)
{
    Musica musicaTocando;
    musicaTocando = listaPlaylistsCadastradas->buscarPorIndice(playlistTocando)->data.proximaMusica();

    cout << "Música tocando agora: " << musicaTocando.getTitulo() << endl;
}

/**
 * @brief Solicita que o usuário escolha uma playlist para ser tocada.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @details Esta função apresenta um menu com as playlists cadastradas e solicita ao usuário 
 * que escolha uma opção a partir deste menu.
 * @return O índice da playlist escolhida pelo usuário.
 */
int escolherPlaylist(Lista<Playlist> *listaPlaylistsCadastradas)
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

/**
 * @brief Adicionar uma música à uma playlist.
 *
 * @param listaPlaylist Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 * @param indicePlaylist O índice da playlist selecionada pelo usuário.
 */
void adicionarMusicaPlaylist(Lista<Playlist> *listaPlaylist, Lista<Musica> *listaMusicasCadastradas, int indicePlaylist)
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
                // cadastro da música apenas na playlist
                listaPlaylist->buscarPorIndice(indicePlaylist)->data.adicionarMusica(musicaNova);
                return;
            }
        }
        listaTemp = listaTemp->proximo;
    }

    // cadastro da música na playlist e no sistema
    listaPlaylist->buscarPorIndice(indicePlaylist)->data.adicionarMusica(musicaNova);
    listaMusicasCadastradas->inserir(musicaNova);
    return;
}

/**
 * @brief Remover música de uma playlist.
 *
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param playlistEscolhida O índice da playlist selecionada pelo usuário.
 */
void removerMusicaPlaylist(Lista<Playlist> *listaPlaylists, int playlistEscolhida)
{
    Lista<Musica> *listaMusicaTemporaria = new Lista<Musica>;
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

/**
 * @brief Listar músicas de uma playlist.
 *
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param playlistEscolhida O índice da playlist selecionada pelo usuário.
 */
void listarMusicasPlaylist(Lista<Playlist> *listaPlaylists, int playlistEscolhida)
{
    listaPlaylists->buscarPorIndice(playlistEscolhida)->data.imprimir();
}

/**
 * @brief Move uma música dentro de uma playlist.
 *
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param playlistEscolhida O índice da playlist selecionada pelo usuário.
 * @details Esta função permite ao usuário selecionar uma música em uma playlist
 * e movê-la para outra posição dentro da mesma playlist. O usuário informa o índice
 * da música escolhida e o índice da posição para onde a música deve ser movida.
 * @note A função não realiza nenhuma validação do input do usuário.
 */
void moverMusicaPlaylist(Lista<Playlist> *listaPlaylists, int playlistEscolhida)
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
    }else if(listaPlaylists->buscarPorIndice(playlistEscolhida)->getData().getLista()->tamanho <= musicaIndice){
        cout << "Indice de música inválido." << endl;
        return;
    }else if(listaPlaylists->buscarPorIndice(playlistEscolhida)->getData().getLista()->tamanho <= indiceNovo){
        cout << "Indice novo para música é invalido." << endl;
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

/**
 * @brief Gerencia as músicas em todas as playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 * @details Esta função permite ao usuário adicionar, remover ou mover músicas em todas as playlists cadastradas.
 * O usuário escolhe a ação que deseja realizar e a playlist na qual deseja realizar a ação.
 * @note A função não realiza nenhuma validação do input do usuário.
 */
void gerenciarMusicasEmPlaylists(Lista<Playlist> *listaPlaylistsCadastradas, Lista<Musica> *listaMusicasCadastradas)
{
    int playlistEscolhida;

    cout << "Digite o número da playlist que deseja gerenciar: " << endl;
    // imprimir playlists cadastradas
    listarPlaylists(listaPlaylistsCadastradas);

    cin >> playlistEscolhida;
    playlistEscolhida--;

    if(listaPlaylistsCadastradas->tamanho <= playlistEscolhida){
        cout << "Essa playlist não existe." << endl;
        voltar();
    }

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

/**
 * @brief Encerra o programa.
 * 
 */
void sair()
{
    // Verificar falhas no vazamento de memória
    // Encerrar o programa
    exit(0);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "portuguese-brazilian");

    // Declarando a variavel da lista de músicas cadastradas
    Lista<Musica> *listaMusicasCadastradas;
    listaMusicasCadastradas = new Lista<Musica>;

    // Declarando a variável da lista de playlists cadastradas
    Lista<Playlist> *listaPlaylistsCadastradas;
    listaPlaylistsCadastradas = new Lista<Playlist>;

    // Pré-Cadastro:
    listaMusicasCadastradas->inserir(Musica("Red", "Taylor Swift"));
    listaMusicasCadastradas->inserir(Musica("Lego House", "Ed Sheeran"));
    listaMusicasCadastradas->inserir(Musica("Deixa Eu Viver", "Mari Fernandez"));
    listaMusicasCadastradas->inserir(Musica("Pilanta", "Jao"));
    listaMusicasCadastradas->inserir(Musica("Sorry To Me Too", "Julia Michaels"));

    listaPlaylistsCadastradas->inserir(Playlist("Minha Playlist"));

    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Red", "Taylor Swift"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Deixa Eu Viver", "Mari Fernandez"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Pilanta", "Jao"));

    // MENU

    int continuar = 1; /**< Variável que indica qual opção do menu foi escolhida pelo usuário. */
    int playlistTocando = 0;

    do /**< Loop exibe o menu até que o usuário selecione a opção "Sair"*/
    {
        cout << "MENU! O que voce deseja fazer? (Digite o numero apenas)" << endl;
        cout << "1 - Gerenciar musicas" << endl;
        cout << "2 - Gerenciar playlists" << endl;
        cout << "3 - Gerenciar musicas em playlists" << endl;
        cout << "4 - Selecione uma playlist para tocar" << endl;
        cout << "5 - O que esta tocando agora?" << endl;
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
            /** Caso o usuário não escolha uma playlist irá tocar a primeira cadastrada.*/ 
            estaTocandoAgora(listaPlaylistsCadastradas, playlistTocando);
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