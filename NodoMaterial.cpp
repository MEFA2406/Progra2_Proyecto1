#include "NodoMaterial.h"

NodoMaterial::NodoMaterial(MaterialBiblioteca *material): material(material){
    siguienteMaterial=nullptr;
}
NodoMaterial::~NodoMaterial() {
    delete material;
}
NodoMaterial *NodoMaterial::get_siguienteMaterial()  {
    return siguienteMaterial;
}
MaterialBiblioteca *NodoMaterial::get_material() const{
    return material;
}
void NodoMaterial::set_siguienteMaterial(NodoMaterial *siguienteMaterial) {
    this->siguienteMaterial=siguienteMaterial;
}
