#ifndef PROYECTO1_ARCHIVO_H
#define PROYECTO1_ARCHIVO_H
#include "MaterialBiblioteca.h"
#include "NodoMaterial.h"
#include "Usuario.h"

class Archivo {
public:
    void guardarMaterialBiblioteca(MaterialBiblioteca* material);
    void reescribirMaterialBiblioteca(NodoMaterial* nodo);
    void cargarMaterialBiblioteca(NodoMaterial* &inicio);
    void guardarUsuario(Usuario* usuario);
};


#endif //PROYECTO1_ARCHIVO_H
