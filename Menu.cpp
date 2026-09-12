#include "Menu.h"

#include <iostream>
using namespace std;
Menu::Menu(Archivo* archivo): inicio(nullptr), guardarMaterialBiblioteca(archivo) {}

string Menu::registrarMaterial(string titulo, string autor, int annio, int id) {
MaterialBiblioteca* nuevoMaterial=new MaterialBiblioteca(id, titulo, autor,annio);
NodoMaterial* nuevo = new NodoMaterial();
    cout<<"-------------------------------------"<<endl;
    cout<<"     REGISTRO DE NUEVO MATERIAL"<<endl;
    cout<<"-------------------------------------"<<endl;
    if (inicio==nullptr) {
        inicio=nuevo;
    }
    else {
        NodoMaterial* actual=inicio;
        while (actual->get_siguienteMaterial()!=nullptr) {
            actual=actual->get_siguienteMaterial();
        }
        actual->set_siguienteMaterial(nuevo);
    }
    if (guardarMaterialBiblioteca!=nullptr) {
        guardarMaterialBiblioteca->guardarMaterialBiblioteca(nuevo);
    }

}

string Menu::devolverMaterial(int id) {
    cout<<"------------------------------------"<<endl;
    cout<<"     DEVOLUCION DE MATERIAL"<<endl;
    cout<<"------------------------------------"<<endl;
    if (inicio==nullptr) {
        cout<<"No hay material en la biblioteca para devolver actualmente"<<endl;
    }
    NodoMaterial* actual = inicio;
    NodoMaterial* nuevo=nullptr;
    bool encontrado=false;
    while (actual != nullptr) {
        MaterialBiblioteca* material;
        //material=actual->get_siguienteMaterial();
        if (material != nullptr) {
            encontrado=true;
            break;
        }
        nuevo=actual;
        actual=actual->get_siguienteMaterial();
    }
    if (!encontrado) {
        cout<<"No hay material registrado con ese id:"<<id<<endl;
    }
    //Desvincular nodo con la lista
    if (nuevo==nullptr) {
        inicio=inicio->get_siguienteMaterial();
    }else {
        nuevo->set_siguienteMaterial(actual->get_siguienteMaterial());
    }
    //Liberar memoria en Nodo y en MaterialBiblioteca*
    delete actual;
    //sincronizar el cambio con el almacenamiento en archivo
    if (guardarMaterialBiblioteca != nullptr) {
        guardarMaterialBiblioteca->reescribirMaterialBiblioteca(inicio);
    }
    cout << "Material con ID " << id << " devuelto y eliminado exitosamente." << endl;
}
string Menu::listarMaterial() const{
    cout<<"-------------------------------------"<<endl;
    cout<<"         LISTA DE MATERIALES"<<endl;
    cout<<"-------------------------------------"<<endl<<endl;
if (inicio==nullptr) {
    cout<<"No hay material registrado actualmente"<<endl;
    return 0;
}
    NodoMaterial* actual = inicio;
    while (actual != nullptr) {
       MaterialBiblioteca* material;
        //material = actual->get_siguienteMaterial();
        if (material != nullptr) {
            cout << "ID: " << material->getIdMaterial() << " | "
                 << "Título: " << material->getNombreMaterial() << " | "
                 << "Autor: " << material->getAutorMaterial() << " | "
                 << "Año: " << material->getAnnoMaterial() << endl;
        }
        actual = actual->get_siguienteMaterial();
    }
}
string Menu::guardarMaterial() {
if (guardarMaterialBiblioteca!=nullptr) {
    guardarMaterialBiblioteca->reescribirMaterialBiblioteca(inicio);
    cout << "Estado actual de la lista guardado en el archivo correctamente." << endl;
}
}
string Menu::cargarMaterial() {
    if (guardarMaterialBiblioteca!=nullptr) {
        guardarMaterialBiblioteca->cargarMaterialBiblioteca(inicio);
        cout << "Materiales cargados desde el archivo correctamente." << endl;
    }
}

string Menu::registrarPrestamo(string titulo, string autor, int annio, int id, string usuario, int idUsuario) {
}

Menu::~Menu() {
    NodoMaterial* actual = inicio;
    while (actual != nullptr) {
        NodoMaterial* siguiente = actual->get_siguienteMaterial();
        actual=siguiente;
    }
}
