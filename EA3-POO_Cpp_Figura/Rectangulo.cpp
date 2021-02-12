/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#include "Rectangulo.h"


Rectangulo::Rectangulo(double lado,double lado2)
{
    if(lado<=0&&lado2<=0)
    {
        throw FiguraInvalidaException("Figura Invalida");
    }
    else
    {
        this->lado=lado;
        this->lado2=lado2;
    }

}



double Rectangulo::area() const
{
    return lado*lado2;
}
