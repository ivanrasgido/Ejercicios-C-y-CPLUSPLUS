/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#ifndef FIGURA_H_
#define FIGURA_H_

#include <string>
#include "FiguraInvalidaException.h"



class Figura
{
    public:

        virtual double area()const = 0;
        virtual ~Figura();
};




#endif // FIGURA_H_
