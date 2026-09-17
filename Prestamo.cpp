//
// Created by Manol on 9/6/2026.
//

#include "Prestamo.h"
#include "sstream"

Prestamo::Prestamo(string id, string material, Usuario* usuario, string fecha) {
    this->id = id;
    this->material = material;
    this->usuario = usuario;
    this->fechaPrestamo = fecha;
}

Prestamo::~Prestamo() {
}

string Prestamo::getId() {
    return this->id;
}

string Prestamo::getMaterial() {
    return this->material;
}

string Prestamo::getFechaPrestamo() {
    return this->fechaPrestamo;
}

void Prestamo::setMaterial(string material) {
    this->material = material;
}

void Prestamo::setCliente(Usuario* usuario) {
    this->usuario = usuario;
}

void Prestamo::setFechaPrestamo(string fechaPrestamo) {
    this->fechaPrestamo = fechaPrestamo;
}

Usuario* Prestamo::getCliente() {
    return this->usuario;
}

string Prestamo::toString() {
    stringstream ss;
    ss << "ID: " << this->id << endl;
    ss<<"Fecha del prestamo: "<<this->fechaPrestamo<<endl;
    ss << "ID del material: " << this->material<<endl;
    ss<<"Informacion del usuario:\n"<<this->usuario->toString();
    return ss.str();
}

string Prestamo::formatoGuardar() {
    stringstream ss;
    ss<<id<<","<<fechaPrestamo<<","<<material<<","<<usuario->formatoGuardar();
    return ss.str();
}
