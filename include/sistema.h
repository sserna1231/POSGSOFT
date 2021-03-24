#ifndef SISTEMA_H
#define SISTEMA_H

#include <fstream>
#include <list>
#include <string>
#include "acta.h"
#include "colaborador.h"
#include "estudiante.h"
#include "evaluacion.h"

using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::string;

class Sistema
{
private:
    std::string nombre;
    int actasCreadas, estudiantesCreados, colabsCreados, criteriosCreados;
    std::list<Acta> listaActas;
    std::list<Colaborador> listaColab;
    std::list<Criterio> listaCriterios;
    std::list<Estudiante> listaEstudiante;

public:
    Sistema();
    void addActa( Acta );
    void addEstudiante( Estudiante );
    void addColab( Colaborador );
    void addCriterio( Criterio );
    list<Estudiante>::iterator buscarEstudiante( int );
    list<Colaborador>::iterator buscarColab( int );
    list<Acta>::iterator buscarActa( int );
    list<Criterio>::iterator buscarCriterio( int );
    list<Criterio>& getRefList();
    int menuActa();
    void modificarActa();
    void mostrarEstudiantes();
    void mostrarActas();
    void mostrarJurados();
    void mostrarCriterios();
    void eliminarActa( int );
    void eliminarEstudiante( int );
    void eliminarColaborador( int );
    void eliminarCriterio( int );
    int getActasCreadas();
    int getEstudiantesCreados();
    int getColabsCreados();
    int getCritCreados();
    void setActasCreadas( int );
    void setEstudiantesCreados( int );
    void setColabsCreados( int );
    int getListActasSize();
    int getListColabSize();
    int getListEstudianteSize();
    list<Colaborador>::iterator getListColabBegin();
    list<Colaborador>::iterator getListColabEnd();
    list<Acta>::iterator getListActasBegin();
    list<Acta>::iterator getListActasEnd();
    list<Estudiante>::iterator getListEstudianteEnd();
    list<Criterio>::iterator getListCriteriosEnd();
    void guardarActa(list<Acta>::iterator);
};

#endif