/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"

class Triangulo : public Figura{
    public:
        Triangulo(double base,double altura);
        double area()const;

    private:
        double base;
        double altura;
};






#endif // TRIANGULO_H_
