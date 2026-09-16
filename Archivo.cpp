#include "Archivo.h"
#include "MaterialBiblioteca.h"
#include <fstream>

#include "Libro.h"
#include "Revista.h"
#include "Tesis.h"

string Archivo::siguienteEspacioS(string &linea) {
    int pos = linea.find(',');
    string campo;
    if (pos == (int) string::npos) {
        campo = linea;
        linea = "";
    } else {
        campo = linea.substr(0, pos);
        linea = linea.substr(pos + 1);
    }
    return campo;
}
int Archivo::siguienteEspacioE(int &posicion) {
    static string linea = "";
    if (linea.empty()) {
        linea = to_string(posicion);
    } else {
        linea += "," + to_string(posicion);
    }
    int pos = linea.find(',');
    string campo;

    if (pos == (int) string::npos) {
        campo = linea;
        linea = "";
    } else {
        campo = linea.substr(0, pos);
        linea = linea.substr(pos + 1);
    }
    return stoi(campo);
}
void Archivo::guardarMaterialBiblioteca(ListaMaterial *lista, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        return;
    }
    NodoMaterial *actual = lista->getInicio();
    while (actual != nullptr) {
        MaterialBiblioteca *material = actual->get_material();
        archivo << material->getIdMaterial() << "|" << material->getNombreMaterial() << "|" << material->getAutorMaterial() << "1"
                << material->getAnnoMaterial() << endl;
        actual = actual->get_siguienteMaterial();
    }
    archivo.close();
}
void Archivo::cargarMaterialBiblioteca(ListaMaterial *lista, string nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        return;
    }
    string linea;
    int lineaE;
    while (getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }
        int id = siguienteEspacioE(lineaE);
        string titulo = siguienteEspacioS(linea);
        string autor = siguienteEspacioS(linea);
        int annio = siguienteEspacioE(lineaE);
        string tipo = siguienteEspacioS(linea);
        string genero = siguienteEspacioS(linea);
        string grado= siguienteEspacioS(linea);
        int edicion = siguienteEspacioE(lineaE);
        int paginas = siguienteEspacioE(lineaE);

        MaterialBiblioteca *material = nullptr;
        if (tipo == "Revista") {
            material = new Revista(id,titulo, autor,annio, edicion,genero);
        } else if (tipo == "Libro") {
            material = new Libro(id, titulo, autor, annio, paginas, genero);
        }else if (tipo == "Tesis") {
            material = new Tesis(id, titulo, autor, annio, grado);
        }

        if (material != nullptr) {
            lista->ingresarMaterial(material);
        }
    }
    archivo.close();
}
void Archivo::guardarUsuario(ListaPrestamo *lista, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        return;
    }
    NodoPrestamo *actual = lista->getPrimero();
    while (actual != nullptr) {
        Prestamo *prestamo = actual->getDato();
        archivo << prestamo->getId() << "|" << prestamo->getCliente() << "|"<< prestamo->getMaterial()<<"|"<<prestamo->getFechaPrestamo() << endl;
        actual = actual->getSiguiente();
    }
    archivo.close();
}

void Archivo::cargarUsuario(ListaPrestamo *prestamo, string nombreArchivo) {
}

bool Archivo::archivoValido(string nombreArchivo) {
    return true;
}
