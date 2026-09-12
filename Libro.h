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
    Libro(string titulo, int paginas);
    ~Libro();
    void setGenero(string titulo);
    void setPaginas(int paginas);
    string getGenero();
    int getPaginas();
};


#endif //PROYECTO1_LIBRO_H
