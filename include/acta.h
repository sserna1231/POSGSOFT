#ifndef ACTA_H
#define ACTA_H

#include <list>
#include <string>
#include "colaborador.h"
#include "estudiante.h"
#include "evaluacion.h"
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

constexpr int max_words_obsfinal = 200;

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
    Tipo tipo;
    Aprobacion aprobacion;
    Diligencia diligencia;
    std::list<Criterio> listaCriterios;
    //std::list<DetalleCriterio> listaDetalleCrit;

public:
    Acta();
    Acta(int);
    void llenarActa();
    void initCriterios(list<Criterio>&);
    list<Criterio>::iterator buscarCriterio(int);
    void evaluarActa();
    void setEstudiante(Estudiante);
    void setColaborador(list<Colaborador>::iterator);
    void setColaborador(list<Colaborador>::iterator, list<Colaborador>::iterator);
    void setPeriodo();
    void setTitulo();
    void setNotaFinal();
    void setObsFinal();
    void setAprobacion();
    void setDiligencia();
    void setFecha();
    Diligencia getDiligencia();
    Aprobacion getAprobacion();
    string getTitulo();
    int getId();
    Tipo getTipo();
    string getFecha();
    Estudiante getAutor();
    string getPeriodo();
    Colaborador getDirector();
    Colaborador getCodirector();
    Colaborador getJurado1();
    Colaborador getJurado2();
    list<Criterio>::iterator getCriteriosBegin();
    list<Criterio>::iterator getCriteriosEnd();
    string getObsFinal();
    float getNotaFinal();
    //void guardarActa();
    void mostrarActa();
    void mostrarEstado();
    void setId( int );
};

#endif