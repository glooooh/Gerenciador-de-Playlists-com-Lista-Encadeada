#include <string>
using namespace std;

class Musica
{
private:
    string titulo;
    string artista;

public:
    Musica(string, string);
    Musica();

    ~Musica();

    string getTitulo();
    string getArtista();
};