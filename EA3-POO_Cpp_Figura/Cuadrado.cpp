/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#include "Cuadrado.h"
#include <exception>

Cuadrado::Cuadrado(double lado)
{
        if(lado<=0)
        {
            throw FiguraInvalidaException("Figura Invalida");
        }
        else
            this->lado = lado;
}


double Cuadrado::area() const
{
    return lado*lado;
}

