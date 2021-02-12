
#include <stdio.h>

int factorial(int);
int potencia(int,int);
float modulo(float);
void pda(int);
int sumasuc(int,int);
void cociente (int,int);
int ejercicio10(int);


float seno(int x,float t)
{
    int exp=3;
    float result=1;
    float numerador,denominador;

    while(modulo(result)>t)
    {
         numerador=potencia(x,exp);
        denominador=factorial(exp);
        result-=(numerador/denominador);
        exp+=2;
        result*=-1;

    }
    return result;
}

float modulo(float x)
{
    float result;
        result=x;

    if(x<0)
    {
        result=result*-1;
    }
    return result;
}

int potencia(int x,int e)
{
    int i;
    int solu=1;

    for(i=0;i<e;i++)
    {
        solu=solu*x;
    }
    return solu;
}

int factorial(int f)
{
    int i;
    if(f==0)
        return 1;
    else
    {
        for(i=f;i>1;i--)
        {
            f*=(i-1);
        }
        return f;
    }
}

void pda(int n)
{
    int acum=0;
    int i;
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            acum+=i;
        }
    }
    if(acum==n)
    {
        printf("perfecto\n");
    }
    else
    {
        if(acum>n)
        {
            printf("abundante\n");
        }
        else
        {
            printf("deficiente\n");
        }
    }
}

int sumasuc(int n1,int n2)
{
    int resul=0;
    int i;
    if(n1!=0&&n2!=0)
    {
        for(i=1;i<=n2;i++)
        {
            resul+=n1;
        }
    }
    else
    {
        return resul;
    }
    return resul;
}

void cociente (int n1,int n2)
{
     int coci=0;
     int resto=0;
     coci=n1/n2;
     resto=n1%n2;
     printf("el cociente es %d y el resto %d\n",coci,resto);
}

int ejercicio10(int n)
{
  int resul=0;
   int tope=n;
   int i;
    for(i=0;i<tope;i++)
    {
        resul+=n;
        n--;
    }
    return resul;
}
