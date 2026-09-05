//
// Created by Manol on 9/5/2026.
//

#ifndef PROYECTO1_ESTUDIANTE_H
#define PROYECTO1_ESTUDIANTE_H

#include "Usuario.h"

class Estudiante : public Usuario {
private:
    string carrera;
public:
    Estudiante(string carrera,string nombre,string id);
    ~Estudiante();

    string getCarrera() const;
    string getTipo() const override;
    string toString() const override;

};


#endif //PROYECTO1_ESTUDIANTE_H