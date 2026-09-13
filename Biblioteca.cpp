//
// Created by Manol on 9/12/2026.
//

#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    //Archivo::cargarMateriales();
    //Archivo::cargarPrestamos();
}

ListaPrestamo * Biblioteca::getPrestamos() {
    return prestamos;
}

ListaMaterial * Biblioteca::getMateriales() {
    return materiales;
}

Biblioteca::~Biblioteca() {
    //Archivo::guardarPrestamos
    //Archivo::GuardarMateriales
    delete materiales;
    delete prestamos;
}

