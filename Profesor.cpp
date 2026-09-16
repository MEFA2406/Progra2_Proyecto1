//
// Created by Manol on 9/14/2026.
//

#include "Profesor.h"

Profesor::Profesor(string departamento, string nombre, string id) : Usuario(nombre,id){
}

string Profesor::getTipo() const {
    return "Profesor";
}

string Profesor::getDepartamento() const {
    return departamento;
}

string Profesor::toString() const {
    return "ID: "+id+"Nombre: "+nombre+" departamento: "+departamento;
}
