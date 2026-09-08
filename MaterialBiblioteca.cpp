#include "MaterialBiblioteca.h"
MaterialBiblioteca::MaterialBiblioteca( int idMaterial, string nombreMaterial, string autorMaterial, int annoMaterial) {
    this->idMaterial = idMaterial;
    this->nombreMaterial = nombreMaterial;
    this->autorMaterial = autorMaterial;
    this->annoMaterial = annoMaterial;
}
int MaterialBiblioteca::getIdMaterial() {
    return idMaterial;
}
void MaterialBiblioteca::setIdMaterial(const int idMaterial) {
    this->idMaterial = idMaterial;
}
string MaterialBiblioteca::getNombreMaterial() {
    return nombreMaterial;
}
void MaterialBiblioteca::setNombreMaterial(const string nombreMaterial) {
    this->nombreMaterial = nombreMaterial;
}
string MaterialBiblioteca::getAutorMaterial() {
    return autorMaterial;
}
void MaterialBiblioteca::setAutorMaterial(const string autorMaterial) {
    this->autorMaterial = autorMaterial;
}
int MaterialBiblioteca::getAnnoMaterial() {
    return annoMaterial;
}
void MaterialBiblioteca::setAnnoMaterial(const int annoMaterial) {
    this->annoMaterial = annoMaterial;
}
MaterialBiblioteca::~MaterialBiblioteca() {}

string MaterialBiblioteca::toStringMaterial() {
   stringstream ss;
    ss<<"Titulo:"<<nombreMaterial<<endl;
    ss<<"Autor:"<<autorMaterial<<endl;
    ss<<"A"<<char(164)<<"o:"<<annoMaterial<<endl;
    return ss.str();
}