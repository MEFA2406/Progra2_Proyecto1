#ifndef PROYECTO1_MATERIALBIBLIOTECA_H
#define PROYECTO1_MATERIALBIBLIOTECA_H
#include <string>
#include "Archivo.h"
#include <sstream>
using namespace std;

class MaterialBiblioteca {
private:
    int idMaterial;
    string nombreMaterial;
    string autorMaterial;
    int annoMaterial;
public:
    MaterialBiblioteca(const int idMaterial, const string nombreMaterial, const string autorMaterial, const int annoMaterial);
    int getIdMaterial();
    string getNombreMaterial();
    string getAutorMaterial();
    int getAnnoMaterial();
    void setIdMaterial(const int idMaterial);
    void setNombreMaterial(const string nombreMaterial);
    void setAutorMaterial(const string autorMaterial);
    void setAnnoMaterial(const int annoMaterial);
    string toStringMaterial();
    ~MaterialBiblioteca();
};


#endif //PROYECTO1_MATERIALBIBLIOTECA_H
