#include <stdio.h>
#include <stdlib.h>
#include "ARCHIVOS.h"


int main()
{

    char nombrearchivo1[20];
    char nombrearchivo2[20];
    char *pc,*pt;
    t_persona per;
    pc=nombrearchivo1;
    pt=nombrearchivo2;
    printf("ingrese el nombre del archivo binario\n");
    scanf("%s",pc);
    printf("ingrese el nombre del archivo de texto\n");
    scanf("%s",pt);
    printf("\n\n");

    crearArchivobinario(pc);
    //LeeryMostrarArchivobinario(pc);
    //buscarporDNIarchivobinario(&per,pc);
    creararchivotextolf(pc,pt);
    //creararchivotextolv(pc,pt);
   leerymostrararchivodetexto(pt);
   buscarporDNIarchivodetexto(&per,pt);

    return 0;
}
