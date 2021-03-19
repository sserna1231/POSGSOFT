#ifndef ACTA_H
#define ACTA_H

#include <list>
#include <string>
#include "colaborador.h"
#include "estudiante.h"
#include "evaluacion.h"

enum class Tipo
{
    Aplicado, Investigacion
};

enum class Aprobacion
{
    Aprobado, Pendiente, Reprobado
};

enum class Diligencia
{
    Abierto, Cerrado
};

class Acta
{
private:
    int id;
    float notaFinal;
    std::string fecha, titulo, periodo, obsFinales;
    Estudiante autor;
    Colaborador director, codirector, jurado1, jurado2;
    enum class Tipo tipo;
    enum class Aprobacion aprobacion;
    enum class Diligencia diligencia;
    std::list<Criterio> listaCriterios;
    //std::list<DetalleCriterio> listaDetalleCrit;

public:
    Acta();
    Acta llenarActa();
    void initCriterios(lista<Criterios>&);
    Criterio buscarCriterio(int);
    void modificarActa();
    void evaluarActa();
    void setNotaFinal();
    void setAprobacion();
    void setObsFinal();
    void setDiligencia();
    int getDiligencia();
    //void guardarActa();
    void mostrarActa();
};

#endif