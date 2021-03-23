#include <ctime>
#include <iostream>
#include "acta.h"

Acta::Acta()
{
    this->id = empty_id;
    this->notaFinal = empty_grade;
    this->aprobacion = Aprobacion::Pendiente;
    this->diligencia = Diligencia::Abierto;
}

Acta::Acta(int id)
{
    this->notaFinal = empty_grade;
    this->aprobacion = Aprobacion::Pendiente;
    this->diligencia = Diligencia::Abierto;
}

void Acta::llenarActa()
{
    this->setTitulo();

    this->setPeriodo();

    this->setFecha();

    int opc;
    do{
        cout << "Trabajo Aplicado (1) o Investigativo (2): ";
        cin >> opc;
        if( opc == 1 ){
            this->tipo = Tipo::Aplicado;
        }else if( opc == 2 ){
            this->tipo = Tipo::Investigacion;
        }else{
            cout << "Opcion no valida" << endl;
            opc = 0;
        }
    } while( !opc );
}

void Acta::initCriterios(list<Criterio>& criterios)
{
    this->listaCriterios.splice(listaCriterios.begin(), criterios);
}

list<Criterio>::iterator Acta::buscarCriterio(int id)
{
    for(list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        if(it->getID() == id) return it;
    }
    return listaCriterios.end();
}

void Acta::evaluarActa()
{
    int pos = 0; //Indice del arreglo num_criterio
    int num_criterio[listaCriterios.size()];
    for(list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        it->evaluarCriterio();
        if(it->getNota() == empty_grade) num_criterio[pos++] = it->getID();
    }
    if(pos >= 0 && pos < listaCriterios.size()){
        std::cout << "Faltaron por evaluar los siguientes criterios:\n";
        for(int i = 0; i < pos; i++)
            std::cout << "Criterio ID: " << num_criterio[i] << std::endl;
        std::cout << "\nLa nota final aun no puede ser asignada.\n";
        return;
    }
    setNotaFinal();
}

void Acta::setEstudiante(Estudiante e)
{
    this->autor = e;
}

void Acta::setColaborador(list<Colaborador>::iterator c)
{
    int opc;
    do{
        std::cout << "\nIngrese el puesto correspondiente:\n";
        std::cout << "1. Director\n";
        std::cout << "2. Codirector\n";
        std::cout << "3. Jurado 1\n";
        std::cout << "4. Jurado 2\n";
        std::cout << "0. Cancelar\n\n";

        std::cout << "> ";
        std::cin >> opc;

        switch(opc){
            case 1:
                this->director = *c;
                c->setDirigidos( c->getDirigidos() + 1 );
                break;
            case 2:
                this->codirector = *c;
                c->setDirigidos( c->getDirigidos() + 1 );
                break;
            case 3:
                this->jurado1 = *c;
                c->setEvaluados( c->getEvaluados() + 1 );
                c->addTrabajoEval( this->id, this->titulo );
                break;
            case 4:
                this->jurado2 = *c;
                c->setEvaluados( c->getEvaluados() + 1 );
                c->addTrabajoEval( this->id, this->titulo );
                break;
            case 0:
                break;
            default:
                std::cout << "Campo invalido\n";
        }
    } while( opc != 0 );
}

void Acta::setColaborador(list<Colaborador>& listaColab){
    int opc, op, idActual, idNuevo;
    list<Colaborador>::iterator colabNuevo;
    list<Colaborador>::iterator colabActual;
    do{
        std::cout << "\nIngrese el puesto a reemplazar:\n";
        std::cout << "1. Director\n";
        std::cout << "2. Codirector\n";
        std::cout << "3. Jurado 1\n";
        std::cout << "4. Jurado 2\n";
        std::cout << "0. Cancelar\n\n";

        std::cout << "> ";
        std::cin >> opc;

        switch( opc ){
            case 1:
            case 2:
                cout << "Actualmente dirige/codirige:\n";
                if( opc == 1 ){
                    this->director.mostrarColaborador();
                    idActual = director.getId();
                }else{
                    this->codirector.mostrarColaborador();
                    idActual = codirector.getId();
                }
                if( idActual != empty_id ){
                    cout << "¿Reemplazar? Si(1), No(cualquier otro numero)\n> ";
                }else{
                    cout << "¿Agregar? Si(1), No(cualquier otro numero)\n> ";
                }
                cin >> op;
                if( op == 1 ){
                    cout << "Ingrese id del nuevo Director/Codirector: ";
                    cin >> idNuevo;
                    for( list<Colaborador>::iterator it = listaColab.begin(); it != listaColab.end(); it++ ){
                        if( it->getId() == idNuevo ){ 
                            colabNuevo = it;
                        }else if( it->getId() == idActual ){
                            colabActual = it;
                        }
                    }
                    if( id != colabNuevo->getId() ){
                        cout << "Colaborador nuevo no registrado\n";
                        cout << "Debe crearlo primero\n";
                        break;
                    }
                    colabActual->setDirigidos( colabActual->getDirigidos() - 1 );
                    colabNuevo->setDirigidos( colabNuevo->getDirigidos() + 1 );
                    if( opc == 1 ){
                        this->director = *colabNuevo;
                    }else{
                        this->codirector = *colabNuevo;
                    }
                }
                break;
            case 3:
            case 4:
                cout << "Actualmente evalua:\n";
                if( opc == 3 ){
                    this->jurado1.mostrarColaborador();
                    idActual = jurado1.getId();
                }else{
                    this->jurado2.mostrarColaborador();
                    idActual = jurado2.getId();
                }
                if( idActual != empty_id ){
                    cout << "¿Reemplazar? Si(1), No(cualquier otro numero)\n> ";
                }else{
                    cout << "¿Agregar? Si(1), No(cualquier otro numero)\n> ";
                }
                cin >> op;
                if( op == 1 ){
                    cout << "Ingrese id del nuevo Director/Codirector: ";
                    cin >> idNuevo;
                    for( list<Colaborador>::iterator it = listaColab.begin(); it != listaColab.end(); it++ ){
                        if( it->getId() == idNuevo ){ 
                            colabNuevo = it;
                        }else if( it->getId() == idActual ){
                            colabActual = it;
                        }
                    }
                    if( id != colabNuevo->getId() ){
                        cout << "Colaborador nuevo no registrado\n";
                        cout << "Debe crearlo primero\n";
                        break;
                    }
                    colabActual->setEvaluados( colabActual->getEvaluados() - 1 );
                    colabActual->deleteTrabajoEval( this->id, this->titulo );
                    colabNuevo->setEvaluados( colabNuevo->getEvaluados() + 1 );
                    colabNuevo->addTrabajoEval( this->id, this->titulo );
                    if( opc == 3 ){
                        this->jurado1 = *colabNuevo;
                    }else{
                        this->jurado2 = *colabNuevo;
                    }
                }
                break;
            case 0:
                break;
            default:
                std::cout << "Campo invalido\n";
        }
    }while( opc != 0 );
}

void Acta::setPeriodo()
{
    std::cout << "Ingrese el periodo lectivo.\nNOTA: seguir el\
        formato [AAAA-SEMESTRE:Tesis( Num. Romano)].\n\n";
    std::cout << "Ejemplo: 2021-2:Tesis II\n\n";
    std::cout << "> ";
    std::cin.ignore();
    getline(std::cin >> std::ws, this->periodo);
}

void Acta::setTitulo()
{
    std::cout << "Ingrese el titulo del trabajo: ";
    std::cin.ignore();
    getline(std::cin >> std::ws, this->titulo);
}

void Acta::setNotaFinal()
{
    for(list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        this->notaFinal += it->getNota();
    }
}

void Acta::setAprobacion()
{
    if(this->notaFinal == empty_grade) this->aprobacion = Aprobacion::Pendiente;
    else if(this->notaFinal >= min_grade && this->notaFinal <= limit_grade)
        this->aprobacion = Aprobacion::Reprobado;
    else this->aprobacion = Aprobacion::Aprobado;
}

void Acta::setDiligencia()
{
    int opc;
    do{
        std::cout << "\nIngrese la opcion correspondiente:\n";
        std::cout << "1. Abrir acta\n";
        std::cout << "2. Cerrar acta\n";
        std::cout << "0. Salir\n\n";

        std::cout << "> ";
        std::cin >> opc;

        switch(opc){
            case 1:
                if(this->diligencia == Diligencia::Abierto)
                    std::cout << "El acta ya esta abierta\n";
                else this->diligencia = Diligencia::Abierto;
                break;
            case 2:
                if(this->diligencia == Diligencia::Cerrado)
                    std::cout << "El acta ya esta cerrada\n";
                else this->diligencia = Diligencia::Cerrado;
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion invalida\n";
        }
    } while( opc );
}

void Acta::setObsFinal()
{
    int num_words;
    do{
        std::cout << "Comentario final: ";
        getline(std::cin >> std::ws, this->obsFinales);
        num_words = countWords(obsFinales);
        if(num_words > max_words_obsfinal){
            std::cout << "Limite de palabras rebasado\n";
        }
    } while(num_words > max_words_obsfinal);
}

Diligencia Acta::getDiligencia()
{
    return this->diligencia;
}

Aprobacion Acta::getAprobacion(){
    return this->aprobacion;
}

string Acta::getTitulo(){
    return this->titulo;
}

int Acta::getId(){
    return this->id;
}

Tipo Acta::getTipo(){
    return this->tipo;
}

void Acta::mostrarActa()
{
    std::cout << "\n===============================\n";
    std::cout << "ID ACTA: " << this->id << std::endl;
    std::cout << "Fecha: " << this->fecha << std::endl;
    std::cout << "Periodo: " << this->periodo << std::endl;
    std::cout << "Titulo trabajo: " << this->titulo << std::endl;
    std::cout << "Tipo trabajo: ";
    if( this->tipo == Tipo::Aplicado ){
        cout << "Aplicado\n";
    }else{
        cout << "Investigacion\n";
    }

    std::cout << "\nDATOS AUTOR\n";
    this->autor.mostrarEstudiante();
    
    std::cout << "\nDirector:\n";
    this->director.mostrarColaborador();
    std::cout << "\nCodirector:\n";
    this->codirector.mostrarColaborador();
    std::cout << "\nJurados:\n";
    this->jurado1.mostrarColaborador();
    this->jurado2.mostrarColaborador();
    cout << endl;
    this->mostrarEstado();
}

void Acta::setFecha(){
    std::string dia, mes, year;
    std::cout << "Ingrese la fecha de sustentacion.\n";
    std::cout << "Dia: "; std::cin >> dia;
    std::cout << "Mes: "; std::cin >> mes;
    std::cout << "Anio: "; std::cin >> year;    
    this->fecha = dia + '/' + mes + '/' + year;
}

void Acta::mostrarEstado(){
    cout << "Estado: ";
    if( this->aprobacion == Aprobacion::Aprobado ){
        cout << "Aprobado\n";
    }else if( this->aprobacion == Aprobacion::Pendiente ){
        cout << "Pendiente\n";
    }else{
        cout << "Reprobado\n";
    }
    cout << "Diligencia: ";
    if( this->diligencia == Diligencia::Abierto ){
        cout << "Abierto\n";
    }else{
        cout << "Cerrado\n";
    }
    cout << "Nota final: ";
    if( notaFinal == empty_grade ){
        cout << "Faltan criterios por evaluar" << endl;
    }else{
        cout << notaFinal << endl;
    }
}

void Acta::setId( int id ){
    this->id = id;
}