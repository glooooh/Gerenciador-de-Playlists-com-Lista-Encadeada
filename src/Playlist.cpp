/**
 * @file Playlist.cpp
 * @brief Implementação dos métodos da classe Playlist
 */

#include <iostream>

#include "Playlist.h" /**< Inclui a classe Playlist. */

using namespace std;

/**
 * @brief Construtor da classe Playlist.
 * @param n é o nome da playlist.
 */
Playlist::Playlist(string n)
{   
    this->nome = n;
    this->lista = new Lista<Musica>();
    this->musicaTocando = 0;
}

/**
 * @brief Construtor padrão da classe Playlist.
 */
Playlist::Playlist() {}

/**
 * @brief Destrutor da classe Playlist.
 */
Playlist::~Playlist() {}

/**
 * @brief Limpa a lista de músicas da playlist.
*/
void Playlist::limpar() {
    this->lista->~Lista();
}

/**
 * @brief Retorna o nome da playlist.
 * @return o nome da playlist.
 */
string Playlist::getNome()
{
    return nome;
}

/**
 * @brief Retorna a lista de músicas da playlist.
 * @return a lista de músicas da playlist.
 */
Lista<Musica> *Playlist::getLista()
{
    return lista;
}

/**
 * @brief Adiciona uma música à playlist.
 * @param musica é a música a ser adicionada.
 * @return true se a música foi adicionada com sucesso.
 */
bool Playlist::adicionarMusica(Musica musica)
{
    this->lista->inserir(musica);
    return true;
}

/**
 * @brief Remove uma música da playlist.
 * @param indice é o índice da música a ser removida.
 * @return true se a música foi removida com sucesso, false caso contrário.
 */
bool Playlist::removerMusica(int indice)
{
    bool statusOperacao;
    statusOperacao = this->lista->remover(indice);
    return statusOperacao;
}

/**
 * @brief Toca a próxima música da playlist.
 * @return a próxima música da playlist.
 */
No<Musica> *Playlist::proximaMusica()
{
    // Verifica se a playlist possui músicas.
    if (this->lista->tamanho <= 0)
    {
        cout << "A PLAYLIST NAO POSSUI MUSICAS" << endl;
        system("pause");
        system("clear||cls");
        return NULL;
    }

    // Verifica se é a última música tocando.
    if (this->musicaTocando == this->lista->tamanho)
    {
        cout << "A PLAYLIST CHEGOU AO FIM!" << endl;
        this->musicaTocando = 0;
        system("pause");
        system("clear||cls");
        return NULL;
    }

    // Busca a música que está tocando pelo índice.
    No<Musica> *celula = this->lista->buscarPorIndice(musicaTocando);

    // Incrementa o índice.
    this->musicaTocando++;

    return celula;
}

/**
 * @brief Imprime as músicas da playlist.
 */
void Playlist::imprimir()
{
    // Verifica se a playlist está vazia
    if (this->lista->cabeca == nullptr)
    {
        cout << "A Playlist esta vazia!" << endl;
        return;
    }
    
    // Chama a função de impressão recursiva.
    impressaoRecursiva(this->lista->cabeca, 0);

    return;
}

/**
 * @brief Função auxiliar para imprimir as músicas da playlist recursivamente.
 * @param celula é a célula atual da lista encadeada.
 * @param indice é o índice correspondente à música sendo impressa.
 */
void Playlist::impressaoRecursiva(No<Musica> *celula, int indice)
{
    // Imprime a música atual.
    cout << indice + 1 << ". '" << celula->data.getTitulo() << "' de " << celula->data.getArtista() << endl;

    // Verifica se existe uma próxima música na lista
    if (celula->proximo != nullptr)
    {
        // Incrementa o índice e utiliza recursão para imprimir a próxima música.
        indice++;
        impressaoRecursiva(celula->proximo, indice);
    }

    return;
}