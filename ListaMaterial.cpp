#include "ListaMaterial.h"
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
        removeInicio();
    }
}

void ListaMaterial::insertInicio(MaterialBiblioteca* material) {
    auto actual= new NodoMaterial(material);
    actual->set_siguienteMaterial(inicio);
    inicio = actual;
}

void ListaMaterial::removeInicio() {
    if (inicio != nullptr) {
        NodoMaterial* actual = inicio;
        inicio = inicio->get_siguienteMaterial();
        delete actual;
    }
}

bool ListaMaterial::findMaterialID(int id, string titulo) {
    actual = inicio;
    while (actual!=nullptr && actual->get_siguienteMaterial()!=nullptr) {
        if (actual->get_material()->getIdMaterial()==id||actual->get_material()->getNombreMaterial()==titulo) {
            return true;
        }
        actual = actual->get_siguienteMaterial();
    }
    return false;
}
