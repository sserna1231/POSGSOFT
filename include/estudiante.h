#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Estudiante{
    private:
        string nombre;
        int id;
        int celular;
        string email;

    public:
        Estudiante( int );
        Estudiante( string, int, int, string );
        void llenarEstudiante();
        void mostrarEstudiante();
        int getId();
        void modificarEstudiante();
        int mostrarOpciones();
}

#endif