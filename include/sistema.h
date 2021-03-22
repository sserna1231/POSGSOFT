#ifndef SISTEMA_H
#define SISTEMA_H

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
using std::string;

class Sistema
{
private:
    std::string nombre;
    int actasCreadas, estudiantesCreados, colabsCreados;
    std::list<Acta> listaActas;
    std::list<Colaborador> listaColab;
    std::list<Criterio> listaCriterios;
    std::list<Estudiante> listaEstudiante;

public:
    Sistema();
    void addActa( Acta );
    void addEstudiante( Estudiante );
    void addColab( Colaborador );
    Estudiante& buscarEstudiante( int );
    Colaborador& buscarColab( int );
    Acta& buscarActa( int );
    list<Criterios>& getRefList();
    int menuActa();
    void modificarActa();
    void mostrarActas();
    void mostrarJurados();
    void mostrarCriterios();
    void eliminarActa( int );
    void eliminarEstudiante( int );
    void eliminarColaborador( int );
    int getActasCreadas();
    int getEstudiantesCreados();
    int getColabsCreados();
    void setActasCreadas( int );
    void setEstudiantesCreados( int );
    void setColabsCreados( int );
};

#endif