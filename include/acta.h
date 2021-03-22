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

constexpr int max_words_obsfinal = 200;

enum class Tipo: string
{
    Aplicado, Investigacion
};

enum class Aprobacion: string
{
    Aprobado, Pendiente, Reprobado
};

enum class Diligencia: string
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
    Acta(int);
    void llenarActa();
    void initCriterios(lista<Criterios>&);
    Criterio& buscarCriterio(int);
    void evaluarActa();
    void setEstudiante(Estudiante);
    void setColaborador(Colaborador&);
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
    //void guardarActa();
    void mostrarActa();
    void mostrarEstado();
    void setId( int );
};

#endif