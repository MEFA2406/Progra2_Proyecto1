//
// Created by sualf on 5/9/2026.
//

#include "Usuario.h"

Usuario::Usuario(string& nombre, string& id): nombre(nombre), id(id) {
}

Usuario::~Usuario() {
}

string Usuario::getNombre() const {
    return nombre;
}

string Usuario::getId() const {
    return id;
}
