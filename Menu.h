#ifndef PROYECTO1_MENU_H
#define PROYECTO1_MENU_H
#include <string>
#include "ListaMaterial.h"
#include "ListaPrestamo.h"
#include "MaterialBiblioteca.h"
#include "NodoMaterial.h"

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
    void buscarMaterialID();
    void buscarMaterialTitulo();
    void devolverMaterial();
    void guardarMaterial();
    void cargarMaterial();
    void cargarPrestamo();
    void guardarPrestamo();
    void inicializarDatos();
    void precargarDatos();
    public:
    Menu();
    ~Menu();
    void iniciar();
};


#endif //PROYECTO1_MENU_H
