
#include "main.h"

int main()
{
    FILE *fpPant = fopen("pantalla.txt", "wt");

    if(fpPant == NULL)      // si no puede abrir el archivo
        fpPant = stdout;        // mostrará por consola

    probarCadenas(fpPant);

    probarMatrices(fpPant);

    probarArchivosYPila(fpPant);

    if(fpPant != stdout && fpPant != stderr && fpPant != NULL)
    {
        fclose(fpPant);
        system("start notepad pantalla.txt");
    }

    return 0;
}


void probarCadenas(FILE *fpPant)
{
    char    buscar[] = { "int" },
                    //   123456789 123456789 123456789 123456789 123
            cade[99] = { "int funcion(int seIntegra, int noIntegra);" },
            reempl[] = { "unsigned int" };
    int     veces = 0,
            sinEspacio = 0;

    fprintf(fpPant,
            "///////////////// Ini - Parte 1 /////////////////\n"
            "En la cadena \n\"%s\":\n",
            cade);
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
    //veces = buscarYReemplazar(cade, sizeof(cade), buscar, reempl);
  veces = buscarYReemplazar_MIO(cade, sizeof(cade), buscar, reempl);
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
    if(veces < 0)
    {
        veces = -veces - 1;
        sinEspacio = 1;
    }
    fprintf(fpPant,
            "Se reemplaza la sub cadena \"%s\" por la subcadena \"%s\".\n"
            "Se hicieron %d reemplazos.\n"
            "La cadena queda:\n\"%s\".\n"
            "Sin %s.\n"
            "///////////////// FIN - Parte 1 /////////////////\n\n",
            buscar, reempl, veces, cade,
            sinEspacio ? "espacio para reemplazos" : "problemas");
}


void probarMatrices(FILE *fpPant)
{
    int     mat[TAM_MAT][TAM_MAT];

/**//**//**//**//**//**//**//**//**//**//**//**//**/
    cargarCuadrMagico(mat, TAM_MAT, TAM_MAT);
/*  cargarCuadrMagico_MIO(mat, TAM_MAT, TAM_MAT); */
/**//**//**//**//**//**//**//**//**//**//**//**//**/
    fprintf(fpPant,
            "///////////////// Ini - Parte 2 /////////////////\n"
            "El cuadrado magico es:\n");
/**//**//**//**//**//**//**//**//**//**//**//**//**/
    mostrarMat(mat, TAM_MAT, TAM_MAT, fpPant);
/*  mostrarMat_MIO(mat, TAM_MAT, TAM_MAT, fpPant);*/
/**//**//**//**//**//**//**//**//**//**//**//**//**/
    fprintf(fpPant, "///////////////// Fin - Parte 2 /////////////////\n\n");
}


void probarArchivosYPila(FILE *fpPant)
{
    FILE   *fpPedi,
           *fpPend,
           *fpMayo,
           *fpMeno;

    fprintf(fpPant, "///////////////// Ini - Parte 3 /////////////////\n");
    int     retVal = abrirLosArchivos(&fpPedi, ARCH_PEDIDOS, "rb",
                                      &fpPend, ARCH_PENDIENTES, "wb",
                                      &fpMayo, ARCH_MAYORES, "wt",
                                      &fpMeno, ARCH_MENORES, "wt",
                                      fpPant);
    if(retVal)
    {
        fprintf(fpPant,
                "ERROR - abriendo %d archivo%s - Imposible seguir",
                retVal, retVal > 1 ? "s" : "");
        return;
    }
    mostrarPediOPend(ARCH_PEDIDOS, fpPant);
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
    procesarPedidos(fpPedi, fpPend, fpMayo, fpMeno, fpPant);
/*  procesarPedidos_MIO(fpPedi, fpPend, fpMayo, fpMeno, fpPant);  */
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
    fclose(fpPend);
    fclose(fpMayo);
    fclose(fpMeno);
    mostrarPediOPend(ARCH_PENDIENTES, fpPant);
    fprintf(fpPant, "///////////////// Fin - Parte 3 /////////////////\n");
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

