//
// Created by Manol on 9/6/2026.
//

#include "Prestamo.h"

Prestamo::Prestamo(string id, Usuario *cliente) {
    this->id = id;
    this->cliente = cliente;
}

Prestamo::~Prestamo() {
    delete this->cliente;
}

string Prestamo::getId() {
    return this->id;
}

Usuario * Prestamo::getCliente() {
    return this->cliente;
}

string Prestamo::toString() {
    return "ID del prestamo: " + id;
}
