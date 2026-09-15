#ifndef PROYECTO1_TESIS_H
#define PROYECTO1_TESIS_H
#include "MaterialBiblioteca.h"

class Tesis : public MaterialBiblioteca {
private:
    string grado;
    public:
    Tesis(int id, string titulo, string autor, int annio, string grado);
    ~Tesis();
    void setGrado(string grado);
    string getGrado();
    string obtenerTipo();

};


#endif //PROYECTO1_TESIS_H
