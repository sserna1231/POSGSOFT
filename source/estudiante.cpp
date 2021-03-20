#include "estudiante.h"

Estudiante::Estudiante( int id ){
    this->id = id;
}

Estudiante::Estudiante( string nombre, int id, int celular, string email ){
    this->nombre = nombre;
    this->id = id;
    this->celular = celular;
    this->email = email;
}

void Estudiante::llenarEstudiante(){
    string nombre, email;
    int celular;

    cout << endl;

    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline( cin, nombre );

    cout << "Telefono celular: ";
    cin >> celular;

    cout << "Ingrese el email: ";
    cin >> email;

    this->nombre = nombre;
    this->celular = celular;
    this->email = email;

    cout << endl;
}

void Estudiante::mostrarEstudiante(){
    cout << endl;

    cout << "* Nombre: " << this->nombre << endl;
    cout << "* id: " << this->id << endl;
    cout << "* Celular: " << this->celular << endl;
    cout << "* Email: " << this->email << endl;

    cout << endl;
}

int Colaborador::getId(){
    return this->id;
}