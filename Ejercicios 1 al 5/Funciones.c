
#include <stdio.h>

float modulo(float);
int potencia(int,int);

int esnumero(int n)
{
        if(n>=1&&n<=10)
        {
            return 1;
        }
        else
        {
            printf("no eligio un numero del menu\n");
            return 0;
        }

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

float combinatorio(int n1,int n2)
{   int m,n,j;
    float resultado;
    m=factorial(n1);
    n=factorial(n2);
    j=factorial(n1-n2);
    resultado=m/(n*j);
    return resultado;
}

float exponencial(int x,float t)
{
    float resultado=1;
    float numerador,denominador;
    int exp=1;
    while(resultado<t)
    {
        if(x!=0)
        {

            numerador=potencia(x,exp);
            denominador=factorial(exp);
            resultado+=numerador/denominador;
            exp++;
        }
        else
        {
            return resultado;
        }
    }
    return resultado;
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
float raiz(int x,float t)
{
   float raizant=1;
   float raiznue=0;
    float aux=raizant;
    while(modulo(raiznue-(aux))>t)
    {
            raiznue=0.5*(raizant+(x/raizant));//2
            aux=raizant;//1
            raizant=raiznue;//2
    }
    return raiznue;
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

void fibonacci(int n)
{
     int n1=1;
     int n2=1;
     int result=0;

     while(n!=result)
     {
         if(n!=result)
         {
             result=n1+n2;
             n1=n2;
            n2=result;
         }
         else
            printf("pertenece\n");
     }

}
