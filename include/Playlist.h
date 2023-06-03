/**
 * @file Playlist.h
 * @brief Arquivo header da classe Playlist.
 */

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

#include "Lista.h"  /**< Inclui a classe Lista. */
#include "Musica.h" /**< Inclui a classe Musica. */

using namespace std;

/**
 * @class Playlist
 * @brief Classe que representa uma playlist.
 */
class Playlist
{
private:
    string nome;          /*!< Nome da playlist */
    Lista<Musica> *lista; /*!< Lista ligada de músicas da playlist */
    int musicaTocando;    /*!< Ponteiro para a música tocando atualmente */

public:
    // Construtores
    Playlist(string);
    Playlist();
    Playlist(const Playlist &other);

    // Destrutor
    ~Playlist();
    void limpar();

    bool operator==(const Playlist& other) const;
    Playlist *operator=(const Playlist& other);
    Playlist operator+(const Playlist& other);  // a união de playlists não permite músicas repetidas na playlist resultante. A operação não deve modificar a playlist original, retornando uma nova lista como resultado.
    Playlist operator+(const Musica& other);    /** B. Operador “+”: Uma versão sobrecarregada do operador “+” porém
                                                recebendo uma música como parâmetro. Nesse caso, a música deve ser
                                                adicionada ao final da playlist que é retornada como resultado do operador.
                                                (a playlist original continua inalterada).*/
    Playlist operator-(const Playlist& other);  /** C. Operador “-”: implementa a diferença entre duas playlists. Sejam duas
                                                Playlists a e b, a operação a – b retorna a uma nova playlist contendo todos os
                                                elementos da playlist a que não estão na playlist b. Da mesma forma que a
                                                operação de união, a playlist original não deve ser modificada após a
                                                operação. */
    Playlist operator-(const Musica& other);    /** D. Operador “-”: uma versão sobrecarregada do operador “-” porém recebendo
                                                uma música como parâmetro. Nesse caso, a música deve ser removida da,
                                                playlist que é retornada como resultado do operador. (a playlist original
                                                continua inalterada).*/
    void operator>>(Musica*& musica);           /** E. Operador de extração “>>”: remove a última música da playlist atual e
                                                preenche na Música recebida como argumento. Caso não existam músicas na
                                                playlist, nullptr deve ser preenchido no parâmetro.*/
    void operator<<(Musica*& musica);           /** F. Operador de inserção “<<”: insere a música recebida na última posição da
                                                playlist atual. Caso nullptr seja recebido, nada deve ser feito. */

    // Gets
    string getNome();
    Lista<Musica> *getLista();

    // CRUD
    bool adicionarMusica(Musica);
    bool adicionarMusica(Playlist);
    bool removerMusica(int);
    int removerMusica(Playlist);

    // Metodos da funcionalidade "tocando"
    No<Musica> *proximaMusica();

    // Impressão com recursão
    void imprimir();
    // Chamado pela função 'imprimir'
    void impressaoRecursiva(No<Musica> *, int);
};

#endif

// Melhorias na classe que representa a Playlist
// Nossa classe que representa uma Playlist e possui uma lista ligada deve espelhar as
// melhorias que foram feitas na classe Lista Ligada.
// 3 - Implemente os seguintes métodos adicionais:
// A. Adicionar músicas: Este método é uma versão sobrecarregada do método
// que adiciona uma música à Playlist, porém esse método recebe como
// parâmetro, por referência, outra Playlist. Ao final da operação espera-se que
// todos os elementos da playlist recebida sejam adicionados no final da playlist
// atual.
// B. Remover músicas: Este método é uma versão sobrecarregada do método que
// remove uma música da Playlist, porém esse método recebe como parâmetro,
// por referência, outra Playlist e remove todas as músicas da playlist atual, que
// estejam na lista recebida por parâmetro. O método deve retornar um número
// com a quantidade de elementos que foram removidos.
// C. Construtor cópia: Este método é similar ao construtor cópia criado para a
// lista, porém feito para a playlist.
// 4 - Implemente os seguintes operadores para a Playlist:
// A. Operador “+”: implementa a união de duas PlayLists. Diferente da
// concatenação de Listas Ligadas, a união de playlists não permite músicas
// repetidas na playlist resultante. A operação não deve modificar a playlist
// original, retornando uma nova lista como resultado.
// B. Operador “+”: Uma versão sobrecarregada do operador “+” porém
// recebendo uma música como parâmetro. Nesse caso, a música deve ser
// adicionada ao final da playlist que é retornada como resultado do operador.
// (a playlist original continua inalterada).
// C. Operador “-”: implementa a diferença entre duas playlists. Sejam duas
// Playlists a e b, a operação a – b retorna a uma nova playlist contendo todos os
// elementos da playlist a que não estão na playlist b. Da mesma forma que a
// operação de união, a playlist original não deve ser modificada após a
// operação.
// D. Operador “-”: uma versão sobrecarregada do operador “-” porém recebendo
// uma música como parâmetro. Nesse caso, a música deve ser removida da
// playlist que é retornada como resultado do operador. (a playlist original
// continua inalterada).
// E. Operador de extração “>>”: remove a última música da playlist atual e
// preenche na Música recebida como argumento. Caso não existam músicas na
// playlist, nullptr deve ser preenchido no parâmetro.
// F. Operador de inserção “<<”: insere a música recebida na última posição da
// playlist atual. Caso nullptr seja recebido, nada deve ser feito.