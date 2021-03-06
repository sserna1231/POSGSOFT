#include <iostream>
#include "evaluacion.h"

Criterio::Criterio()
{
    this->nota = empty_grade;
};

Criterio::Criterio( int id ){
    std::cout << "Ingrese la descripcion del criterio: ";
    std::getline(std::cin >> std::ws, this->descripcion);
    this->nota = empty_grade;
    do{
        std::cout << "Ingrese la ponderacion del criterio: ";
        std::cin >> this->ponderacion;
    }while( this->ponderacion < 0 || this->ponderacion > 1 );
}

void Criterio::modificarCriterio(){
    int opc;
    do{
        opc = this->menuModificables();
        switch(opc){
            case 1:
                std::getline(std::cin >> std::ws, this->descripcion);        
                break;
            case 2:
                do{
                    std::cout << "Ingrese la ponderacion del criterio: ";
                    std::cin >> this->ponderacion;
                }while( this->ponderacion < 0 || this->ponderacion > 1 );
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion invalida\n";
        }
    } while(opc != 0);
}

int Criterio::menuModificables(){
    int opc;
    std::cout << "Digite el campo que desea editar:\n";
    std::cout << "1. Descripcion\n";
    std::cout << "2. Ponderacion\n";
    std::cout << "0. Cancelar\n\n";
    std::cout << "> ";
    std::cin >> opc;
    return opc;
}

void Criterio::evaluarCriterio()
{
    int numJurado;
    do{
        std::cout << "Inserte # Jurado. Para dejar de evaluar este criterio, digite '0'.\n";
        std::cout << "> ";
        std::cin >> numJurado;
        switch(numJurado){
            case 1:
                setNotaJ1();
                break;
            case 2:
                setNotaJ2();
                break;
            case 0: 
                std::cout << "Evaluacion detenida.\n";
                break;
            default:
                std::cout << "# Jurado invalido.\nIntente de nuevo\n\n";
        }
    } while(numJurado != 0);
    this->setNota();
}

/*Para nuestra aplicación, asumiremos que la relación entre el número de palabras
y la cantidad total de caracteres es 1:6 [fuente de los deseos]. Por ende, según 
estimación, un comentario de criterio hecho por un jurado será de una extensión 
máxima de 50 palabras para que se equipare con las 3 líneas del formato ejemplo*/
void Criterio::setNotaJ1()
{
    float grade;
    do{
        std::cout << "Inserte la calificacion para el criterio:\n";
        std::cout << "'" << this->descripcion << "'\n> ";
        std::cin >> grade;
        if(grade < min_grade || grade > max_grade) std::cout << "Nota invalida\n";
    } while(grade < min_grade || grade > max_grade);

    this->notaj1.nota = grade;

    char comentar;
    std::cout << "Desea comentar el acta respecto a este criterio?\n";
    std::cout << "Inserte 's' o 'n' para afirmar o denegar, respectivamente.\n\n";
    std::cout << "> ";
    std::cin.ignore();
    std::cin.get(comentar);

    int numWords;
    if(comentar == 's'){
        do{
            std::cout << "Inserte comentario [max. 50 palabras]:\n";
            std::getline(std::cin >> std::ws, this->notaj1.comentario);
            numWords = countWords(notaj1.comentario);
            if(numWords > 50) 
                std::cout << "Numero sobrepasado de palabras.\n";
        } while(numWords > 50);
    }
}

void Criterio::setNotaJ2()
{
    float grade;
    do{
        std::cout << "Inserte la calificacion para el criterio:\n";
        std::cout << "'" << this->descripcion << "'\n> ";
        std::cin >> grade;
        if(grade < min_grade || grade > max_grade) std::cout << "Nota invalida\n";
    } while(grade < min_grade || grade > max_grade);

    this->notaj2.nota = grade;

    char comentar;
    std::cout << "Desea comentar el acta respecto a este criterio?\n";
    std::cout << "Inserte 's' o 'n' para afirmar o denegar, respectivamente.\n\n";
    std::cout << "> ";
    std::cin.ignore();
    std::cin.get(comentar);

    int numWords;
    if(comentar == 's'){
        do{
            std::cout << "Inserte comentario [max. 50 palabras]:\n";
            std::getline(std::cin >> std::ws, this->notaj2.comentario);
            numWords = countWords(notaj2.comentario);
            if(numWords > 50) 
                std::cout << "Numero sobrepasado de palabras.\n";
        } while(numWords > 50);
    }
}

void Criterio::setNota()
{
    if(notaj1.nota == empty_grade){
        std::cout << "Falta nota del jurado 1.\n";
        return;
    }
    if(notaj2.nota == empty_grade){
        std::cout << "Falta nota del jurado 2.\n";
        return;
    }
    this->nota = ponderacion * (notaj1.nota + notaj2.nota) / (float) num_jurados;
}

float Criterio::getNota()
{
    if(notaj1.nota == empty_grade)
        std::cout << "Falta nota del jurado 1.\n";
    if(notaj2.nota == empty_grade)
        std::cout << "Falta nota del jurado 2.\n";
    return this->nota;
}

float Criterio::getPonderacion()
{
    return this->ponderacion;
}

int Criterio::getID()
{
    return this->id;
}

Evaluacion Criterio::getNotaJ1(){
    return this->notaj1;
}

Evaluacion Criterio::getNotaJ2(){
    return this->notaj2;
}

std::string Criterio::getDescripcion(){
    return this->descripcion;
}

void Criterio::setId( int id ){
    this->id = id;
}

int countWords(const std::string& str)
{
    int spaces = 0; //Cantidad de espacios
    unsigned int newPos, lastPos = 0; //Última posición donde se halló espacio

    do{
        newPos = str.find (' ', lastPos);
        if (newPos != std::string::npos){
            spaces++;
            lastPos = newPos + 1;
        }
    } while(newPos != std::string::npos);

    return spaces + 1;
}

void Criterio::mostrarCriterio()
{
    std::cout << "\n==========================\n";
    std::cout << "\nDETALLES CRITERIO\n";
    std::cout << "Descripcion: " << this->descripcion << std::endl;
    std::cout << "Ponderacion: " << this->ponderacion << std::endl;
    std::cout << "\n==========================\n";
}