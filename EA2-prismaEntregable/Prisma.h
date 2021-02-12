/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 39.166.716-RASGIDO,Ivan Gonzalo-(04-1361) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**         COMPLETE LA DECLARACIÓN DE LA CLASE          **//**//**//**/

#ifndef PRISMA_H_
#define PRISMA_H_

#include <iostream>
#include <string>

using namespace std;

class Prisma
{
private:
    int alto;
    int ancho;
    int profundidad;
    char* color;/// <--preferentemente, de lo contrario:  char *color;
public:
    Prisma(const char* color="incoloro",int alto=1,int ancho=1,int profundidad=1);
    Prisma(Prisma& pris);
    Prisma& operator=(const Prisma& pris);
    Prisma& operator++();
    Prisma operator++(int);
    Prisma& operator--();
    friend Prisma operator *(int multiplicador, Prisma& pris);
    friend ostream& operator << (ostream& sal, const Prisma& pris);
    ~Prisma();
};

#endif // PRISMA_H_

