#include <iostream>
#include <string>
#include <locale>

using namespace std;

#include "Playlist.h"

/**
 * @brief Pedir informações de uma música para o usuário.
 *
 * @return a musica que o usuário informou.
 */
Musica pedirMusica()
{
    string nome, artista;
    cout << "Insira o nome da música: " << endl;
    while (getline(cin, nome))
    {
        if (nome != "")
        {
            break;
        }
    }

    cout << "Insira o artista:" << endl;
    while (getline(cin, artista))
    {
        if (nome != "")
        {
            break;
        }
    }

    Musica musica(nome, artista);

    return musica;
}

/**
 * @brief Cadastra uma nova música na lista de músicas cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 */
void cadastrarMusica(Lista<Musica> *listaMusicasCadastradas)
{
    system("clear||cls");

    No<Musica> *listaTemp = listaMusicasCadastradas->cabeca;

    Musica musicaNova;
    cout << "Cadastre uma musica: \n"
         << endl;
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
                cout << "Cadastro invalido! Musica ja foi cadastrada anteriormente" << endl;
                system("pause");
                return;
            }
        }
        listaTemp = listaTemp->proximo;
    }

    // cadastro da música no sistema
    listaMusicasCadastradas->inserir(musicaNova);

    delete listaTemp;

    cout << "\nMusica cadastrada no sistema." << endl;
    system("pause");
    system("clear||cls");
    return;
}

/**
 * @brief Remove uma música da lista de músicas cadastradas e das playlists em que está presente.
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 */
void removerMusica(Lista<Playlist> *listaPlaylists, Lista<Musica> *listaMusicasCadastradas)
{
    system("clear||cls");

    bool existe = false;
    bool removidoDePlaylist = false;
    No<Musica> *noTemp = nullptr;
    Lista<Musica> *listaMusicaTemporaria = nullptr;

    Musica musicaRemovida;

    cout << "Remova uma musica: \n"
         << endl;
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
                existe = true;
                break;
            }
        }
        noTemp = noTemp->proximo;
    }

    // removendo musica das playlists:
    if (existe == true)
    {
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
        cout << "\nMusica removida no sistema!" << endl;
    }
    else
    {
        cout << "\nMusica invalida!" << endl;
    }

    delete listaMusicaTemporaria;

    system("pause");
    system("clear||cls");

    return;
}

/**
 * @brief Lista as músicas cadastradas.
 * @param listaMusicasCadastradas Ponteiro para a lista de músicas cadastradas.
 */
void listarMusicas(Lista<Musica> *listaMusicasCadastradas)
{
    No<Musica> *listaTemp = listaMusicasCadastradas->cabeca;

    system("clear||cls");
    cout << "Musicas cadastradas no sistema:\n"
         << endl;

    // percorre a lista encadeada de músicas já cadastradas e confere se a música a ser cadastrada
    // ainda não existe na lista
    for (int i = 0; i < listaMusicasCadastradas->tamanho; i++)
    {
        cout << i + 1 << ". " << listaTemp->data.getTitulo() << endl;
        listaTemp = listaTemp->proximo;
    }

    delete listaTemp;

    system("pause");
    system("clear||cls");
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
    system("clear||cls");
    int continuar = 1;

    do
    {

        cout << "MENU!" << endl
             << "O que voce deseja fazer? (Digite o numero apenas)" << endl;
        cout << "1 - Adicionar musicas" << endl;
        cout << "2 - Remover musicas" << endl;
        cout << "3 - Listar musicas" << endl;
        cout << "4 - Voltar" << endl;

        cin >> continuar;

        switch (continuar)
        {
        case 1:
            cadastrarMusica(listaMusicasCadastradas);
            break;
        case 2:
            removerMusica(listaPlaylists, listaMusicasCadastradas);
            break;
        case 3:
            listarMusicas(listaMusicasCadastradas);
            break;
        case 4:
            system("clear||cls");
            return;
            break;
        default:
            system("clear||cls");
            cout << "========================" << endl;
            cout << "Digite uma opcao valida!" << endl;
            cout << "========================" << endl;
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

    system("clear||cls");
    cout << "Adicione um playlist:\n"
         << endl;

    cout << "Insira o nome da playlist a ser adicionada:" << endl;
    while (getline(cin, nome))
    {
        if (nome != "")
        {
            break;
        }
    }

    Playlist playlistNova(nome);

    listaPlaylistsCadastradas->inserir(playlistNova);

    cout << "Playlist adicionada no sistema" << endl;
    system("pause");
    system("clear||cls");
}

/**
 * @brief Remove uma playlist da lista de playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 * @param indicePlaylistEscolhida O índice da playlist selecionada pelo usuário.
 */
void removerPlaylist(Lista<Playlist> *listaPlaylistsCadastradas, int indicePlaylistEscolhida)
{
    if (indicePlaylistEscolhida > listaPlaylistsCadastradas->tamanho - 1 || indicePlaylistEscolhida < 0)
    {
        cout << "Playlist invalida!" << endl;
    }
    else
    {
        listaPlaylistsCadastradas->buscarPorIndice(indicePlaylistEscolhida)->data.getLista()->~Lista();
        listaPlaylistsCadastradas->remover(indicePlaylistEscolhida);

        cout << "Playlist removida do sistema" << endl;
    }
    
    system("pause");
    system("clear||cls");
}

/**
 * @brief Lista as playlists cadastradas.
 * @param listaPlaylistsCadastradas Ponteiro para a lista de playlists cadastradas.
 */
void listarPlaylists(Lista<Playlist> *listaPlaylistsCadastradas)
{
    No<Playlist> *listaTemp = listaPlaylistsCadastradas->cabeca;

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
    system("clear||cls");
    int playlistEscolhida;

    // Menu para alterar playlist escolhida
    int continuar = 1;

    do
    {
        cout << "MENU!" << endl
             << "O que voce deseja fazer? (Digite o numero apenas)" << endl;
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
            system("clear||cls");
            cout << "Digite o numero da playlist que deseja excluir: " << endl;

            cin >> playlistEscolhida;
            playlistEscolhida--;

            if (playlistEscolhida < 0 || playlistEscolhida > listaPlaylistsCadastradas->tamanho)
            {
                system("clear||cls");
                cout << "========================" << endl;
                cout << "Playlist Invalida" << endl;
                cout << "========================" << endl;
            }
            else
            {
                removerPlaylist(listaPlaylistsCadastradas, playlistEscolhida);
            }
            break;
        case 3:
            system("clear||cls");
            cout << "Playlists cadastradas no sistema:\n"<< endl;
            listarPlaylists(listaPlaylistsCadastradas);
            system("pause");
            system("clear||cls");
            break;
        case 4:
            system("clear||cls");
            return;
            break;
        default:
            system("clear||cls");
            cout << "========================" << endl;
            cout << "Digite uma opcao valida!" << endl;
            cout << "========================" << endl;
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
    listaPlaylistsCadastradas->buscarPorIndice(playlistTocando)->data.proximaMusica();
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

    // imprimir playlists cadastradas
    listarPlaylists(listaPlaylistsCadastradas);

    cout << "Digite o numero da playlist que deseja tocar: " << endl;

    cin >> playlistEscolhida;
    playlistEscolhida--;

    if (playlistEscolhida < 0 || playlistEscolhida >= listaPlaylistsCadastradas->tamanho)
    {
        cout << "Playlist invalida!" << endl;
        return 0;
    }

    cout << listaPlaylistsCadastradas->buscarPorIndice(playlistEscolhida)->getData().getNome() << " esta tocando agora." << endl;

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
    system("clear||cls");
    cout << "Adicione uma musica a playlist:\n"<< endl;

    No<Musica> *listaTemp = listaMusicasCadastradas->cabeca;

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

    delete listaTemp;

    cout << "Musica adicionada com sucesso."<< endl;
    system("pause");
    system("clear||cls");
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
    Lista<Musica> *listaMusicaTemporaria = nullptr;
    No<Musica> *noTemp = nullptr;

    bool removidoDePlaylist = false;

    Musica musicaRemovida;

    system("clear||cls");
    cout << "Remover uma musica da playlist:\n"<< endl;
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
    }else{
        cout << "Musica nao encontrada."<< endl;
    }

    delete listaMusicaTemporaria;

    system("pause");
    system("clear||cls");
    return;
}

/**
 * @brief Listar músicas de uma playlist.
 *
 * @param listaPlaylists Ponteiro para a lista de playlists cadastradas.
 * @param playlistEscolhida O índice da playlist selecionada pelo usuário.
 */
void listarMusicasPlaylist(Lista<Playlist> *listaPlaylists, int playlistEscolhida)
{
    system("clear||cls");
    cout << "Musicas da playlist:\n"<< endl;
    listaPlaylists->buscarPorIndice(playlistEscolhida)->data.imprimir();

    system("pause");
    system("clear||cls");
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

    cout << "Musicas da playlist: " << endl;
    listarMusicasPlaylist(listaPlaylists, playlistEscolhida);

    cout << "\nDigite o numero da musica escolhida: " << endl;
    cin >> musicaIndice;
    musicaIndice--;

    cout << "\nDigite para qual posicao voce deseja move-la: " << endl;
    cin >> indiceNovo;
    indiceNovo--;

    if (musicaIndice == indiceNovo)
    {
        return;
    }
    else if (listaPlaylists->buscarPorIndice(playlistEscolhida)->getData().getLista()->tamanho <= musicaIndice)
    {
        cout << "Indice de musica invalido." << endl;
        system("pause");
        system("clear||cls");
        return;
    }
    else if (listaPlaylists->buscarPorIndice(playlistEscolhida)->getData().getLista()->tamanho <= indiceNovo)
    {
        cout << "Indice novo para musica e invalido." << endl;
        system("pause");
        system("clear||cls");
        return;
    }

    No<Musica> *noTemp = nullptr;
    No<Musica> *noMusicaMovida = nullptr;

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

    cout << "Musica movida com sucesso." << endl;
    system("pause");
    system("clear||cls");
    return;
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
    system("clear||cls");
    int playlistEscolhida;

    cout << "Digite o numero da playlist que deseja gerenciar:\n " << endl;
    // imprimir playlists cadastradas
    listarPlaylists(listaPlaylistsCadastradas);

    cin >> playlistEscolhida;
    playlistEscolhida--;

    if (listaPlaylistsCadastradas->tamanho <= playlistEscolhida)
    {
        system("clear||cls");
        cout << "========================" << endl;
        cout << "Essa playlist não existe." << endl;
        cout << "========================" << endl;
        return;
    }

    // Menu para alterar playlist escolhida
    int continuar = 1;

    do
    {
        cout << "MENU!" << endl
             << "O que voce deseja fazer? (Digite o numero apenas)" << endl;
        cout << "1 - Adicionar musicas a playlist" << endl;
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
            system("clear||cls");
            return;
            break;
        default:
            system("clear||cls");
            cout << "========================" << endl;
            cout << "Digite uma opcao valida!" << endl;
            cout << "========================" << endl;
            break;
        }

    } while (continuar);
}

/**
 * @brief Encerra o programa.
 *
 */
void sair(Lista<Musica> *listaMusicasCadastradas, Lista<Playlist> *listaPlaylistsCadastradas)
{
    // Verificar falhas no vazamento de memória
    // Encerrar o programa
    delete listaMusicasCadastradas;
    delete listaPlaylistsCadastradas;
    exit(0);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    // Declarando a variavel da lista de músicas cadastradas
    Lista<Musica> *listaMusicasCadastradas = new Lista<Musica>;

    // Declarando a variável da lista de playlists cadastradas
    Lista<Playlist> *listaPlaylistsCadastradas = new Lista<Playlist>;

    /**
     * Insere no sistema valores pré-definidos na lista de músicas cadastradas
     */
    listaMusicasCadastradas->inserir(Musica("Red", "Taylor Swift"));
    listaMusicasCadastradas->inserir(Musica("Lego House", "Ed Sheeran"));
    listaMusicasCadastradas->inserir(Musica("Deixa Eu Viver", "Mari Fernandez"));
    listaMusicasCadastradas->inserir(Musica("Pilantra", "Jao"));
    listaMusicasCadastradas->inserir(Musica("Sorry To Me Too", "Julia Michaels"));
    listaMusicasCadastradas->inserir(Musica("Go Getter", "Mia Giovina"));
    listaMusicasCadastradas->inserir(Musica("So Good", "Halsey"));
    listaMusicasCadastradas->inserir(Musica("The Alcott", "The National"));
    listaMusicasCadastradas->inserir(Musica("You Only Love Me", "Rita Ora"));
    listaMusicasCadastradas->inserir(Musica("Una Noche Sin Pensar", "Sebastian Yatra"));

    listaMusicasCadastradas->inserir(Musica("Bones", "Imagine Dragons"));
    listaMusicasCadastradas->inserir(Musica("Natural", "Imagine Dragons"));
    listaMusicasCadastradas->inserir(Musica("Demons", "Imagine Dragons"));
    listaMusicasCadastradas->inserir(Musica("Bird", "Imagine Dragons"));

    Lista<int> *lista = new Lista<int>;
    lista->inserir(1);
    /**
     * Insere uma playlist pré-definida na lista de playlists cadastradas
     */
    Playlist playlistNova("Playlist de Gloria");
    listaPlaylistsCadastradas->inserir(playlistNova);
    playlistNova.setNome("Playlist de Marcos");
    listaPlaylistsCadastradas->inserir(playlistNova);
    // listaPlaylistsCadastradas->inserir(Playlist("Playlist de Gloria"));
    // listaPlaylistsCadastradas->inserir(Playlist("Playlist Marcos"));

    listaPlaylistsCadastradas->remover(1);

    /**
     * Insere valores pré-definidos nas playlists criadas
     */
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Red", "Taylor Swift"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Deixa Eu Viver", "Mari Fernandez"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Pilantra", "Jao"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("Go Getter", "Mia Giovina"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("The Alcott", "The National"));
    listaPlaylistsCadastradas->cabeca->data.adicionarMusica(Musica("You Only Love Me", "Rita Ora"));

    listaPlaylistsCadastradas->cabeca->proximo->data.adicionarMusica(Musica("Bones", "Imagine Dragons"));
    listaPlaylistsCadastradas->cabeca->proximo->data.adicionarMusica(Musica("Natural", "Imagine Dragons"));
    listaPlaylistsCadastradas->cabeca->proximo->data.adicionarMusica(Musica("Demons", "Imagine Dragons"));
    listaPlaylistsCadastradas->cabeca->proximo->data.adicionarMusica(Musica("Bird", "Imagine Dragons"));

    // MENU

    int continuar = 1; /**< Variável que indica qual opção do menu foi escolhida pelo usuário. */
    int playlistTocando = 0;

    do /**< Loop exibe o menu até que o usuário selecione a opção "Sair"*/
    {
        cout << "MENU!" << endl
             << "O que voce deseja fazer? (Digite o numero apenas)" << endl;
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
            sair(listaMusicasCadastradas, listaPlaylistsCadastradas);
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