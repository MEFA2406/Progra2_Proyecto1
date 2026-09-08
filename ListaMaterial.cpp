#include "ListaMaterial.h"
ListaMaterial::ListaMaterial() {
    inicio = NULL;
    actual = NULL;
    ultimo = NULL;
}

ListaMaterial::ListaMaterial(NodoMaterial *inicio, NodoMaterial *ultimo, NodoMaterial *actual) {
    this->inicio = inicio;
    this->ultimo = ultimo;
    this->actual = actual;
}
void ListaMaterial::setInicio(NodoMaterial *inicio) {
    this->inicio = inicio;
}
NodoMaterial *ListaMaterial::getInicio() const {
    return inicio;
}

void ListaMaterial::setActual(NodoMaterial *actual) {
    this->actual = actual;
}
NodoMaterial *ListaMaterial::getActual() const {
    return actual;
}

string ListaMaterial::toStringMaterial() {
    std::ostringstream s;
    actual=inicio;
    while (actual!=NULL) {
        s<<actual->toString();
        actual=actual->get_siguienteMaterial();
    }
    return s.str();
}