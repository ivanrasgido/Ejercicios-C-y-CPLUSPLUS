#include <stdio.h>
#include "matrices.h"

void suma(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    printf("\n");
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i<=j)
            {
                res+=m[i][j];
                printf("%d\t",m[i][j]);
            }
        }
        switch(i)
        {
        case 0:
            printf("\n\t");
            break;
        case 1:
            printf("\n\t\t");
            break;
        case 2:
            printf("\n\t\t\t");
            break;
        case 3:
            printf("\n");
            break;
        }

    }

    printf("El resultado es %d\n",res);

}

void suma2(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    printf("\n");
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i>=j)
            {
                res+=m[i][j];
                printf("%d\t",m[i][j]);
            }
        }
        printf("\n");
    }
    printf("El resultado es %d",res);
}

void suma3(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    printf("\n");
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i<j)
            {
                res+=m[i][j];
                printf("%d\t",m[i][j]);
            }
        }
        switch(i)
        {
        case 0:
            printf("\n\t");
            break;
        case 1:
            printf("\n\t\t");
            break;
        case 2:
            printf("\n\t\t\t");
            break;
        case 3:
            printf("\n");
            break;
        }

    }

    printf("El resultado es %d\n",res);
}

void suma4(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    printf("\n");
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i>j)
            {
                res+=m[i][j];
                printf("%d\t",m[i][j]);
            }
        }
        printf("\n");
    }
    printf("El resultado es %d",res);
}

void suma5(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    printf("\n");
    for(i=0;i<f;i++)
    {
        switch(i)
        {
        case 0:
            printf("\n\t\t\t");
            break;
        case 1:
            printf("\n\t\t");
            break;
        case 2:
            printf("\n\t");
            break;
        case 3:
            printf("\n");
            break;
        }

        for(j=0;j<c;j++)
        {
            if(i+j>=c-1)
            {
                res+=m[i][j];
                printf("%d\t",m[i][j]);
            }
        }
        printf("\n");
    }
    printf("El resultado es %d",res);
}

void suma6(int m[][COL],int f,int c)
{
        int i,j;
    int res=0;
    printf("\n");
    for(i=0;i<f;i++)
    {
        switch(i)
        {
        case 0:
            printf("\n\t\t\t");
            break;
        case 1:
            printf("\n\t\t");
            break;
        case 2:
            printf("\n\t");
            break;
        case 3:
            printf("\n");
            break;
        }

        for(j=0;j<c;j++)
        {
            if(i+j>c-1)
            {
                res+=m[i][j];
                printf("%d\t",m[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nEl resultado es %d",res);
}

void suma7(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    printf("\n");
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i+j<=c-1)
            {
                res+=m[i][j];
                printf("%d\t",m[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nEl resultado es %d",res);
}

void suma8(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    printf("\n");
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i+j<c-1)
            {
                res+=m[i][j];
                printf("%d\t",m[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nEl resultado es %d",res);
}

void trazadprin(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i==j)
            {
                res+=m[i][j];
            }
        }
    }
    printf("\nEl resultado es:%d",res);
}

void trazadsecu(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i+j==c-1)
            {
                res+=m[i][j];
            }
        }
    }
    printf("\nEl resultado es:%d",res);
}

void matdiag(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]!=0&&i==j)
            {
                res=1;
            }
            else
            {
                if(m[i][j]==0&&i!=j)
                {
                    res=1;
                }
                else
                {
                    res=0;
                    i=4;
                    j=4;
                }
            }
        }
    }
    if(res==1)
    {
        printf("La matriz es diagonal\n");
    }
    else
    {
        printf("La matriz no es diagonal\n");
    }
}

void matident(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]==1&&i==j)
            {
                res=1;
            }
            else
            {
                if(m[i][j]!=1&&i!=j)
                {
                    res=1;
                }
                else
                {
                    res=0;
                    i=4;
                    j=4;
                }
            }
        }
    }
    if(res==1)
    {
        printf("La matriz es identidad\n");
    }
    else
    {
        printf("La matriz no es identidad\n");
    }

}

void matsim(int m[][COL],int f,int c)
{
    int i,j;
    int res=0;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]==m[j][i])
            {
                res=1;
            }
        }
    }
    if(res==1)
    {
        printf("Su matriz es simetrica\n");
    }
    else
    {
        printf("Su matriz no es simetrica\n");
    }
}

void transponerinsitu(int m[][COL],int f,int c)
{
        int i,j,aux;
        for(i=0;i<f;i++)
        {
            for(j=0;j<c;j++)
            {
                if(i!=j&&i<j)
                {
                    aux=m[j][i];
                    m[j][i]=m[i][j];
                    m[i][j]=aux;
                }
            }
        }
        for(i=0;i<f;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%d\t",m[i][j]);
            }
            printf("\n");
        }
}

void transponer(int m[][3],int f,int c)
{
    int i,j;
    int fila=c;
    int colu=f;
    int mattrans[fila][colu];
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            mattrans[j][i]=m[i][j];
        }
    }
    printf("\n matriz sin transponer \n");
    for(i=0;i<f;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%d\t",m[i][j]);
            }
            printf("\n");
        }
    printf("\n matriz transpuesta\n");
    for(i=0;i<fila;i++)
        {
            for(j=0;j<colu;j++)
            {
                printf("%d\t",mattrans[i][j]);
            }
            printf("\n");
        }
}

void productodematrices(int m1[][3],int f1,int c1,int m2[][2],int f2,int c2)
{
    int fila=f1;
    int colu=c2;
    int mprod[fila][colu];
    int i,j,k;
    for(i=0;i<f1;i++)//va hasta 2
    {

        for(j=0;j<c2;j++)// va hasta 2
        {
            mprod[i][j]=0;
            for(k=0;k<f2;k++)//va hasta 3
            {

                mprod[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    for(i=0;i<fila;i++)
    {
        for(j=0;j<colu;j++)
        {
            printf("%d\t",mprod[i][j]);
        }
        printf("\n");
    }
}
