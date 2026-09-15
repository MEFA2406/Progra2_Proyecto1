#ifndef PROYECTO1_LIBRO_H
#define PROYECTO1_LIBRO_H
#include <string>
#include "MaterialBiblioteca.h"

using namespace std;
class Libro :public MaterialBiblioteca {
private:
    string genero;
    int paginas;
    public:
    Libro(int id, string titulo, string autor, int annio, int paginas, string genero);
    ~Libro();
    void setGenero(string genero);
    void setPaginas(int paginas);
    string getGenero();
    int getPaginas();
    string obtenerTipo();
};


#endif //PROYECTO1_LIBRO_H
