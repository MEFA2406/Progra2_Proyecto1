//
// Created by Manol on 9/12/2026.
//

#ifndef PROYECTO1_BIBLIOTECA_H
#define PROYECTO1_BIBLIOTECA_H

#include "ListaMaterial.h"
#include "ListaPrestamo.h"


class Biblioteca {
private:
    ListaPrestamo *prestamos;
    ListaMaterial *materiales;
public:
    Biblioteca();
    ListaPrestamo *getPrestamos();
    ListaMaterial *getMateriales();
    ~Biblioteca();

};


#endif //PROYECTO1_BIBLIOTECA_H