#ifndef PROYECTO1_LISTAMATERIAL_H
#define PROYECTO1_LISTAMATERIAL_H
#include "NodoMaterial.h"

class ListaMaterial {
private:
    NodoMaterial *inicio;
    NodoMaterial *actual;
    NodoMaterial *ultimo;
public:
    ListaMaterial();
    ListaMaterial(NodoMaterial *inicio, NodoMaterial *ultimo, NodoMaterial *actual);
    NodoMaterial* getInicio() const;
    void setInicio(NodoMaterial*);
    NodoMaterial* getActual() const;
    void setActual(NodoMaterial*);

    string toStringMaterial();
    void insertFinal(MaterialBiblioteca*);
    bool removeFinal();
    bool findMaterialID(int,string);
    MaterialBiblioteca* obtenerMaterial(string);
    ~ListaMaterial();
};


#endif //PROYECTO1_LISTAMATERIAL_H
