#include <stdio.h>
#include <stdlib.h>

void multiplicacionrusa(int,int);
void conversion(float);

int main()
{
    int num,n1,n2;
    float n3;
    printf("ingrese el ejercicio que desea realizar\n");
    printf("Ejercicio 20\n");
    printf("Ejercicio 21\n");
    scanf("%d",&num);
    switch(num)
    {
    case 20:
        printf("ingrese 2 numeros para realizar la multiplicacion rusa\n");
        printf("ingrese el primer numero \n");
        scanf("%d",&n1);
        printf("ingrese el segundo numero \n");
        scanf("%d",&n2);
        multiplicacionrusa(n1,n2);
        break;
    case 21:
        printf("ingrese un numero cualquiera para obtener su parte entera\n");
        scanf("%f",&n3);
        conversion(n3);
        break;
    }
    return 0;
}
