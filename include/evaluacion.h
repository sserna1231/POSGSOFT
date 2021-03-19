#ifndef EVAL_H
#define EVAL_H
#include <string>

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
    //std::string descripcion; Creo que falta
public:
    Criterio();
    void evaluarCriterio();
    void setNotaJ1();
    void setNotaJ2();
    void setNota();
    float getNota();
};

//Cuenta cuantas palabras tiene una cadena
int countWords(const std::string& str);

#endif