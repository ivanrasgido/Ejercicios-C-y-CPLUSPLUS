/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "Figura.h"

class Rectangulo : public Figura{
    public:
        Rectangulo(double lado,double lado2);
        double area()const;

    private:
        double lado;
        double lado2;
};





#endif // RECTANGULO_H_
