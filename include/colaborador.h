#ifndef COLABORADOR_H
#define COLABORADOR_H

#include <iostream>
#include <tuple>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tuple;
using std:list;

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
        int dirigidos; //Cantidad de trabajos que ha dirigido el colaborador
        int evaluados; //Cantidad de trabajos en los que ha sido jurado el colaborador
        list<tuple<int, string>> trabajos; //Corresponde a los trabajos evaluados por el colaborador
        

    public:
        Colaborador(int);
        Colaborador( string, int, int, string, cargo_enum, afil_enum );
        void llenarColaborador();
        void mostrarColaborador();
        void setDirigidos( int );
        void setEvaluados( int );
        void setCargo( cargo_enum );
        void addTrabajoEval( int, string );
        int getId();
        int getDirigidos();
        int getEvaluados();
        afil_enum getAfil();
        void modificarColaborador();
        int mostrarOpciones();
        void mostrarTrabajosEval();
}

#endif