#include "..//include//colaborador.h"

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
    int celular;
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
    }while( opc == 0 );

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
    }while( opc == 0 );

    this->nombre = nombre;
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

void Colaborador::modificarColaborador(){
    string nombre, email;
    int celular;
    cargo_enum cargo;
    int opc, op;
    do{
        opc = this->mostrarOpciones();
        switch( opc ){
            case 1:
                cout << "Ingrese el nombre del colaborador: ";
                cin.ignore();
                getline( cin, nombre );
                this->nombre = nombre;
                break;
            case 2:
                cout << "Telefono celular: ";
                cin >> celular;
                this->celular = celular;
                break;
            case 3:
                cout << "Ingrese el email: ";
                cin >> email;
                break;
            case 4:
                do{
                    cout << "Jurado(1) o Profesor(2): ";
                    cin >> op;
                    if( op == 1 ){
                        cargo = cargo_enum::JURADO;
                    }else{
                        if( op == 2 ){
                            cargo = cargo_enum::PROFESOR;
                        }else{
                            cout << "Opcion no valida" << endl;
                            op = 0;
                        }
                    }
                }while( op == 0 );
                break;
            case 5:
                do{
                    cout << "Interno(1) o Externo(2): ";
                    cin >> op;
                    if( op == 1 ){
                        afiliacion = afil_enum::INTERNO;
                    }else{
                        if( op == 2 ){
                            afiliacion = afil_enum::EXTERNO;
                        }else{
                            cout << "Opcion no valida" << endl;
                            op = 0;
                        }
                    }
                }while( op == 0 );
                break;
            case 0:
                break;
            default:
                cout << "Opcion no valida\n";
                break;
        }
    }while( opc != 0 );
}

int Colaborador::mostrarOpciones(){
    int opc;
    cout << "\nASPECTO A MODIFICAR\n";
    cout << "1. Nombre\n";
    cout << "2. Celular\n";
    cout << "3. Email\n";
    cout << "4. Cargo\n"
    cout << "5. Afiliacion\n"
    cout << "0. Salir\n";
    cout << "> ";
    cin >> opc;
    cout << endl;
    return opc;
}