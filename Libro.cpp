#include "Libro.h"
Libro::~Libro() {}
void Libro::setPaginas(int paginas) {
    this->paginas=paginas;
}
int Libro::getPaginas() {
    return this->paginas;
}
void Libro::setGenero(string genero) {
    this->genero=genero;
}
string Libro::getGenero() {
    return this->genero;
}