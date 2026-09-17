
#include "Tesis.h"
Tesis::~Tesis() {}

Tesis::Tesis(int id, string titulo, string autor, int annio, string grado) :MaterialBiblioteca(id, titulo, autor, annio),grado(grado) {}

string Tesis::getGrado() {
 return grado;
}
void Tesis::setGrado(string grado) {
 this->grado = grado;
}
string Tesis::obtenerTipo() {
 return "Tesis";
}

string Tesis::toStringMaterial() {
 return MaterialBiblioteca::toStringMaterial();
}

string Tesis::formatoGuardar() {
 stringstream ss;
 ss<<MaterialBiblioteca::formatoGuardar()<<grado;
 return ss.str();
}
