/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#ifndef CUADRADO_H_
#define CUADRADO_H_

#include "Figura.h"

class Cuadrado : public Figura{
    public:
        Cuadrado(double lado);
        double area()const;

    private:
        double lado;
};







#endif // CUADRADO_H_
