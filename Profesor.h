//
// Created by Manol on 9/14/2026.
//

#ifndef PROYECTO1_PROFESOR_H
#define PROYECTO1_PROFESOR_H
#include "Usuario.h"


class Profesor :public Usuario{
private:
    string departamento;
public:
    Profesor(string departamento, string nombre,string id);

    string getTipo() const override;
    string getDepartamento() const;
    string toString() const override;
};


#endif //PROYECTO1_PROFESOR_H