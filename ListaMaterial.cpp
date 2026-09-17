#include "ListaMaterial.h"
#include <iostream>
ListaMaterial::ListaMaterial() {
    inicio = nullptr;
    actual = nullptr;
}

ListaMaterial::ListaMaterial(NodoMaterial *inicio, NodoMaterial *actual) {
    this->inicio = inicio;
    this->actual = actual;
}
ListaMaterial::~ListaMaterial() {
    if (inicio != nullptr) {
        removerMaterial();
    }
}

string ListaMaterial::formatoGuardar() {
    actual = inicio;
    stringstream ss;
    while (actual != nullptr) {
        ss<<actual->get_material()->formatoGuardar();
        if (actual->get_siguienteMaterial() != nullptr) {
            ss<<endl;
        }
        actual = actual->get_siguienteMaterial();
    }
    cout<<ss.str()<<endl;
    return ss.str();
}

NodoMaterial *ListaMaterial::getActual() {
    return actual;
}
NodoMaterial *ListaMaterial::getInicio() {
    return inicio;
}
void ListaMaterial::ingresarMaterial(MaterialBiblioteca* material) {
    auto actual= new NodoMaterial(material);
    actual->set_siguienteMaterial(inicio);
    inicio = actual;
}

void ListaMaterial::removerMaterial() {
    if (inicio != nullptr) {
        NodoMaterial* actual = inicio;
        inicio = inicio->get_siguienteMaterial();
        delete actual;
    }
}

MaterialBiblioteca *ListaMaterial::obtenerMaterialId(int id) {
    NodoMaterial *actual = inicio;
    while (actual != nullptr) {
        if (actual->get_material()->getIdMaterial() == id) {
            return actual->get_material();
        }
        actual = actual->get_siguienteMaterial();
    }
    return nullptr;
}
MaterialBiblioteca *ListaMaterial::obtenerMaterialTitulo(string titulo) {
    NodoMaterial *actual = inicio;
    while (actual != nullptr) {
        if (actual->get_material()->getNombreMaterial() == titulo) {
            return actual->get_material();
        }
        actual = actual->get_siguienteMaterial();
    }
    return nullptr;
}

string ListaMaterial::toStringMaterial() {
    stringstream ss;
    NodoMaterial *actual = inicio;
    if (actual == nullptr) {
        ss<<"No hay material registrado"<<endl;
        return ss.str();
    }
    while (actual != nullptr) {
        ss<<actual->get_material()->toStringMaterial()<<endl;
        actual = actual->get_siguienteMaterial();
    }
    return ss.str();
}

