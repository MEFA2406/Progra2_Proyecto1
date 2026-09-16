#ifndef PROYECTO1_REVISTA_H
#define PROYECTO1_REVISTA_H
#include "MaterialBiblioteca.h"
class Revista: public MaterialBiblioteca {
    private:
    int edicion;
    string genero;
    public:
    Revista(int id, string titulo, string autor, int annio, int edicion, string genero);
    ~Revista();
    void setEdicion(int edicion);
    int getEdicion();
    void setGenero(string genero);
    string getGenero();
    string obtenerTipo() override;
    string toStringMaterial() override;
};


#endif //PROYECTO1_REVISTA_H
