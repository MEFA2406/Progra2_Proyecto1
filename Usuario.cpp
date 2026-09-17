//
// Created by sualf on 5/9/2026.
//

#include "Usuario.h"
#include <sstream>

Usuario::Usuario(string nombre, string id): nombre(nombre), id(id) {
}

Usuario::~Usuario() {
}

string Usuario::getNombre() const {
    return nombre;
}

string Usuario::getId() const {
    return id;
}

string Usuario::formatoGuardar() {
    stringstream ss;
    ss<<id<<","<<nombre<<","<<getTipo()<<",";
    return ss.str();
}
