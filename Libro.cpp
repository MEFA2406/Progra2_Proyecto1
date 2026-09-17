#include "Libro.h"
Libro::~Libro() {}
Libro::Libro(int id, string titulo, string autor, int annio, int paginas, string genero) :MaterialBiblioteca(id, titulo,autor,annio),paginas(paginas),genero(genero) {}
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

string Libro::obtenerTipo() {
    return "Libro";
}

string Libro::toStringMaterial() {
    return MaterialBiblioteca::toStringMaterial();
}

string Libro::formatoGuardar() {
    stringstream ss;
    ss<<MaterialBiblioteca::formatoGuardar()<<paginas<<","<<genero;
    return ss.str();
}
