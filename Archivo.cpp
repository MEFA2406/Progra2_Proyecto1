#include "Archivo.h"
#include <fstream>

void Archivo::guardarMaterialBiblioteca(MaterialBiblioteca *material) {
    ofstream archivo("biblioteca.txt", ios::app);
    if (archivo.is_open()) {
        archivo<<material->getNombreMaterial()<<endl;
        archivo<<material->getAutorMaterial()<<endl;
        archivo<<material->getIdMaterial()<<endl;
        archivo<<material->getAnnoMaterial()<<endl;
        archivo.close();
    }
}
void Archivo::reescribirMaterialBiblioteca(NodoMaterial* inicio) {
    ofstream archivo("biblioteca.txt",ios::trunc);
    if (archivo.is_open()) {
        NodoMaterial* actual = inicio;
        while (actual != nullptr) {
            MaterialBiblioteca* material = actual->get_material();
            if (material != nullptr) {
                archivo << material->getIdMaterial() << endl
                        << material->getNombreMaterial() << endl
                        << material->getAutorMaterial() << endl
                        << material->getAnnoMaterial() << endl;
            }
            actual = actual->get_siguienteMaterial();
        }
        archivo.close();
    }
}

void Archivo::cargarMaterialBiblioteca(NodoMaterial *&inicio) {
    ifstream archivo("biblioteca.txt", ios::in);
    if (!archivo.is_open()) {
        return;
    }
    string line;
    while (getline(archivo, line)) {
        stringstream ss(line);
        string sID, titulo, autor, sAnno;
        if (getline(ss, sID, '|') &&
            getline(ss, titulo, '|') &&
            getline(ss, autor, '|') &&
            getline(ss, sAnno)) {
            int id=stoi(sID);
            int anno=stoi(sAnno);
            MaterialBiblioteca* material = new MaterialBiblioteca(id,titulo,autor,anno);
            NodoMaterial* nuevo = new NodoMaterial(material);
            if (inicio == nullptr) {
                inicio=nuevo;
            } else {
                NodoMaterial* actual = inicio;
                while (actual->get_siguienteMaterial() != nullptr) {
                    actual=actual->get_siguienteMaterial();
                }
                actual->set_siguienteMaterial(nuevo);
            }
            }
    }
    archivo.close();
}
void Archivo::guardarUsuario(Usuario *usuario) {}
