#ifndef PROYECTO1_TESIS_H
#define PROYECTO1_TESIS_H
#include "MaterialBiblioteca.h"

class Tesis : public MaterialBiblioteca {
private:
    string tipoTesis;
    public:
    Tesis();
    ~Tesis();
    string getTipoTesis();
    void setTipoTesis(string tipoTesis);

};


#endif //PROYECTO1_TESIS_H
