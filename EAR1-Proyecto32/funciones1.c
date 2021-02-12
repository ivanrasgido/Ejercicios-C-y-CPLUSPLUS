/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#include "funciones.h"
#define A_MINUSCULA_MIO(A) ((A)>='A'&&(A)<='Z'?(A)+=32:(A))

void desplazamiento(int tamR,int tamB,char* cade,char* cadeR);
void reemplazo(const char* reem,char* cade);
int strlen_mio(const char* a);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//* PUNTO 1                                            *//**//**//**/

int buscarYReemplazar_MIO(char *cade, int tam,const char *busc, const char *reem)
{
    const char* puntBusc=busc;
    const char* puntReem=reem;
    char* puntCoincide;
    char* puntCadeFin=cade+tam-strlen_mio(busc);
    char  auxBusc=*busc;
    char  auxCade=*cade;
    int band=0,sobrepaso=0,contReem=0;
    int tamReem=strlen_mio(reem);
    int tamBusc=strlen_mio(busc);
    int tamanioCont;

    if(tamReem<tamBusc)//Para que no de negativo el tamanio
    {
        tamanioCont=tamBusc-tamReem;
    }
    else
    {
        tamanioCont=tamReem-tamBusc;
    }

    if(reem==NULL)
        return 0;

    while(auxCade)
    {
        A_MINUSCULA_MIO(auxBusc);
        A_MINUSCULA_MIO(auxCade);

        if(auxBusc==auxCade)     // va a ser la primera vez que encuentre la coincidencia y ahi va a dejar un puntero para luego reemplazar
        {
            if(band==0)
            {
                puntCoincide=cade;
                band=1;
            }
            cade++;
            puntBusc++;
            auxBusc=*puntBusc;
            auxCade=*cade;
        }
        else
        {
            if(auxBusc=='\0'&&tam-tamanioCont>0)//si es el final de la cadena buscar y la resta del contador de tamanio con el tamanio de la cadena es mayor a 0 se hace el reemplazo
            {
                desplazamiento(tamReem,tamBusc,puntCadeFin,cade);
                if(tamReem>tamBusc)//para posicionar el puntero de cade en la posicion siguiente dependiendo del tamanio del array reempl
                    cade+=(tamReem-tamBusc);
                else
                    cade-=(tamBusc-tamReem);
                reemplazo(puntReem,puntCoincide);
                contReem++;
                puntReem=reem;//reseteo el puntero reem
                tamanioCont+=tamReem;
                puntBusc=busc;
                auxBusc=*puntBusc;
                auxCade=*cade;
            }
            else //si no son iguales sigo recorriendo el array cade y reseteo el puntero del array buscar
            {
                if(band==1)
                    band=0;

                cade++;
                puntBusc=busc;//reseteo el puntero buscar
                auxCade=*cade;
                auxBusc=*puntBusc;
            }

        }
    }
    if(tam-tamanioCont<0)
        sobrepaso=1;

    if(contReem==0)// si no se pudo reemplazar ninguno
    {
        return -1;
    }
    else
    {
        if(sobrepaso==1) //si se sobrepaso del limite
        {
            return -contReem-1;
        }

    }

    return contReem; //si no hubo problemas
}

void desplazamiento(int tamR,int tamB,char* cade,char* cadeR)
{

    char aux;
    char* cadeAct;
    cadeR--;

    while(cade!=cadeR&&*cadeR!='\0')
    {
        if(tamR>tamB)//desplazamiento derecha
        {
            while(*cade=='\0') //ya el puntero posicionado en el final lo decremento hasta encontrar algun caracter
                cade--;
            cadeAct=cade;       //luego con cade voy guardando el contenido en una variable auxiliar
            aux=*cade;          //para luego cuando lo incremente en la cantidad del array reempl-buscar   pueda guardar el contenido
            *cade=' ';          //y luego decremento el puntero cadeAct y asigno a cade para ir recorriendo y desplazando hasta que
            cade+=(tamR-tamB);  // cade sea igual que cadeR
            *cade=aux;
            cadeAct--;
            cade=cadeAct;

        }
        else//desplazamiento izquierda
        {
            cade=cadeR+1;
            aux=*cade;
            cade-=(tamB-tamR);
            *cade=aux;
            cadeR++;

        }
    }
}

void reemplazo(const char* reem,char* cade)
{
    while(*reem!='\0')
    {
        *cade=*reem;
        cade++;
        reem++;
    }
}

int strlen_mio(const char* a)
{
    int cont=0;

    while(*a!='\0')
    {
        cont++;
        a++;
    }
    return cont;
}
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

