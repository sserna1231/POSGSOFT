#include <iostream>
#include "evaluacion.h"

Criterio::Criterio()
{
    this->nota = empty_grade;
};

void Criterio::evaluarCriterio()
{
    int numJurado;
    std::cout << "Inserte N° Jurado: " << std::endl;
    std::cin >> numJurado;

    switch(numJurado){
        case 1:
            setNotaJ1();
            break;
        case 2:
            setNotaJ2();
            break;
        default:
            std::cout << "N° Jurado invalido.\nIntente de nuevo\n\n";
    }
    setNota();
}

/*Para nuestra aplicación, asumiremos que la relación entre el número de palabras
y la cantidad total de caracteres es 1:6 [fuente de los deseos]. Por ende, según 
estimación, un comentario de criterio hecho por un jurado será de una extensión 
máxima de 50 palabras para que se equipare con las 3 líneas del formato ejemplo*/
void Criterio::setNotaJ1()
{
    float grade;
    do{
        std::cout << "Inserte la calificacion para este criterio: ";
        std::cin >> grade;
        if(grade < min_grade || grade > max_grade) std::cout << "Nota invalida\n";
    } while(grade < min_grade || grade > max_grade);

    this->notaj1.nota = grade;

    char comentar;
    std::cout << "Desea comentar el acta respecto a este criterio?\n";
    std::cout << "Inserte 's' o 'n' para afirmar o denegar, respectivamente.\n\n";
    std::cout << "> ";
    std::cin.get(comentar);

    int numWords;
    if(comentar == 's'){
        do{
            std::cout << "Inserte comentario [max. 50 palabras]:\n";
            getline(std::cin >> std::ws, this->notaj1.comentario);
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
        std::cout << "Inserte la calificacion para este criterio: ";
        std::cin >> grade;
        if(grade < min_grade || grade > max_grade) std::cout << "Nota invalida\n";
    } while(grade < min_grade || grade > max_grade);

    this->notaj2.nota = grade;

    char comentar;
    std::cout << "Desea comentar el acta respecto a este criterio?\n";
    std::cout << "Inserte 's' o 'n' para afirmar o denegar, respectivamente.\n\n";
    std::cout << "> ";
    std::cin.get(comentar);

    int numWords;
    if(comentar == 's'){
        do{
            std::cout << "Inserte comentario [max. 50 palabras]:\n";
            getline(std::cin >> std::ws, this->notaj2.comentario);
            numWords = countWords(notaj1.comentario);
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

int Criterio::getID()
{
    return this->id;
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