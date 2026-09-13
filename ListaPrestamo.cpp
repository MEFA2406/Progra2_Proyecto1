//
// Created by Manol on 9/6/2026.
//

#include "ListaPrestamo.h"
#include <sstream>

ListaPrestamo::ListaPrestamo() {
    primero = nullptr;
}

ListaPrestamo::~ListaPrestamo() {
    while (primero != nullptr) {
        eliminarPrimero();
    }
}

void ListaPrestamo::eliminarPrimero() {
    if (primero != nullptr) {
        NodoPrestamo* actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}

bool ListaPrestamo::eliminarPrestamoId(string id) {
    NodoPrestamo* actual = primero;

    if (primero != nullptr) {
        if (primero->getDato()->getId() == id) {
            eliminarPrimero();
            return true;
        }else {
            while (actual->getSiguiente() != nullptr && actual->getSiguiente()->getDato()->getId() != id) {
                actual = actual->getSiguiente();
            }
            if (actual->getSiguiente() != nullptr) {
                NodoPrestamo* temp = actual->getSiguiente();
                actual->setSiguiente(temp->getSiguiente());
                delete temp;
                return true;
            }
        }

    }
    return false;
}

void ListaPrestamo::agregarPrimero(Prestamo *elPrestamo) {
    auto actual = new NodoPrestamo(elPrestamo);
    actual->setSiguiente(primero);
    primero = actual;
}

string ListaPrestamo::toString() {
    stringstream ss;
    NodoPrestamo* actual = primero;
    while (actual!=nullptr) {
        ss<<actual->toString()<<endl;
        actual = actual->getSiguiente();
    }
    return ss.str();
}
