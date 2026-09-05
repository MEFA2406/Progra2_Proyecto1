//
// Created by Manol on 9/5/2026.
//

#include "Estudiante.h"

Estudiante::Estudiante(string carrera, string nombre, string id): Usuario(nombre, id), carrera(carrera) {
}

Estudiante::~Estudiante() {
}

string Estudiante::getCarrera() const {
    return carrera;
}

string Estudiante::getTipo() const {
    return "Estudiante";
}

string Estudiante::toString() const {
    return "Nombre: " + nombre + " Carrera: " + carrera;
}
