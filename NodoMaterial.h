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
    MaterialBiblioteca *get_material();
    void set_material(MaterialBiblioteca *material);
    NodoMaterial *get_siguienteMaterial() ;
    void set_siguienteMaterial(NodoMaterial *siguienteMaterial);

};


#endif //PROYECTO1_NODOMATERIAL_H
