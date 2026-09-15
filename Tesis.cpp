
#include "Tesis.h"
Tesis::~Tesis() {}

Tesis::Tesis(int id, string titulo, string autor, int annio, string grado) :MaterialBiblioteca(id, titulo, autor, annio) {}

string Tesis::getGrado() {
 return grado;
}
void Tesis::setGrado(string grado) {
 this->grado = grado;
}
string Tesis::obtenerTipo() {
 return "Tesis";
}
