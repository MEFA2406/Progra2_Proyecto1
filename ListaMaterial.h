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
    NodoMaterial* getInicio();
    void setInicio(NodoMaterial*);
    NodoMaterial* getActual();
    void setActual(NodoMaterial*);

    string toStringMaterial();
    void ingresarMaterial(MaterialBiblioteca*);
    void removerMaterial();
    MaterialBiblioteca* obtenerMaterialTitulo(string titulo);
    MaterialBiblioteca* obtenerMaterialId(int id);
    ~ListaMaterial();
};


#endif //PROYECTO1_LISTAMATERIAL_H
