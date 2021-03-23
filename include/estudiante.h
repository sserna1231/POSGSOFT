#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#ifndef EMPTY_ID
#define EMPTY_ID
static constexpr int empty_id = -1;
#endif

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Estudiante{
    private:
        string nombre;
        int id;
        string celular;
        string email;

    public:
        Estudiante();
        Estudiante( int );
        Estudiante( string, int, string, string );
        void llenarEstudiante();
        void mostrarEstudiante();
        int getId();
        void modificarEstudiante();
        int mostrarOpciones();
        void setId( int );
};

#endif