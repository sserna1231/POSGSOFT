#ifndef COLABORADOR_H
#define COLABORADOR_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

enum class cargo_enum{
    PROFESOR, JURADO
};

enum class afil_enum{
    INTERNO, EXTERNO
};

class Colaborador{
    private:
        string nombre;
        int id;
        int celular;
        string email;
        cargo_enum cargo;
        afil_enum afiliacion;
        int dirigidos;
        int evaluados;

    public:
        Colaborador(int);
        Colaborador( string, int, int, string, cargo_enum, afil_enum );
        void llenarColaborador();
        void mostrarColaborador();
        void setDirigidos( int );
        void setEvaluados( int );
        int getId();
        int getDirigidos();
        int getEvaluados();
        afil_enum getAfil();
}

#endif