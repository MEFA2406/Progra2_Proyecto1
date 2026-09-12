
#include "Revista.h"
Revista::~Revista(){}
string Revista::getGenero() {
    return genero;
}
void Revista::setGenero(string genero) {
    this->genero = genero;
}
int Revista::getEdicion() {
    return edicion;
}
void Revista::setEdicion(int edicion) {
    this->edicion = edicion;
}