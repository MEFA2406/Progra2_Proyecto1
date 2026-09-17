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
    string usuario;
    string material;
    string fechaPrestamo;
public:
    Prestamo(string id, string material, string usuario, string fechaPrestamo);
    ~Prestamo();

    string getId();
    string getMaterial();
    string getCliente();
    string getFechaPrestamo();

    void setMaterial(string material);
    void setCliente(string usuario);
    void setFechaPrestamo(string fechaPrestamo);

    string toString();
};



#endif //PROYECTO1_PRESTAMO_H
