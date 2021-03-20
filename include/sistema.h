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

class Sistema
{
private:
    std::string nombre;
    int actasTotales, estudiantesTotales, colabsTotales;
    std::list<Acta> listaActas;
    std::list<Colaborador> listaColab;
    std::list<Criterio> listaCriterios;
    std::list<Estudiante> listaEstudiante;

public:
    void addActa(Acta);
    void addEstudiante(Estudiante);
    void addColab(Colaborador);
    Estudiante& buscarEstudiante(int);
    Colaborador& buscarColab(int);
    Acta& buscarActa(int);
    list<Criterios>& getRefList();
    int menuActa();
    void modificarActa();
    void mostrarActas();
    void mostrarJurados();
    void mostrarCriterios();
    void EliminarActa();
    void EliminarEstudiante();
    void EliminarColaborador();
};

#endif