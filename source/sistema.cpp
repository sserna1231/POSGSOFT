#include "sistema.h"

Sistema::Sistema(){
    cout << "Ingrese el nombre del sistema: "
    cin >> this->nombre;
    actasCreadas = estudiantesCreados = colabsCreados = 0;
    cout << endl;
}

int Sistema::menuActa()
{
    int opc;
    std::cout << "\nElija el campo a modificar:\n\n";
    std::cout << "1. Fecha\n";
    std::cout << "2. Titulo de trabajo\n";
    std::cout << "3. Periodo\n";
    std::cout << "4. Observaciones finales\n";
    std::cout << "5. Modificar datos Autor\n";
    std::cout << "6. Reasignar Autor\n";
    std::cout << "7. Modificar datos Directores\n";
    std::cout << "8. Reasignar Directores\n";
    std::cout << "9. Modificar datos Jurados\n";
    std::cout << "10. Reasignar Jurados\n";
    std::cout << "11. Criterio\n";
    std::cout << "0. Salir\n\n";
    std::cout << "> ";
    std::cin >> opc;

    return opc;
}

void Sistema::modificarActa()
{
    int id;
    cout << "Ingrese el ID del acta: ";
    cin >> id;
    cout << endl;
    Acta& acta = this->buscarActa( id );
    if( id != acta.getId() ){
        cout << "Acta no registrado\n";
        cout << "Debe crearla primero\n";
        return;
    }
    if( acta.getDiligencia() == Diligencia::Cerrado ){
        cout << "Acta cerrada: no puede modificarse" << endl;
        return;
    }  
    Estudiante& estudiante;
    Colaborador& colaborador;
    Criterio& criterio;
    do{
        int opc = this->menuActa();
        Criterio criterio;
        switch(opc){
            case 1:
                acta.setFecha();
                break;
            case 2:
                acta.setTitulo();
                break;
            case 3:
                acta.setPeriodo();
                break;
            case 4:
                acta.setObsFinal();
                break;
            case 5:
                cout << "Ingrese el ID del Autor: ";
                cin >> id; //Identificador reutilizado
                cout << endl;
                estudiante = this->buscarEstudiante( id );
                if(estudiante.getId() != id){
                    std::cout << "Estudiante inexistente.\n";
                    break;
                }
                estudiante.modificarEstudiante();
                acta.setEstudiante( *estudiante );
                break;
            case 6:
                cout << "Ingrese el ID del nuevo Autor: ";
                cin >> id; //Identificador reutilizado
                cout << endl;
                estudiante = this->buscarEstudiante( id );
                if(estudiante.getId() != id){
                    std::cout << "Estudiante inexistente.\n";
                    break;
                }
                acta.setEstudiante( *estudiante );
                break;
            case 7:
            case 9:
                cout << "Ingrese el ID del Colaborador: ";
                cin >> id; //Identificador reutilizado
                cout << endl;
                colaborador = this->buscarColab( id );
                if(colaborador.getId() != id){
                    std::cout << "Colaborador inexistente.\n";
                    break;
                }
                colaborador.modificarColaborador();
                acta.setColaborador( colaborador );
                break;
            case 8:
            case 10:
                acta.setColaborador( &this->listaColab );
                break;
            case 11:
                std::cout << "Ingrese el id del criterio: ";
                std::cin >> id;
                criterio = acta.buscarCriterio( id );

                if(criterio.getID() != id){
                    std::cout << "Criterio inexistente.\n";
                    break;
                }
                criterio.evaluarCriterio();
                break;
            case 0: 
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n\n";
        }
    } while( !opc );
}

void Sistema::addActa( Acta acta ){
    this->listaActas.push_back( acta );
    this->actasCreadas++;
}

void Sistema::addEstudiante( Estudiante e ){
    this->listaEstudiante.push_back( e );
    this->estudiantesCreados++;
}

void Sistema::addColab( Colaborador colab ){
    this->listaColab.push_back( colab );
    this->colabsCreados++;
}

Estudiante& Sistema::buscarEstudiante( int id ){
    list<Estudiante>::iterator it;
    for( it = this->listaEstudiante.begin(); it != this->listaEstudiante.end(); it++ ){
        if( it->id == id ){
            return *it;
        }
    }
    return *this->listaEstudiante.end();
}

Colaborador& Sistema::buscarColab( int id ){
    list<Colaborador>::iterator it;
    for( it = this->listaColab.begin(); it != this->listaColab.end(); it++ ){
        if( it->id == id ){
            return *it;
        }
    }
    return *this->listaColab.end();
}

Acta& Sistema::buscarActa( int id ){
    list<Acta>::iterator it;
    for( it = this->listaActas.begin(); it != this->listaActas.end(); it++ ){
        if( it->id == id ){
            return *it;
        }
    }
    return *this->listaActas.end();
}

list<Criterios>& Sistema::getRefList(){
    return &this->listaCriterios;
}

void Sistema::mostrarActas(){
    if( this->listaActas.size() == 0 ){
        cout << "No hay actas en el sistema\n";
        return;
    }
    list<Acta>::iterator it;
    for( it = this->listaActas.begin(); it != this->listaActas.end(); it++ ){
        it->mostrarActa();
        cout << endl;
    }
}

void Sistema::mostrarJurados(){
    list<Colaborador>::iterator it;
    for( it = this->listaColab.begin(); it != this->listaColab.end(); it++ ){
        if( it->evaluados > 0 ){
            it->mostrarColaborador();
        }
        cout << endl;
    }
}

void Sistema::mostrarCriterios(){
    list<Criterio>::iterator it;
    for( it = this->listaCriterios.begin(); it != this->listaCriterios.end(); it++ ){
        it->mostrarCriterio();
        cout << endl;
    }
}

void Sistema::eliminarActa( int id ){
    list<Acta>::iterator it;
    for( it = this->listaActas.begin(); it != this->listaActas.end(); it++ ){
        if( it->id == id ){
            if( it->getDiligencia() == Diligencia::Cerrado ){
                cout << "Acta cerrada: no puede eliminarse" << endl;
                return;
            }
            this->listaActas.erase( it );
            return;
        }
    }
}

void Sistema::eliminarEstudiante( int id ){
    list<Estudiante>::iterator it;
    for( it = this->listaEstudiante.begin(); it != this->listaEstudiante.end(); it++ ){
        if( it->id == id ){
            this->listaEstudiante.erase( it );
            return;
        }
    }
}

void Sistema::eliminarColaborador( int id ){
    list<Colaborador>::iterator it;
    for( it = this->listaColab.begin(); it != this->listaColab.end(); it++ ){
        if( it->id == id ){
            this->listaColab.erase( it );
            return;
        }
    }
}

int Sistema::getActasCreadas(){
    return this->actasCreadas;
}
    
int Sistema::getEstudiantesCreados(){
    return this->estudiantesCreados;
}

int Sistema::getColabsCreados(){
    return this->colabsCreados;
}

void setActasCreadas( int ac ){
    this->actasCreadas = ac;
}

void setEstudiantesCreados( int ec ){
    this->estudiantesCreados = ec;
}

void setColabsCreados( int cc ){
    this->colabsCreados = cc;
}