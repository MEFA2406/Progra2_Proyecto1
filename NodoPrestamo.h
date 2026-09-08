//
// Created by Manol on 9/6/2026.
//

#ifndef PROYECTO1_NODOPRESTAMO_H
#define PROYECTO1_NODOPRESTAMO_H
#include "Prestamo.h"

class NodoPrestamo {
private:
    Prestamo *dato;
    NodoPrestamo *siguiente;
public:
    NodoPrestamo(Prestamo *dato);
    ~NodoPrestamo();

    NodoPrestamo *getSiguiente();
    Prestamo *getDato();

    void setSiguiente(NodoPrestamo *siguiente);
    string toString();
};


#endif //PROYECTO1_NODOPRESTAMO_H