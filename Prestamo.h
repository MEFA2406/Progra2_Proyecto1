//
// Created by Manol on 9/6/2026.
//

#ifndef PROYECTO1_PRESTAMO_H
#define PROYECTO1_PRESTAMO_H
#include "Usuario.h"
#include "MaterialBiblioteca.h"

class Prestamo {
private:
    string id;
    Usuario* usuario;
    MaterialBiblioteca* material;
    string fechaPrestamo;
public:
    Prestamo(string id, MaterialBiblioteca* material, Usuario* usuario, string fechaPrestamo);
    ~Prestamo();

    string getId();
    MaterialBiblioteca* getMaterial();
    Usuario* getCliente();
    string getFechaPrestamo();

    void setMaterial(MaterialBiblioteca* material);
    void setCliente(Usuario* usuario);
    void setFechaPrestamo(string fechaPrestamo);

    string toString();
};



#endif //PROYECTO1_PRESTAMO_H
