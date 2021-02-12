/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#include "Triangulo.h"


Triangulo::Triangulo(double lado,double lado2)
{
    if(base<=0||altura<=0)
    {
        throw FiguraInvalidaException("Figura Invalida");
    }
    else
    {
        this->base = base;
        this->altura=altura;
    }

}


double Triangulo::area() const
{
    return (base*altura)/2;
}
