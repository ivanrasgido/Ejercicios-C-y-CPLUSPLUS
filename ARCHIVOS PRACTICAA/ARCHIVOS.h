#ifndef PUNTEROS_H_INCLUDED
#define PUNTEROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int dia,
        mes,
        anio;
}t_fecha;

typedef struct
{
    long dni;//8
    t_fecha fnac;//12
    char nomyap[50];//51
    float sueldo;//4
}t_persona;

int crearArchivobinario(char *nombrearchivo);
int LeeryMostrarArchivobinario(char *nombredearchivo);
void mostrarempleado(const t_persona *emp);
int buscarporDNIarchivobinario(t_persona *per,char *nom1);
int creararchivotextolf(char *nom1,char *nom2);
int leerymostrararchivodetexto(char *nom);
int creararchivotextolv(char *nom1,char *nom2);
int buscarporDNIarchivodetexto(t_persona *per,char *nom2);

#endif // PUNTEROS_H_INCLUDED
