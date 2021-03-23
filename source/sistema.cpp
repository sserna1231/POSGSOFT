#include "sistema.h"

Sistema::Sistema(){
    cout << "Ingrese el nombre del sistema: ";
    cin >> this->nombre;
    actasCreadas = estudiantesCreados = colabsCreados = 0;
    this->listaActas.push_back( Acta() );
    this->listaEstudiante.push_back( Estudiante() );
    this->listaColab.push_back( Colaborador() );
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
    int id, opc;
    cout << "Ingrese el ID del acta: ";
    cin >> id;
    cout << endl;
    list<Acta>::iterator acta = this->buscarActa( id );
    if( id != acta->getId() ){
        cout << "Acta no registrado\n";
        cout << "Debe crearla primero\n";
        return;
    }
    if( acta->getDiligencia() == Diligencia::Cerrado ){
        cout << "Acta cerrada: no puede modificarse" << endl;
        return;
    }  
    list<Estudiante>::iterator estudiante;
    list<Colaborador>::iterator colaborador;
    list<Criterio>::iterator criterio;
    do{
        opc = this->menuActa();
        switch(opc){
            case 1:
                acta->setFecha();
                break;
            case 2:
                acta->setTitulo();
                break;
            case 3:
                acta->setPeriodo();
                break;
            case 4:
                acta->setObsFinal();
                break;
            case 5:
                cout << "Ingrese el ID del Autor: ";
                cin >> id; //Identificador reutilizado
                cout << endl;
                estudiante = this->buscarEstudiante( id );
                if(estudiante->getId() != id){
                    std::cout << "Estudiante inexistente.\n";
                    break;
                }
                estudiante->modificarEstudiante();
                acta->setEstudiante( *estudiante );
                break;
            case 6:
                cout << "Ingrese el ID del nuevo Autor: ";
                cin >> id; //Identificador reutilizado
                cout << endl;
                estudiante = this->buscarEstudiante( id );
                if(estudiante->getId() != id){
                    std::cout << "Estudiante inexistente.\n";
                    break;
                }
                acta->setEstudiante( *estudiante );
                break;
            case 7:
            case 9:
                cout << "Ingrese el ID del Colaborador: ";
                cin >> id; //Identificador reutilizado
                cout << endl;
                colaborador = this->buscarColab( id );
                if(colaborador->getId() != id){
                    std::cout << "Colaborador inexistente.\n";
                    break;
                }
                colaborador->modificarColaborador();
                acta->setColaborador( colaborador );
                break;
            case 8:
            case 10:
                acta->setColaborador( this->listaColab );                                                        //***********************************
                break;
            case 11:
                std::cout << "Ingrese el id del criterio: ";
                std::cin >> id;
                criterio = acta->buscarCriterio( id );
                if(criterio->getID() != id){
                    std::cout << "Criterio inexistente.\n";
                    break;
                }
                criterio->evaluarCriterio();
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

list<Estudiante>::iterator Sistema::buscarEstudiante( int id ){
    if( this->listaEstudiante.size() - 1 == 0 ){
        cout << "No hay estudiantes en el sistema\n";
        return this->listaEstudiante.end();
    }
    list<Estudiante>::iterator it;
    for( it = this->listaEstudiante.begin(); it != this->listaEstudiante.end(); it++ ){
        if( it->getId() == id ){
            return it;
        }
    }
    return this->listaEstudiante.end();
}

list<Colaborador>::iterator Sistema::buscarColab( int id ){
    if( this->listaColab.size() - 1 == 0 ){
        cout << "No hay colaboradores en el sistema\n";
        return this->listaColab.end();
    }
    list<Colaborador>::iterator it;
    for( it = this->listaColab.begin(); it != this->listaColab.end(); it++ ){
        if( it->getId() == id ){
            return it;
        }
    }
    return this->listaColab.end();
}

list<Acta>::iterator Sistema::buscarActa( int id ){
    if( this->listaActas.size() - 1 == 0 ){
        cout << "No hay actas en el sistema\n";
        return this->listaActas.end();
    }
    list<Acta>::iterator it;
    for( it = this->listaActas.begin(); it != this->listaActas.end(); it++ ){
        if( it->getId() == id ){
            return it;
        }
    }
    return this->listaActas.end();
}

list<Criterio>& Sistema::getRefList(){
    return this->listaCriterios;
}

void Sistema::mostrarActas(){
    if( this->listaActas.size() - 1 == 0 ){
        cout << "No hay actas en el sistema\n";
        return;
    }
    list<Acta>::iterator it;
    for( it = this->listaActas.begin(); it != this->listaActas.end(); it++ ){
        if( it->getId() != empty_id ){
            it->mostrarActa();
        }
        cout << endl;
    }
}

void Sistema::mostrarEstudiantes(){
    if( this->listaEstudiante.size() - 1 == 0 ){
        cout << "No hay estudiantes en el sistema\n";
        return;
    }
    list<Estudiante>::iterator it;
    for( it = this->listaEstudiante.begin(); it != this->listaEstudiante.end(); it++ ){
        if( it->getId() == empty_grade ){
            continue;
        }
        it->mostrarEstudiante();
        cout << endl;
    }
}

void Sistema::mostrarJurados(){
    if( this->listaColab.size() - 1 == 0 ){
        cout << "No hay colaboradores en el sistema\n";
        return;
    }
    list<Colaborador>::iterator it;
    for( it = this->listaColab.begin(); it != this->listaColab.end(); it++ ){
        if( it->getEvaluados() > 0 ){
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
    if( this->listaActas.size() == 0 ){
        cout << "No hay actas en el sistema\n";
        return;
    }
    list<Acta>::iterator it;
    for( it = this->listaActas.begin(); it != this->listaActas.end(); it++ ){
        if( it->getId() == id ){
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
    if( this->listaEstudiante.size() == 0 ){
        cout << "No hay estudiantes en el sistema\n";
        return;
    }
    list<Estudiante>::iterator it;
    for( it = this->listaEstudiante.begin(); it != this->listaEstudiante.end(); it++ ){
        if( it->getId() == id ){
            this->listaEstudiante.erase( it );
            return;
        }
    }
}

void Sistema::eliminarColaborador( int id ){
    if( this->listaColab.size() == 0 ){
        cout << "No hay colaboradores en el sistema\n";
        return;
    }
    list<Colaborador>::iterator it;
    for( it = this->listaColab.begin(); it != this->listaColab.end(); it++ ){
        if( it->getId() == id ){
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

void Sistema::setActasCreadas( int ac ){
    this->actasCreadas = ac;
}

void Sistema::setEstudiantesCreados( int ec ){
    this->estudiantesCreados = ec;
}

void Sistema::setColabsCreados( int cc ){
    this->colabsCreados = cc;
}

int Sistema::getListActasSize(){
    return this->listaActas.size();
}

int Sistema::getListColabSize(){
    return this->listaColab.size();
}

int Sistema::getListEstudianteSize(){
    return this->listaEstudiante.size();
}

list<Colaborador>::iterator Sistema::getListColabBegin(){
    return this->listaColab.begin();
}

list<Colaborador>::iterator Sistema::getListColabEnd(){
    return this->listaColab.end();
}

list<Acta>::iterator Sistema::getListActasBegin(){
    return this->listaActas.begin();
}

list<Acta>::iterator Sistema::getListActasEnd(){
    return this->listaActas.end();
}