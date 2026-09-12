#ifndef PROYECTO1_REVISTA_H
#define PROYECTO1_REVISTA_H
#include "MaterialBiblioteca.h"
class Revista: public MaterialBiblioteca {
    private:
    int edicion;
    string genero;
    public:
    Revista();
    Revista(int edicion, string genero);
    ~Revista();
    void setEdicion(int edicion);
    int getEdicion();
    void setGenero(string genero);
    string getGenero();
};


#endif //PROYECTO1_REVISTA_H
