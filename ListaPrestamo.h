//
// Created by Manol on 9/6/2026.
//

#ifndef PROYECTO1_LISTAPRESTAMO_H
#define PROYECTO1_LISTAPRESTAMO_H
#include "NodoPrestamo.h"

class ListaPrestamo {
private:
    NodoPrestamo *primero;
public:
    ListaPrestamo();
    ~ListaPrestamo();

    void eliminarPrimero();
    bool eliminarPrestamoId(string id);

    void agregarPrimero(Prestamo *elPrestamo);
    string toString();

};


#endif //PROYECTO1_LISTAPRESTAMO_H