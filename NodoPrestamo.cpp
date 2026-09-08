//
// Created by Manol on 9/6/2026.
//

#include "NodoPrestamo.h"

NodoPrestamo::NodoPrestamo(Prestamo *dato) : dato(dato){
    siguiente = nullptr;
}

NodoPrestamo::~NodoPrestamo() {
    delete dato;
}

NodoPrestamo * NodoPrestamo::getSiguiente() {
    return siguiente;
}

Prestamo * NodoPrestamo::getDato() {
    return dato;
}

void NodoPrestamo::setSiguiente(NodoPrestamo *siguiente) {
    this->siguiente = siguiente;
}

string NodoPrestamo::toString() {
    return dato->toString();
}
