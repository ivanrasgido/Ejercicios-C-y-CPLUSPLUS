#include <stdio.h>
#include <stdlib.h>

typedef struct{
        int dia;
        int mes;
        int anio;
}t_fecha;

void validarfecha(t_fecha);
void diasiguiente(t_fecha);
void sumndias(t_fecha,int);
void restarndias(t_fecha,int);
void restarfechas(t_fecha,t_fecha);
void diadelasemana(t_fecha);

int main()
{   int num;
    t_fecha f,f2;
    printf("Ingrese el ejercicio que desea realizar\n");
    printf("Ejercicio 14\n");
    printf("Ejercicio 15\n");
    printf("Ejercicio 16\n");
    printf("Ejercicio 17\n");
    printf("Ejercicio 18\n");
    printf("Ejercicio 19\n");
    scanf("%d",&num);

    switch(num)
    {
    case 14:
        printf("programa para validar una fecha\n");
        printf("ingrese dia\n");
        scanf("%d",&f.dia);
        printf("ingrese mes\n");
        scanf("%d",&f.mes);
        printf("ingrese anio\n");
        scanf("%d",&f.anio);
        validarfecha(f);
        break;
    case 15:
        printf("programa para saber fecha del dia siguiente\n");
        printf("ingrese dia\n");
        scanf("%d",&f.dia);
        printf("ingrese mes\n");
        scanf("%d",&f.mes);
        printf("ingrese anio\n");
        scanf("%d",&f.anio);
        validarfecha(f);
        diasiguiente(f);
        break;
    case 16:
        printf("programa para sumar N dias a una fecha \n");
        printf("ingrese dia\n");
        scanf("%d",&f.dia);
        printf("ingrese mes\n");
        scanf("%d",&f.mes);
        printf("ingrese anio\n");
        scanf("%d",&f.anio);
        printf("ingrese la cantidad a sumar\n");
        scanf("%d",&num);
        sumndias(f,num);
        break;
    case 17:
        printf("programa para restar N dias a una fecha \n");
        printf("ingrese dia\n");
        scanf("%d",&f.dia);
        printf("ingrese mes\n");
        scanf("%d",&f.mes);
        printf("ingrese anio\n");
        scanf("%d",&f.anio);
        printf("ingrese la cantidad a restar\n");
        scanf("%d",&num);
        restarndias(f,num);
        break;
    case 18:
        printf("programa para saber la cantidad de dias entre ellas\n");
        printf("ingrese dia de la primera fecha\n");
        scanf("%d",&f.dia);
        printf("ingrese mes de la primera fecha\n");
        scanf("%d",&f.mes);
        printf("ingrese anio de la primera fecha\n");
        scanf("%d",&f.anio);
        printf("ingrese dia de la segunda fecha\n");
        scanf("%d",&f2.dia);
        printf("ingrese mes de la segunda fecha\n");
        scanf("%d",&f2.mes);
        printf("ingrese anio de la segunda fecha\n");
        scanf("%d",&f2.anio);
        restarfechas(f,f2);
        break;
    case 19:
        printf("programa para saber que dia de la semana es \n");
        printf("ingrese dia\n");
        scanf("%d",&f.dia);
        printf("ingrese mes\n");
        scanf("%d",&f.mes);
        printf("ingrese anio\n");
        scanf("%d",&f.anio);
        diadelasemana(f);
        break;
    }
    return 0;
}
