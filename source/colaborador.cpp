#include "colaborador.h"

Colaborador::Colaborador( int id ){
    this->id = id;
    this->dirigidos = 0;
    this->evaluados = 0;
}

Colaborador::Colaborador( string nombre, int id, int celular, string email, cargo_enum cargo, afil_enum afiliacion ){
    this->nombre = nombre;
    this->id = id;
    this->celular = celular;
    this->email = email;
    this->cargo = cargo;
    this->afiliacion = afiliacion;
    this->dirigidos = 0;
    this->evaluados = 0;
}

void Colaborador::llenarColaborador(){
    string nombre, email;
    int celular, id;
    cargo_enum cargo;
    afil_enum afiliacion;
    int opc = 0;

    cout << endl;

    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline( cin, nombre );

    cout << "Telefono celular: ";
    cin >> celular;

    cout << "Ingrese el email: ";
    cin >> email;

    do{
        cout << "Jurado(1) o Profesor(2): ";
        cin >> opc;
        if( opc == 1 ){
            cargo = cargo_enum::JURADO;
        }else{
            if( opc == 2 ){
                cargo = cargo_enum::PROFESOR;
            }else{
                cout << "Opcion no valida" << endl;
                opc = 0;
            }
        }
    }while( opc = 0 )

    do{
        cout << "Interno(1) o Externo(2): ";
        cin >> opc;
        if( opc == 1 ){
            afiliacion = afil_enum::INTERNO;
        }else{
            if( opc == 2 ){
                afiliacion = afil_enum::EXTERNO;
            }else{
                cout << "Opcion no valida" << endl;
                opc = 0;
            }
        }
    }while( opc = 0 )

    this->nombre = nombre;
    this->id = id;
    this->celular = celular;
    this->email = email;
    this->cargo = cargo;
    this->afiliacion = afiliacion;

    cout << endl;
}

void Colaborador::mostrarColaborador(){
    cout << endl;

    cout << "* Nombre: " << this->nombre << endl;
    cout << "* id: " << this->id << endl;
    cout << "* Celular: " << this->celular << endl;
    cout << "* Email: " << this->email << endl;

    cout << "* Cargo: ";
    if( this->cargo == cargo_enum::JURADO ){
        cout << "Jurado" << endl;
    }else{
        cout << "Profesor" << endl;
    }

    cout << "* Afiliacion: ";
    if( this->afiliacion == afil_enum::INTERNO ){
        cout << "Interno" << endl;
    }else{
        cout << "Externo" << endl;
    }

    cout << "* Dirigidos: " << this->dirigidos << endl;
    cout << "* Evaluados: " << this->evaluados << endl;

    cout << endl;
}

void Colaborador::setDirigidos( int dirigidos ){
    this->dirigidos = dirigidos;
}

void Colaborador::setEvaluados( int evaluados ){
    this->evaluados = evaluados;
}

int Colaborador::getId(){
    return this->id;
}

int Colaborador::getDirigidos(){
    return this->dirigidos;
}

int Colaborador::getEvaluados(){
    return this->evaluados;
}

afil_enum Colaborador::getAfil(){
    return this->afiliacion;
}