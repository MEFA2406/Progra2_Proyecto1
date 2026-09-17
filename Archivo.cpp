#include "Archivo.h"
#include "MaterialBiblioteca.h"
#include <fstream>

#include "Estudiante.h"
#include "Libro.h"
#include "Profesor.h"
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

void Archivo::guardarMaterialBibliotecaV2(ListaMaterial *material, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        return;
    }
    archivo << material->formatoGuardar();
    archivo.close();
}

void Archivo::cargarMaterialBibliotecaV2(ListaMaterial *material, string nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        string id,nombre,autor,annio,tipo;
        int idInt,annioInt;
        stringstream ss(linea);
        getline(ss,id,',');
        idInt = stoi(id);
        getline(ss,nombre,',');
        getline(ss,autor,',');
        getline(ss,annio,',');
        annioInt = stoi(annio);
        getline(ss,tipo,',');
        if (tipo == "Libro" ) {
            string paginas, genero;
            int paginasInt;
            getline(ss,paginas,',');
            paginasInt = stoi(paginas);
            getline(ss,genero,',');
            material->ingresarMaterial(new Libro(idInt,nombre,autor,annioInt,paginasInt,genero));
        }else if (tipo == "Tesis") {
            string grado;
            getline(ss,grado,',');
            material->ingresarMaterial(new Tesis(idInt,nombre,autor,annioInt,grado));
        }else if (tipo == "Revista") {
            string edicion,genero;
            int edicionInt;
            getline(ss,edicion,',');
            edicionInt = stoi(edicion);
            getline(ss,genero,',');
            material->ingresarMaterial(new Revista(idInt, nombre,autor,annioInt,edicionInt,genero));
        }
    }
    archivo.close();
}

void Archivo::cargarPrestamos(ListaPrestamo *prestamos, string nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        Usuario* cliente=nullptr;
        string idPrestamo,idCliente,idMaterial,fecha,nombre,tipo;
        stringstream ss(linea);
        getline(ss,idPrestamo,',');
        getline(ss,fecha,',');
        getline(ss,idMaterial,',');
        getline(ss,idCliente,',');
        getline(ss,nombre,',');
        getline(ss,tipo,',');
        if (tipo == "Profesor") {
            string departamento;
            getline(ss,departamento,',');
            cliente = new Profesor(departamento,nombre,idCliente);
        }else if (tipo == "Estudiante") {
            string carrera;
            getline(ss,carrera,',');
            cliente = new Estudiante(carrera,nombre,idCliente);
        }
        if (cliente != nullptr) {
            prestamos->agregarPrimero(new Prestamo(idPrestamo,idMaterial,cliente,fecha));
        }
    }
    archivo.close();
}

void Archivo::guardarPrestamos(ListaPrestamo *prestamos, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        return;
    }
    archivo<< prestamos->formatoGuardar();
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
