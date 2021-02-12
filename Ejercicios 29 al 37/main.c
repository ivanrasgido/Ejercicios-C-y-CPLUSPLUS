#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

int main()
{
    int num,n;
    int mat[FIL][COL]={{1,2,3,4},{2,3,4,5},{3,4,2,1},{3,2,1,4}};
    int mat2[FIL][COL]={{1,2,0,0},{0,4,0,0},{0,0,9,0},{0,0,0,3}};
    int mat3[FIL][COL]={{0,1,2,3},{1,3,4,5},{2,4,7,2},{3,5,2,8}};
    int mat4[2][3]={{1,2,3},{1,3,4}};
    int mat5[3][2]={{2,1},{1,2},{3,2}};
    printf("Por favor ingrese la opcion que desea realizar\n");
    printf("Ejercicio 29\n");
    printf("Ejercicio 30\n");
    printf("Ejercicio 31\n");
    printf("Ejercicio 32\n");
    printf("Ejercicio 33\n");
    printf("Ejercicio 34\n");
    printf("Ejercicio 35\n");
    printf("Ejercicio 36\n");
    printf("Ejercicio 37\n");
    scanf("%d",&num);

    switch(num)
    {
    case 29:
        printf("funciones para sumar elementos de la matriz segun lo pedido\n");
        printf("Elija cual de los 8 modos necesita realizar\n");
        printf("ingrese del 1 al 8\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            suma(mat,FIL,COL);
            break;
        case 2:
            suma2(mat,FIL,COL);
            break;
        case 3:
            suma3(mat,FIL,COL);
            break;
        case 4:
            suma4(mat,FIL,COL);
            break;
        case 5:
            suma5(mat,FIL,COL);
            break;
        case 6:
            suma6(mat,FIL,COL);
            break;
        case 7:
            suma7(mat,FIL,COL);
            break;
        case 8:
            suma8(mat,FIL,COL);
            break;
        default:
            printf("vuelva a ingresar una opcion correcta\n");
        }
        break;
    case 30:
        printf("ingrese si quiere realizar la suma de la diagonal principal(1) o secundaria(2)\n");
        printf("ingrese 1 o 2\n");
        scanf("%d",&n);

        switch(n)
        {
        case 1:
             trazadprin(mat,FIL,COL);
            break;
        case 2:
            trazadsecu(mat,FIL,COL);
            break;
        }
        break;
    case 31:
        printf("Funcion para determinar si una matriz es diagonal\n");
        matdiag(mat2,FIL,COL);
        break;
    case 32:
        printf("Funcion para determinar si una matriz es identidad\n");
        matident(mat2,FIL,COL);
        break;
    case 33:
        printf("Funcion para determinar si una matriz es simetrica\n");
        matsim(mat3,FIL,COL);
        break;
    case 34:
        printf("Funcion para transponer in situ una matriz de nxn \n");
        transponerinsitu(mat,FIL,COL);
        break;
    case 35:
        printf("Funcion para transponer cualquier matriz \n");
        transponer(mat4,2,3);
        break;
    case 36:
        printf("Funcion para realizar el producto entre 2 matrices \n");
        productodematrices(mat4,2,3,mat5,3,2);
        break;
    default:
        printf("vuelva a ingresar una opcion correcta\n");
        break;
    }
    return 0;
}
