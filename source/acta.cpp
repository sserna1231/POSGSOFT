#include <ctime>
#include <iostream>
#include "acta.h"

Acta::Acta()
{
    this->notaFinal = min_grade;
    this->aprobacion = Aprobacion::Pendiente;
    this->diligencia = Diligencia::Abierto;
}

Acta::Acta(int id)
{
    this->notaFinal = min_grade;
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

void Acta::initCriterios(list<Criterios>& criterios)
{
    this->listaCriterios.splice(listaCriterios.begin(), criterios);
}

Criterio& Acta::buscarCriterio(int id)
{
    for(list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        if(it->id == id) return *it;
    }
    return *listaCriterios.end();
}

void Acta::evaluarActa()
{
    int pos = 0; //Indice del arreglo num_criterio
    int num_criterio[listaCriterios.size()];
    for(list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        it->evaluarCriterio();
        if(it->getNota() == empty_grade) num_criterio[pos++] = it->id;
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

void Acta::setColaborador(Colaborador c)
{
    int opc;
    do{
        std::cout << "\nIngrese el puesto correspondiente:\n";
        std::cout << "1. Director\n";
        std::cout << "2. Codirector\n";
        std::cout << "3. Jurado 1\n";
        std::cout << "4. Jurado 2\n";
        std::cout << "0. Salir\n\n";

        std::cout << "> ";
        std::cin >> opc;

        switch(opc){
            case 1:
                this->director = c;
                break;
            case 2:
                this->codirector = c;
                break;
            case 3:
                this->jurado1 = c;
                break;
            case 4:
                this->jurado2 = c;
                break;
            case 0:
                break;
            default:
                std::cout << "Campo invalido\n";
        }
    } while( opc );
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

void setNotaFinal()
{
    for(list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        this->notFinal += it->getNota();
    }
}

void setAprobacion()
{
    if(this->notaFinal == empty_grade) this->aprobacion = Aprobacion::Pendiente;
    else if(this->notaFinal >= min_grade && this->notaFinal <= limit_grade)
        this->aprobacion = Aprobacion::Reprobado;
    else this->aprobacion = Aprobacion::Aprobado;
}

void setDiligencia()
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

Diligencia getDiligencia()
{
    return this->diligencia;
}

void mostrarActa()
{
    std::cout << "\n===============================\n";
    std::cout << "ID ACTA: " << this->id << std::endl;
    std::cout << "Fecha: " << this->fecha << std::endl;
    std::cout << "Periodo: " << this->periodo << std::endl;
    std::cout << "Titulo trabajo: " << this->titulo << std::endl;
    std::cout << "Tipo trabajo: " << this->tipo << std::endl;

    std::cout << "\nDATOS AUTOR\n";
    this->autor.mostarEstudiante();
    
    std::cout << "\nDirector:\n";
    this->director.mostarColaborador();
    std::cout << "\nCodirector:\n";
    this->codirector.mostarColaborador();
    std::cout << "\nJurados:\n";
    this->jurado1.mostarColaborador();
    this->jurado2.mostarColaborador();

    std::cout << "Estado: " << this->aprobacion << std::endl;
    std::cout << "Diligencia: " << this->diligencia << std::endl;
}

void Acta::setFecha(){
    std::string dia, mes, year;
    std::cout << "Ingrese la fecha de sustentacion.\n";
    std::cout << "Dia: "; std::cin >> dia;
    std::cout << "Mes: "; std::cin >> mes;
    std::cout << "Anio: "; std::cin >> year;    
    this->fecha = dia + '/' + mes + '/' + year;
}