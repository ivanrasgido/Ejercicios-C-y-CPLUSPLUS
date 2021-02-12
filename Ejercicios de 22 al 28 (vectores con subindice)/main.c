#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void inserelemizqder(int[],int,int,int);
void inserelemderizq(int[],int,int,int);
void insertarordenado(int[],int,int);
void eliminarporposicion(int [],int,int);
void eliminarprimerapos(int [],int,int);
void eliminartodasapariciones(int[],int,int);
void palindromo(char [],int);
void numerico(char *pv,int tam);
int potencia (int base , int exp);

int main()
{
    int num,n1,n2;
    int vec[TAM]={51,30,22,11,4,2,61,7,10,1};
    char vec2[16]={'a','n','i','t','a','l','a','v','a','l','a','t','i','n','a'};
    int tamanio=16;
    char vec3[TAM]={'-','1','2','3','4',',','5','5','6'};
    printf("Elija el ejercicio que desea realizar\n");
    printf("Ejercicio 22\n");
    printf("Ejercicio 23\n");
    printf("Ejercicio 24\n");
    printf("Ejercicio 25\n");
    printf("Ejercicio 26\n");
    printf("Ejercicio 27\n");
    printf("Ejercicio 28\n");
    scanf("%d",&num);

    switch(num)
    {
    case 22:

        printf("indique el elemento a insertar en el arreglo\n");
        scanf("%d",&n1);
        printf("indique en que posicion del arreglo quiere insertarlo\n\n");
        scanf("%d",&n2);
        //inserelemizqder(vec,TAM,n1,n2);
        //inserelemderizq(vec,TAM,n1,n2);
        //falta ver cuando el vector esta lleno
        break;
    case 23:
        printf("indique el elemento a insertar en el arreglo\n");
        scanf("%d",&n1);
        insertarordenado(vec,TAM,n1);
        break;
    case 24:
        printf("indique en que posicion quiere eliminar elemento del array\n");
        scanf("%d",&n1);
        eliminarporposicion(vec,TAM,n1);
        break;
    case 25:
        printf("indique que numero quiere eliminar\n");
        scanf("%d",&n1);
        eliminarprimerapos(vec,TAM,n1);
        break;
    case 26:
        printf("indique que numero quiere eliminar\n");
        scanf("%d",&n1);
        eliminartodasapariciones(vec,TAM,n1);
        break;
    case 27:
        printf("funcion para indicar si el array es palindromo\n");
        palindromo(vec2,tamanio);
        break;
    case 28:
        printf("funcion que convierte un array con numeros en el numero decimal\n");
        numerico(vec3,TAM);
        break;
    }
    return 0;
}
