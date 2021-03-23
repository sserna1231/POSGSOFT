#ifndef EVAL_H
#define EVAL_H
#include <string>

/*Nota máxima y mínima asignable para puntuación en el
sistema educativo Colombiano*/
constexpr float max_grade = 5.0;
constexpr float min_grade = 0.0;
constexpr float limit_grade = 3.5; //Nota mínima para aprobar
constexpr float empty_grade = - 1.0;
constexpr int num_jurados = 2;

typedef struct Evaluacion Evaluacion;

struct Evaluacion
{
    float nota;
    std::string comentario;
};

class Criterio
{
private:
    int id;
    Evaluacion notaj1, notaj2;
    float ponderacion, nota; //Peso, nota promedio de jurados
    std::string descripcion;
public:
    Criterio();
    Criterio( int );
    int menuModificables();
    void modificarCriterio();
    void evaluarCriterio();
    void setNotaJ1();
    void setNotaJ2();
    void setNota();
    int getID();
    void setId( int );
    float getNota();
    void mostrarCriterio();
};

//Cuenta cuantas palabras tiene una cadena
int countWords(const std::string& str);

#endif