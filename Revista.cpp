
#include "Revista.h"
Revista::~Revista(){}

Revista::Revista(int id, string titulo, string autor, int annio,int edicion, string genero):MaterialBiblioteca(id, titulo,autor, annio) {}

string Revista::obtenerTipo() {
    return "Revista";
}
void Revista::setEdicion(int edicion) {
    this->edicion=edicion;
}
int Revista::getEdicion() {
    return edicion;
}
void Revista::setGenero(string genero) {
    this->genero=genero;
}
string Revista::getGenero() {
    return genero;
}