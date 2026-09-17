#ifndef PROYECTO1_ARCHIVO_H
#define PROYECTO1_ARCHIVO_H
#include "ListaMaterial.h"
#include "ListaPrestamo.h"
#include "Usuario.h"

class Archivo {
public:
    static void guardarMaterialBiblioteca(ListaMaterial* material, string nombreArchivo);
    static void guardarMaterialBibliotecaV2(ListaMaterial* material, string nombreArchivo);
    static void cargarMaterialBibliotecaV2(ListaMaterial* material, string nombreArchivo);
    static void cargarMaterialBiblioteca(ListaMaterial* material, string nombreArchivo);
    static void guardarUsuario(ListaPrestamo* prestamo, string nombreArchivo);
    static void cargarUsuario(ListaPrestamo* prestamo, string nombreArchivo);
    static bool archivoValido(string nombreArchivo);
private:
    static string siguienteEspacioS(string &linea);
    static int siguienteEspacioE(int &lineaE);
};


#endif //PROYECTO1_ARCHIVO_H
