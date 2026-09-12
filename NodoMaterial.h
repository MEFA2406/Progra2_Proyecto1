#ifndef PROYECTO1_NODOMATERIAL_H
#define PROYECTO1_NODOMATERIAL_H
#include "MaterialBiblioteca.h"
class NodoMaterial {
private:
    MaterialBiblioteca *material;
    NodoMaterial *siguienteMaterial;
public:
    NodoMaterial();
    NodoMaterial(MaterialBiblioteca *material);
    ~NodoMaterial();
    MaterialBiblioteca *get_material() const;
    NodoMaterial *get_siguienteMaterial() ;
    void set_siguienteMaterial(NodoMaterial *siguienteMaterial);
    //string toString();
};


#endif //PROYECTO1_NODOMATERIAL_H
