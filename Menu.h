#ifndef PROYECTO1_MENU_H
#define PROYECTO1_MENU_H
#include "MaterialBiblioteca.h"
#include "NodoMaterial.h"
#include "Archivo.h"
#include "Prestamo.h"
#include "Tesis.h"

#include <string>

#include "ListaMaterial.h"
#include "ListaPrestamo.h"

using namespace std;

class Menu {
private:
    ListaMaterial* listaMaterial;
    ListaPrestamo* listaPrestamo;
    string archivoMaterial;
    string archivoPrestamo;
    void mostrarMenuPrincipal();
    void menuMaterial();
    void menuPrestamo();
    void registrarPrestamo();
    void registrarMaterial();
    void listarMaterial();
    void buscarMaterial();
    void devolverMaterial();
    void guardarMaterial();
    void cargarMaterial();
    void cargarPrestamo();
    void guardarPrestamo();
    void inicializarDatos();
    public:
    Menu();
    ~Menu();
    void iniciar();
};


#endif //PROYECTO1_MENU_H
