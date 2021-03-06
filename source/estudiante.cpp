#include "estudiante.h"

Estudiante::Estudiante(){
    this->id = empty_id;
}

Estudiante::Estudiante( int id ){
    this->id = id;
}

Estudiante::Estudiante( string nombre, int id, string celular, string email ){
    this->nombre = nombre;
    this->id = id;
    this->celular = celular;
    this->email = email;
}

void Estudiante::llenarEstudiante(){
    string nombre, email, celular;

    cout << endl;

    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline( cin, nombre );

    cout << "Telefono celular: ";
    getline( cin, celular );

    cout << "Ingrese el email: ";
    getline( cin, email );

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

int Estudiante::getId(){
    return this->id;
}

string Estudiante::getNombre(){
    return this->nombre;
}

void Estudiante::modificarEstudiante(){
    string nombre, email, celular;
    int opc;
    do{
        opc = this->mostrarOpciones();
        switch( opc ){
            case 1:
                cout << "Ingrese el nombre del estudiante: ";
                cin.ignore();
                getline( cin, nombre );
                this->nombre = nombre;
                break;
            case 2:
                cout << "Telefono celular: ";
                getline( cin, celular );
                this->celular = celular;
                break;
            case 3:
                cout << "Ingrese el email: ";
                getline( cin, email );
                break;
            case 0:
                break;
            default:
                cout << "Opcion no valida\n";
                break;
        }
    }while( opc != 0 );
}

int Estudiante::mostrarOpciones(){
    int opc;
    cout << "\nASPECTO A MODIFICAR\n";
    cout << "1. Nombre\n";
    cout << "2. Celular\n";
    cout << "3. Email\n";
    cout << "0. Salir\n";
    cout << "> ";
    cin >> opc;
    cout << endl;
    return opc;
}

void Estudiante::setId( int id ){
    this->id = id;
}