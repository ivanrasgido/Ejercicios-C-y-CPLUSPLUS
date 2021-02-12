/**//* 39.166.716-Rasgido,Ivan_Gonzalo-(04-1361) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/

#include <string.h>
#include <stdlib.h>
#define REDONDEO(X,Y) ( (X) >= (Y)+0.5 ? (Y) + 1 : (Y) )
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/



/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    if(d)
    {
        fprintf(fp,"%s %-30s %4d %2d\n",(((const tFinal*)d)->dni),
                (((const tFinal*)d)->apYNom),
                (((const tFinal*)d)->codMat),
                ((const tFinal*)d)->calif);
    }
    else
    {
        fprintf(fp," D. N. I.  Apellido(s), Nombre(s)         CodM cal\n");
    }
}


int  compararFinal_MIO(const void *d1, const void *d2)
{
    const tFinal* dato1=(const tFinal*)d1;
    const tFinal* dato2=(const tFinal*)d2;

    const char* dat1=dato1->dni;
    const char* dat2=dato2->dni;

    while(*dat1!='\0')
    {
        if(*dat1==*dat2)
        {
            dat1++;
            dat2++;
        }
        if(*dat1>*dat2)
            return 1;
        if(*dat1<*dat2)
            return -1;
    }
    return 0;
}


int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig)
{
    tFinal* destino=(tFinal*)*dest;
    const tFinal* origen=(const tFinal*)orig;

    return destino->calif+=origen->calif;
}


void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp)
{
    tFinal* promedio=(tFinal*)d2;
    float prom=promedio->calif;
    float res = prom/cantCalif;
    int   res1=prom/cantCalif;
    promedio->calif=REDONDEO(res,res1);;
    fprintf(fp,"   --- Rindio  %d final(es) con un promedio de: %2d\n\n",
            cantCalif,((const tFinal*)d2)->calif);
}


/**//* para el TDA LISTA                                                  *//**/

int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp)
{
    ///muestro de derecha a izquierda

    tNodo *act=*p;
    int cant=0;
    if(act)
    {
        mostrar(NULL,fp);
        while(act->sig)
            act=act->sig;
        while(act)
        {
            mostrar(act->info,fp);
            act=act->ant;
            cant++;
        }
    }
    return cant;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
  tNodo *act = NULL,*mayor,*prox =(*p);
    int cont,contMayor;

    if(!*p)
        return;

    while(prox->ant!=NULL)
        prox=prox->ant;

    while(prox!=NULL)
    {
        contMayor=0;
            p = &prox;
        while(*p!=NULL)
        {
            act=(*p);
            cont=0;
            while(act!=NULL)
            {
                if(comparar((*p)->info,act->info)==0)
                    cont++;
                act=act->sig;
            }
            if(contMayor<=cont)
            {
                contMayor=cont;
                mayor=(*p);
            }
            p=&(*p)->sig;
        }

            while(prox!=NULL && comparar(mayor->info,prox->info)==0)
                prox=prox->sig;


            if(prox!=NULL)
            {
                act=prox->sig;
                while(act!=NULL)
                {
                    if(comparar(act->info,mayor->info)==0)
                    {
                        if(act->sig)
                            act->sig->ant=act->ant;
                        if(act->ant)
                            act->ant->sig=act->sig;

                        act->ant=prox->ant;
                        act->sig=prox;

                        if(prox->ant)
                            prox->ant->sig=act;
                        prox->ant=act;
                        act=prox->sig;

                    }
                    else
                        act=act->sig;
                }
            }
    }
}


int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *))
{
    int cant;
    int cantNotas=0;
    tNodo *aux;

    if(p==NULL)
        return 0;


    while((*p)->sig)
        p=&(*p)->sig;


    while(*p)
    {
        mostrar(NULL,fp);
        mostrar((*p)->info,fp);
        aux=(*p);
        (*p)=(*p)->ant;
        cant=1;

        while((*p)&&comparar((*p)->info,aux->info)==0)
        {
            cant++;
            cantNotas++;
            mostrar((*p)->info,fp);
            acumular(&(*p)->info,&(*p)->tamInfo,aux->info,aux->tamInfo);
            free(aux->info);
            free(aux);
            aux=(*p);
            (*p)=(*p)->ant;
        }
        mostrar2(aux->info,cant,fp);
        cantNotas++;
        free(aux->info);
        free(aux);

    }
        *p=NULL;
        return cantNotas;
}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

