//
// Created by Manol on 9/6/2026.
//

#ifndef PROYECTO1_PRESTAMO_H
#define PROYECTO1_PRESTAMO_H
#include "Usuario.h"

class Prestamo {
private:
    string id;
    Usuario* cliente;
    //material
public:
    Prestamo(string id, Usuario* cliente);
    ~Prestamo();

    string getId();
    Usuario* getCliente();

    string toString();
};



#endif //PROYECTO1_PRESTAMO_H
