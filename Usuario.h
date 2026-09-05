//
// Created by manol on 5/9/2026.
//

#ifndef PROYECTO1_USUARIO_H
#define PROYECTO1_USUARIO_H

#include <string>
using namespace std;

class Usuario {
private:
    string nombre;
    string id;
public:
    Usuario(string& nombre, string& id);
    virtual ~Usuario();

    string getNombre() const;
    string getId() const;

    virtual string getTipo() const =0;
    virtual string toString() const=0;

};


#endif //PROYECTO1_USUARIO_H
