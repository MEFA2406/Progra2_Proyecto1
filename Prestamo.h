//
// Created by Manol on 9/6/2026.
//

#ifndef PROYECTO1_PRESTAMO_H
#define PROYECTO1_PRESTAMO_H
#include "MaterialBiblioteca.h"
#include "Usuario.h"


class Prestamo {
private:
    string id;
    Usuario* usuario;
    string material;
    string fechaPrestamo;
public:
    Prestamo(string id, string material, Usuario* usuario, string fechaPrestamo);
    ~Prestamo();

    string getId();
    string getMaterial();
    Usuario* getCliente();
    string getFechaPrestamo();

    void setMaterial(string material);
    void setCliente(Usuario* usuario);
    void setFechaPrestamo(string fechaPrestamo);

    string toString();
};



#endif //PROYECTO1_PRESTAMO_H
