/**
 * @file Playlist.cpp
 * @brief Implementação dos métodos da classe Playlist
 */

#include <iostream>

#include "Playlist.h" /**< Inclui a classe Playlist. */
#include <cstdlib>    /**< Conserta os erros de system???*/

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
 * @brief Construtor cópia da classe Playlist.
 */
Playlist::Playlist(const Playlist &other)
{
    this->nome = other.nome;
    this->lista = new Lista<Musica>(*other.lista);
    this->musicaTocando = 0;
}

/**
 * @brief Destrutor da classe Playlist.
 */
Playlist::~Playlist()
{
    delete lista;
}

/**
 * @brief Limpa a lista de músicas da playlist.
 */
void Playlist::limpar()
{
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
 * @brief Retorna o ponteiro para a lista de músicas da playlist.
 * @return o ponteiro para a lista de músicas da playlist.
 */
Lista<Musica> *Playlist::getLista()
{
    return lista;
}

bool Playlist::operator==(const Playlist &other) const
{
    if (this->nome.compare(other.nome))
    {
        return false;
    }

    return true;
}

Playlist *Playlist::operator=(const Playlist &other)
{
    this->nome = other.nome;
    this->lista = new Lista<Musica>(*other.lista);
    this->musicaTocando = 0;

    return this;
}

Playlist Playlist::operator+(const Playlist &other)
{
    Playlist playlistUniao(this->getNome() + " U " + other.nome);
    playlistUniao.lista = *this->lista + *(other.lista);
    playlistUniao.musicaTocando = 0;

    for (int i = 0; i < playlistUniao.getLista()->tamanho; i++)
    {
        for (int j = i + 1; j < playlistUniao.getLista()->tamanho; j++)
        {
            if (playlistUniao.getLista()->buscarPorIndice(i)->getData() == playlistUniao.getLista()->buscarPorIndice(j)->getData()){
                playlistUniao.removerMusica(j);
            }
        }
    }

    return playlistUniao;
}

Playlist Playlist::operator+(const Musica &other)
{
    Playlist playlistUniao(this->getNome() + " U " + other.getTitulo());
    No<Musica> *noNovo = new No<Musica>(other);
    playlistUniao.lista = this->getLista();
    *playlistUniao.lista << *&noNovo;

    return playlistUniao;
}

Playlist Playlist::operator-(const Playlist &other)
{
    Playlist playlistResultado;
    playlistResultado.nome = this->getNome() + " - " + other.nome;
    playlistResultado.lista = new Lista<Musica>(*this->lista);
    playlistResultado.musicaTocando = 0;

    playlistResultado.lista->remover(other.lista);

    return playlistResultado;
}

Playlist Playlist::operator-(const Musica &other)
{
    Playlist playlistResultado;
    playlistResultado.nome = this->getNome() + " - " + other.getTitulo();
    playlistResultado.lista = new Lista<Musica>(*this->lista);
    playlistResultado.musicaTocando = 0;

    for (int i = 0; i < playlistResultado.getLista()->tamanho; i++)
    {
        if (playlistResultado.getLista()->buscarPorIndice(i)->getData() == other)
        {
            playlistResultado.getLista()->remover(i);
        }
    }

    return playlistResultado;
}

void Playlist::operator>>(Musica *&musica)
{
    if (this->getLista()->cauda == nullptr)
    {
        musica = nullptr;
        return;
    }
    
    No<Musica> *noTemp;
    *this->getLista() >> noTemp;
    musica = new Musica(noTemp->getData().getTitulo(), noTemp->getData().getArtista());
    this->removerMusica((this->lista->tamanho) - 1);
}

void Playlist::operator<<(Musica *&musica) {
    if (musica == nullptr)
    {
        return;
    }
    
    No<Musica> *noTemp = new No<Musica>(*musica);
    *this->getLista() << noTemp;
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
 * @brief Adiciona as músicas de uma playlist à outra.
 * @param playlist é a playlist a ser adicionada.
 * @return true se a playlist foi adicionada com sucesso.
 */
bool Playlist::adicionarMusica(Playlist playlist)
{
    this->lista->inserir(playlist.getLista());
    return true;
    // for (int i = 0; i < playlist.getLista()->tamanho; i++)
    // {
    //     this->adicionarMusica(playlist.getLista()->buscarPorIndice(i)->getData());
    // }
    // return true;
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

int Playlist::removerMusica(Playlist playlist)
{
    int qtd_removidos;
    qtd_removidos = this->lista->remover(playlist.getLista());
    return qtd_removidos;
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