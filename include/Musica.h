#include <string>
using namespace std;

class Musica
{
private:
    string titulo;
    string artista;

public:
// Construtores
    Musica(string, string);
    Musica();

// Destrutores
    ~Musica();

// Gets
    string getTitulo();
    string getArtista();
};