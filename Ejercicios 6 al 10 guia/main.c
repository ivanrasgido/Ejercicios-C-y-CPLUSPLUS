#include <stdio.h>
#include <stdlib.h>

float seno(int,float);
void pda(int);
int sumasuc(int,int);
void cociente (int,int);
int ejercicio10(int);


int main()
{
    int num,num2,re;
    float tole,resultado;
    printf("Hello ingrese el ejercicio que desea realizar\n");
    printf("Ejercicio 6\n");
    printf("Ejercicio 7\n");
    printf("Ejercicio 8\n");
    printf("Ejercicio 9\n");
    printf("Ejercicio 10\n");
    scanf("%d",&num);

    switch(num)

    {
    case 6:
        printf("ingrese el numero\n");
        scanf("%d",&num);
        printf("ingrese una tolerancia\n");
        scanf("%f",&tole);
        resultado=seno(num,tole);
        printf("El resultado es %f",resultado);
        break;
    case 7:
        printf("ingrese el numero a determinar\n");
        scanf("%d",&num);
        pda(num);
        break;
    case 8:
        printf("ingrese 2 numeros para realizar el producto \n");
        scanf("%d",&num);
        scanf("%d",&num2);
        re=sumasuc(num,num2);
        printf("el resultado es %d",re);
        break;
    case 9:
        printf("ingrese 2 numeros para realizar el cociente\n");
        scanf("%d",&num);
        scanf("%d",&num2);
        cociente(num,num2);
        break;
    case 10:
        printf("elija un numero para calcular la suma de sus primeros numeros\n");
        scanf("%d",&num);
        re=ejercicio10(num);
        printf("el resultado es %d",re);
        break;
    default:
        printf("vuelva a elegir una opcion valida\n");

    }


    return 0;
}
