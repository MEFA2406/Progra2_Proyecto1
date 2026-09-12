#ifndef PROYECTO1_MENU_H
#define PROYECTO1_MENU_H
#include "MaterialBiblioteca.h"
#include "NodoMaterial.h"
#include "Archivo.h"
#include <string>

using namespace std;

class Menu {
private:
    NodoMaterial* inicio;
    Archivo* guardarMaterialBiblioteca;
public:
    Menu(Archivo* guardarMaterialBiblio);
    ~Menu();
    string registrarMaterial(string titulo, string autor, int annio, int id);
    string listarMaterial() const;
    string devolverMaterial(int id);
    string guardarMaterial();
    string cargarMaterial();
    string registrarPrestamo(string titulo, string autor, int annio, int id, string usuario, int idUsuario);
};


#endif //PROYECTO1_MENU_H
