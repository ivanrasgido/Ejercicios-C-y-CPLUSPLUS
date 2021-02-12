/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
#include <stdlib.h>
#define minimo( X , Y ) ( (X) <= (Y) ? (X) : (Y) )

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/




void mostrarMovimTxt_MIO(const tMovi *d,FILE *fp)
{

    if(d)
        fprintf(fp,
                "%-*s%10.2lf\n",
                (int)sizeof(d->ctaCte)-1,d->ctaCte,
                d->saldo);
    else
    {
        fprintf(fp,
                "%-*s   %-*s \n",
                (int)sizeof(d->ctaCte)-1,"Nro Cuenta Banc",
                (int)sizeof(d->saldo)-1,"Importe");
    }
}

void mostrarTotalTxt_MIO(const tMovi *d,FILE *fp)
{
    fprintf(fp,
            "%-*s%10.2lf \n",
            (int)sizeof(d->ctaCte)-1,"Total Cliente:",
            d->saldo);
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarMovim_MIO(const void *d, FILE *fp)
{
    mostrarMovimTxt_MIO((const tMovi*)d,fp);
}

int compararMovim_MIO(const void *d1, const void *d2)
{
    /// compara movimientos sirve para el ordenamiento para ordenar
    tMovi* comp1=(tMovi*)d1;
    tMovi* comp2=(tMovi*)d2;
    char* cade1=comp1->ctaCte;
    char* cade2=comp2->ctaCte;
    while(*cade1!='\0'&&*cade2!='\0')
    {
        if(*cade1=='-'&&*cade2=='-')
        {
            cade1++;
            cade2++;
            while(*cade1!='-'&&*cade2!='-')
            {
                if(*cade1<*cade2)
                {
                    return -1;
                }
                else
                {
                    if(*cade1>*cade2)
                        return 1;
                }
                cade1++;
                cade2++;

            }
            cade1++;
            cade2++;

        }
        else
        {
            if(*cade1<*cade2)
            {
                return -1;
            }
            else
            {
                if(*cade1>*cade2)
                    return 1;
            }
            cade1++;
            cade2++;
        }

    }
    return 0;
}

int esCtaCte002_MIO(const void *d)
{
    ///detecta si es la cuenta corriente 002
    tMovi* cuenta=(tMovi*)d;
    char* primerDigito=cuenta->ctaCte+12;
    char* segundoDigito=cuenta->ctaCte+13;
    char* tercerDigito=cuenta->ctaCte+14;
    if(*primerDigito=='0'&&*segundoDigito=='0'&&*tercerDigito=='2')
        return 1;


    return 0;
}

int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                          const void *ori, unsigned tamOri)
{
    /// acumula los movimientos de cada saldo
    tMovi* saldo1=(tMovi*)*dest;
    tMovi* saldo2=(tMovi*)ori;

    saldo1->saldo=saldo1->saldo+saldo2->saldo;

    return 1;
}

void mostrarTotal_MIO(const void *d, FILE *fp)
{
    mostrarTotalTxt_MIO((const tMovi*)d,fp);
}


/**//* para el TDA LISTA                                                  *//**/

int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp)
{
    mostrar(NULL,fp);

    int cant=0;
    while(*p)
    {
        mostrar((*p)->info,fp);
        p = &(*p)->sig;
        cant++;
    }
    return cant;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    tLista* pri=&(*p);

    if(*p==NULL)
        return;
    while((*p)->sig)
    {
        if(comparar((*p)->info,(*p)->sig->info)>0)
        {
            tLista *q=pri;
            tNodo* aux=(*p)->sig;

            (*p)->sig=aux->sig;
            while(comparar((*q)->info,aux->info)<0)
                q=&(*q)->sig;
            aux->sig=*q;
            *q=aux;

        }
        else
            p=&(*p)->sig;
    }

}


int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int comparar2(const void *d),
                                      int acumular(void **, unsigned *,
                                              const void *, unsigned),
                                      void mostrar(const void *, FILE *),
                                      void mostrar2(const void *, FILE *))
{

    tNodo* aux=*p;
    int cant=0;
    while((*p)->sig)
    {
        if(comparar2((*p)->info))
        {
                if(comparar((*p)->info,(*p)->sig->info)==0&&(*p)->sig)
                {
                    while(comparar2((*p)->info)&&(*p)->sig)
                    {
                        aux=(*p);
                        cant++;
                        (*p)=aux->sig;
                        mostrar(aux->info,fpPant);
                        acumular(&aux->info,&aux->tamInfo,aux->sig->info,aux->sig->tamInfo);
                        free(aux->info);
                        free(aux);
                    }
                    if(!(*p)->sig)
                    {
                        aux=(*p);
                        cant++;
                        mostrar(aux->info,fpPant);
                        mostrar2(aux,fpPant);
                        free(aux->info);
                        free(aux);
                        return cant;
                    }
                    else
                        mostrar2((*p)->info,fpPant);
                }
                else
                {
                    aux=(*p);
                    cant++;
                    (*p)=aux->sig;
                    mostrar(aux->info,fpPant);
                    mostrar2(aux->info,fpPant);
                    free(aux->info);
                    free(aux);
                }

        }
        else
        {
            if((*p)->sig->sig)
                p=&(*p)->sig;
        }
    }

    return cant;
}




int  vaciarListaYMostrar_MIO(tLista *p,void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int cant=0;
    while(*p)
    {
        tNodo* aux=*p;
        cant++;
        *p=aux->sig;
        mostrar(aux->info,fp);
        free(aux->info);
        free(aux);
    }
    return cant;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

