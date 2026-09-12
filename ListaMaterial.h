#ifndef PROYECTO1_LISTAMATERIAL_H
#define PROYECTO1_LISTAMATERIAL_H
#include "NodoMaterial.h"

class ListaMaterial {
private:
    NodoMaterial *inicio;
    NodoMaterial *actual;
public:
    ListaMaterial();
    ListaMaterial(NodoMaterial *inicio, NodoMaterial *actual);
    NodoMaterial* getInicio() const;
    void setInicio(NodoMaterial*);
    NodoMaterial* getActual() const;
    void setActual(NodoMaterial*);

    string toStringMaterial();
    void insertInicio(MaterialBiblioteca*);
    void removeInicio();
    bool findMaterialID(int,string);
    MaterialBiblioteca* obtenerMaterial(string);
    ~ListaMaterial();
};


#endif //PROYECTO1_LISTAMATERIAL_H
