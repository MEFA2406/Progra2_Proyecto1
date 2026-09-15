#include "Menu.h"
#include "MaterialBiblioteca.h"
#include "Archivo.h"
#include "Prestamo.h"
#include "Tesis.h"
#include "Revista.h"
#include "Libro.h"
#include <cctype>
#include <iostream>

Menu::Menu() {
    listaMaterial=new ListaMaterial();
    listaPrestamo=new ListaPrestamo();
    archivoMaterial="material.txt";
    archivoPrestamo="prestamo.txt";
    inicializarDatos();
}
Menu::~Menu() {
    delete listaMaterial;
    delete listaPrestamo;
}
//Inicia los datos guardados en archivo
void Menu::inicializarDatos() {
    bool hayMaterial= Archivo::archivoValido(archivoMaterial);
    bool hayPrestamo= Archivo::archivoValido(archivoPrestamo);
    if (hayMaterial && hayPrestamo) {
        Archivo::cargarMaterialBiblioteca(listaMaterial, archivoMaterial);
        Archivo::cargarUsuario(listaPrestamo, archivoPrestamo);
    } else {
    precargarDatos();
    }
}
//Guarda el material
void Menu::guardarMaterial() {
    Archivo::guardarMaterialBiblioteca(listaMaterial, archivoMaterial);
    cout << "Datos guardados correctamente"<<endl;
}
//Carga el material
void Menu::cargarMaterial() {
    delete listaMaterial;
    listaMaterial = new ListaMaterial();
    Archivo::cargarMaterialBiblioteca(listaMaterial, archivoMaterial);
    cout << "Datos cargados correctamente." << endl;
}
//guarda los prestamos
void Menu::guardarPrestamo() {
    Archivo::guardarUsuario(listaPrestamo, archivoPrestamo);
    cout << "Datos guardados correctamente"<<endl;
}
//carga los prestamos
void Menu::cargarPrestamo() {
    delete listaPrestamo;
    listaPrestamo = new ListaPrestamo();
    Archivo::cargarUsuario(listaPrestamo, archivoPrestamo);
    cout << "Datos cargados correctamente." << endl;
}
//Menu de inicio
void Menu::mostrarMenuPrincipal() {
    cout << "====================================" << endl;
    cout << "        BIBLIOTECA UNIVERSITARIA " << endl;
    cout << "====================================" << endl;
    cout << endl;
    cout << "1. Gestion de Material" << endl;
    cout << "2. Gestion de Prestamos" << endl;
    cout << "3. Guardar Datos" << endl;
    cout << "4. Cargar Datos" << endl;
    cout << "0. Salir" << endl;
    cout << endl;
    cout << "Seleccione una opcion: ";
}
//Inicia el menu y lo conecta con el main
void Menu::iniciar() {
    int opc=-1;
    while (opc!=0) {
        mostrarMenuPrincipal();
        cin>>opc;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000,'\n');
            opc = -1;
            cout << "Opcion invalida." << endl;
            continue;
        }
        switch (opc) {
            case 1:
                menuMaterial();
                break;
            case 2:
                menuPrestamo();
                break;
            case 3:
                guardarMaterial();
                guardarPrestamo();
                break;
            case 4:
                cargarMaterial();
                cargarPrestamo();
                break;
            case 0:
                cout << "Hasta pronto." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    }
}
//Menu de prestamos
void Menu::menuPrestamo() {
int opcPres=-1;
    while (opcPres!=0) {
        cout<<"1. Registrar prestamo"<<endl;
        cout<<"2. Devolver prestamo"<<endl;
        cout<<"3. Guardar prestamo"<<endl;
        cout<<"4. Cargar prestamo"<<endl;
        cout<<"0. Regresar"<<endl;
        cout<<endl;
        cout<<"Seleccione una opcion: "<<endl;
        cin>>opcPres;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000,'\n');
            opcPres = -1;
            cout << "Opcion invalida." << endl;
            continue;
        }
        switch (opcPres) {
            case 1:
                registrarPrestamo();
                break;
            case 2:
                devolverMaterial();
                break;
            case 3:
               guardarPrestamo();
                break;
            case 4:
               cargarPrestamo();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    }


}
//menu de material de bilioteca
void Menu::menuMaterial() {
    int opcMat=-1;
    while (opcMat!=0) {
        cout<<"1. Registrar material"<<endl;
        cout<<"2. Listar material"<<endl;
        cout<<"3. Buscar material por Id"<<endl;
        cout<<"4. Buscar material por titulo"<<endl;
        cout<<"5. Guardar Material"<<endl;
        cout<<"6. Cargar material"<<endl;
        cout<<"0. Regresar"<<endl;
        cout<<endl;
        cout<<"Seleccione una opcion: "<<endl;
        cin>>opcMat;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000,'\n');
            opcMat = -1;
            cout << "Opcion invalida." << endl;
            continue;
        }
        switch (opcMat) {
            case 1:
                registrarMaterial();
                break;
            case 2:
                listarMaterial();
                break;
            case 3:
                buscarMaterialID();
                break;
            case 4:
                buscarMaterialTitulo();
                break;
            case 5:
                guardarMaterial();
                break;
            case 6:
                cargarMaterial();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    }
}
//registra material nuevo
void Menu::registrarMaterial() {
    string autor, titulo, tipo, genero, grado;
    int id, annio, paginas, edicion;
    cin.ignore(10000, '\n');
    cout<<"Ingrese el tipo de material: "<<endl;
    cin>>tipo;

    string tipoMaterial=tipo;
    for (int i=0; i<tipo.length(); i++) {
        tipoMaterial[i] = tolower(tipo[i]);
    }
    MaterialBiblioteca* material=nullptr;
    if (tipo=="Revista"||tipo=="revista") {
        material=new Revista(id,titulo, autor,annio, edicion,genero);
    }
    else if (tipo=="Libro"||tipo=="libro") {
        material=new Libro(id, titulo, autor, annio, paginas, genero);
    }
    else if (tipo=="Tesis"||tipo=="tesis") {
        material=new Tesis(id, titulo, autor, annio, grado);
    } else {
        cout<<"Opcion invalida."<<endl;
        return;
    }
    listaMaterial->ingresarMaterial(material);
    cout<<"Material registrado correctamente."<<endl;
}
//registra prestamos
void Menu::registrarPrestamo() {
    string id, usuario, material, fechaPrestamo;

    cout << "Id del usuario: ";
    getline(cin, id);
    cout << "Nombre de usuario: ";
    getline(cin, usuario);
    cout << "Material: ";
    getline(cin, material);
    cout << "Fecha del Prestamo: ";
    getline(cin, fechaPrestamo);
    Prestamo *prestamo = new Prestamo(id, usuario, material, fechaPrestamo);
    listaPrestamo->agregarPrimero(prestamo);

    cout << "Prestamo registrado correctamente." << endl;
}
//devuelve material y elimina prestamos
void Menu::devolverMaterial() {
    int idMaterial;
    string id;
    cout << "Id del usuario: ";
    cin>>id;
    cout << "Id del material que desea devolver: ";
    cin>>idMaterial;
    listaPrestamo->eliminarPrestamoId(id,idMaterial);
    cout << "Prestamo eliminado correctamente. El material ha sido devuelto." << endl;

}
//muestra una lista del material existente
void Menu::listarMaterial() {
    cout<<listaMaterial->toStringMaterial();
}
//busca si existe algun titulo o id de material
void Menu::buscarMaterialID() {
    int id;
    cin.ignore(10000, '\n');
    cout << "Id del material que desea buscar: : ";
    cin>>id;
    MaterialBiblioteca *material = listaMaterial->obtenerMaterialId(id);
    if (material == nullptr) {
        cout << "No se encontro ningun material con ese id" << endl;
        return;
    }
    cout << material->toStringMaterial() << endl;
}

void Menu::buscarMaterialTitulo() {
    string titulo;
    cin.ignore(10000, '\n');
    cout << "Titulo del material que desea buscar: : ";
    getline(cin, titulo);
    MaterialBiblioteca *material = listaMaterial->obtenerMaterialTitulo(titulo);
    if (material == nullptr) {
        cout << "No se encontro ningun material con ese titulo" << endl;
        return;
    }
    cout << material->toStringMaterial() << endl;
}

