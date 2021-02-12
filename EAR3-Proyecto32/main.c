/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* NO DEBE HACER NINGUNA MODIFICACI�N EN ESTE ARCHIVO         *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include "main.h"

int main()
{
    FILE   *fpPant;
    tLista  lista;
    int     cant,
            cantElim;

    if((fpPant = fopen("pantalla.txt", "wt"))== NULL) // si no crea el archivo
        fpPant = stdout;                              //  mostrar� por consola
    cant = crearYcargarLista(&lista);
    fprintf(fpPant,
            "- Se cargo la lista con %d finales.\n\n"
            "- Se muestra la lista de izquierda a derecha.\n",
            cant);


/**//** funci�n a reemplazar *//**/
    ///cant = mostrarDeIzqADer(&lista, mostrarFinal, fpPant);
    cant = mostrarDeIzqADer_MIO(&lista, mostrarFinal_MIO, fpPant);
/** invoque ac� su versi�n de la primitiva **/


    fprintf(fpPant,
            "- Se mostraron %d calificaciones de finales.\n\n"
            "- Se ordena por frecuencia de aparici�n.\n\n",
            cant);


/**//** funci�n a reemplazar *//**/
///   ordenarLista(&lista, compararFinal);
    ordenarLista_MIO(&lista, compararFinal_MIO);
/** invoque ac� su versi�n de la primitiva **/


    fprintf(fpPant, "- Se muestra la lista de izquierda a derecha.\n");
/// NO DEBE reemplazar la siguiente primitiva /// /// /// /// !!!
    if(cant != mostrarDeIzqADer(&lista, mostrarFinal, fpPant))
        fprintf(fpPant, "- Ups!!! - Faltan nodos.\n");
    else
        fprintf(fpPant,
                "- Se mostraron %d calificaciones de finales.\n\n",
                cant);
    fprintf(fpPant,
            "- Eliminando y mostrando promedios por alumno\n"
            "     del ultimo al primero de la lista.\n");


/**//* funci�n a reemplazar *//**/
    /*cantElim = vaciarMostrarDetalleYProm(&lista, fpPant,
                                         compararFinal,
                                         acumularCalif,
                                         mostrarFinal,
                                         mostrarProm);*/
        cantElim = vaciarMostrarDetalleYProm_MIO(&lista, fpPant,
                                                compararFinal_MIO,
                                                acumularCalif_MIO,
                                                mostrarFinal_MIO,
                                                mostrarProm_MIO);
/** invoque ac� su versi�n de la primitiva **/


    fprintf(fpPant, "- Se eliminaron %d nodos de la lista.\n\n", cantElim);
    if(fpPant != stdout && fpPant != stderr && fpPant != NULL)
    {
        fclose(fpPant);
        system("start notepad pantalla.txt");
    }
    return 0;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

