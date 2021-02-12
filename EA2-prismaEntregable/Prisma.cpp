/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 39.166.716-RASGIDO,Ivan Gonzalo-(04-1361) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**   DESARROOLLE LAS "FUNCIONES MIEMBRO" DE LA CLASE    **//**//**//**/

#include "Prisma.h"
#include <string.h>

Prisma::Prisma(Prisma& pris)
{
    this->alto=pris.alto;
    this->ancho=pris.ancho;
    this->profundidad=pris.profundidad;
    this->color = new char[500];
    strcpy(this->color,pris.color);
}

Prisma::Prisma(const char* color,int alto,int ancho,int profundidad)
:alto(alto),ancho(ancho),profundidad(profundidad)
{
    if(alto<=0||ancho<=0||profundidad<=0)
        return;

    this->color = new char[500];
    strcpy(this->color,color);
}


Prisma& Prisma::operator++()
{
    this->alto++;
    this->ancho++;
    this->profundidad++;
    return *this;
}

Prisma Prisma::operator++(int)
{
    Prisma aux(*this);
    this->alto++;
    this->ancho++;
    this->profundidad++;
    return aux;
}

Prisma& Prisma::operator--()
{
    this->alto--;
    this->ancho--;
    this->profundidad--;
    return *this;
}

Prisma& Prisma::operator = (const Prisma& pris)
{
    this->alto=pris.alto;
    this->ancho=pris.ancho;
    strcpy(color,pris.color);
    this->profundidad=pris.profundidad;
    return *this;
}

Prisma operator *(int multiplicador,Prisma& pris)
{
    Prisma p;
    p.alto=multiplicador*pris.alto;
    p.ancho=multiplicador*pris.ancho;
    p.profundidad=multiplicador*pris.profundidad;
    strcpy(p.color,pris.color);
    return p;
}

ostream& operator << (ostream& sal, const Prisma& pris)
{
    sal<<pris.alto<<'x'<<pris.ancho<<'x'<<pris.profundidad<<'-'<<pris.color<<endl;
    return sal;
}

Prisma::~Prisma()
{
    delete[]this->color;
}
