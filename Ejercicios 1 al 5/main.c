#include <stdio.h>
#include <stdlib.h>

int esnumero(int);
int factorial(int);
float combinatorio(int,int);
float exponencial(int,float);
int potencia(int,int);
float raiz(int,float);
float modulo(float);

int main()
{
    int numero,compara,fact,num,num2;
    float tole,resultado;

    printf("Hola ingrese la opcion deseada para realizar la operacion\n");
    printf("1=EJERCICIO 1\n");
    printf("2=EJERCICIO 2\n");
    printf("3=EJERCICIO 3\n");
    printf("4=EJERCICIO 4\n");
    printf("5=EJERCICIO 5\n");

    scanf("%d",&numero);
    compara=esnumero(numero);
    if(compara==1)
    {
        switch(numero){

    case 1:
        printf("ingrese el nro del numero a factorizar\n");
        scanf("%d",&num);
        fact=factorial(num);
        printf("el factorial es %d",fact);
        break;
    case 2:
        printf("ingrese 2 numeros para realizar su combinatorio \n");
        scanf("%d",&num);
        scanf("%d",&num2);
        resultado=combinatorio(num,num2);
        printf("el numero combinatorio es %f",resultado);
        break;
    case 3:
        printf("ingrese un numero para calcular e elevado a la x\n");

        scanf("%d",&num);
        printf("ingrese una tolerancia\n");
        scanf("%f",&tole);
        resultado=exponencial(num,tole);
        printf("el resultado es %f",resultado);
        break;
    case 4:
        printf("ingrese el numero a racionalizar\n");
        scanf("%d",&num);
        printf("ingrese la tolerancia\n");
        scanf("%f",&tole);
        resultado=raiz(num,tole);
        printf("el resultado es %f",resultado);
        break;
    case 5:
        printf("ingrese un numero para determinar si esta en la serie fibonacci\n");
        scanf("%d",&num);
        fibonacci(num);
        break;
    default:
        printf("usted ha ingresado una opcion incorrecta, por favor vuelva a ingresar\n");
        break;
        }
    }

    return 0;
}
