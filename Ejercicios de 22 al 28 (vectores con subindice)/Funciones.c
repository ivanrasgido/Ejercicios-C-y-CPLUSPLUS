#include <stdio.h>

int potencia (int base , int exp);
int deasciiaent(char *pc);

void inserelemizqder(int v[],int cant, int num,int pos)
{
    int i,j;
    for(i=0; i<pos-1; i++)
    {
        v[i]=v[i+1];
    }
    v[pos-1]=num;
    for(j=0; j<cant; j++)
    {
        printf("%d\n\n",v[j]);
    }
}

void inserelemderizq(int v[],int cant,int num,int pos)
{
    int i,j;
    for(i=cant-1; i>=pos-1; i--)
    {
        v[i]=v[i-1];
    }
    v[pos-1]=num;
    for(j=0; j<cant; j++)
    {
        printf("%d\n\n",v[j]);
    }
}

void insertarordenado(int v[],int cant,int num)
{
    int i,j,k,aux;
    int flag=0;
    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(v[j]<v[i])
            {
                aux=v[j];
                v[j]=v[i];
                v[i]=aux;
            }
        }
    }
    for(i=0; i<cant; i++)
    {
        printf("%d\t",v[i]);
    }
    printf("vector ordenado\n");

    i=0;
    j=cant-1;

    while(flag!=1)
    {
        if(v[i-1]<num&&v[i]>num)
        {
            for(k=0;k<(cant-i)-1;k++)
            {
                v[j]=v[j-1];
                j--;

                flag=1;
            }
        }
        i++;
    }
    v[i-1]=num;

    for(i=0; i<cant; i++)
    {
        printf("%d\t",v[i]);
    }
    printf("vector con elemento insertado\n");
}

void eliminarporposicion(int v[],int cant,int pos)
{int i;
    v[pos]=0;
    for(i=0;i<cant-1;i++)
    {
        printf("%d\t",v[i]);
    }
}

void eliminarprimerapos(int v[],int cant,int num)
{
    int flag=0;
    int i=0;
    while(flag!=0)
    {
        if(v[i]==num)
        {
            v[i]=0;
            flag=1;
        }
        i++;
    }
    for(i=0;i<cant-1;i++)
    {
        printf("%d\t",v[i]);
    }
}

void eliminartodasapariciones(int v[],int cant,int num)
{
    int i;
    for(i=0;i<cant-1;i++)
    {
        if(v[i]==num)
        {
            v[i]=0;
        }
    }
    for(i=0;i<cant-1;i++)
    {
        printf("%d\t",v[i]);
    }

}

void palindromo(char v[],int cant)
{   int i=0;
    int j=0;
    int flag=0;
    while(v[i]!=cant-1&&v[j]!=0)
    {
        if(v[i]==v[j])
        {
            i++;
            j--;
            flag=1;
        }
        else
        {
            printf("No es palindromo\n");
        }
    }
    if(flag==1)
    {
        printf("Es palindromo\n");
    }
}

void numerico(char *pv,int tam)
{
    float result=0;
    int listo=0,signo=1,entero=0,i,num;
    char *pc;
    while(*pv!='\0')
    {
        if(*pv=='-')
        {
            signo*=-1;
        }
        entero++;
        if(*pv==',')
        {
            pc=pv;
            pc--;
            for(i=0;i<entero-2;i++)
            {
                num=deasciiaent(pc);
                result+=(1*potencia(10,i))*num;
                pc--;
            }
            listo=1;
        }
        pv++;
        if(listo==1)
        {
            for(i=0;i<tam;i++)
            {
                if(*pv!='\0')
                {
                    num=deasciiaent(pv);
                    result+=(0.1/potencia(10,i))*num;
                    pv++;
                }
            }
            result*=signo;
        }
    }
    printf("El resultado es %.3f:",result);
}

int potencia (int base , int exp)
{
    int i;
    int result=1;
    if(exp==0)
    {
        return result;
    }
    for(i=1;i<=exp;i++)
    {
        result*=base;
    }
    return result;
}

int deasciiaent(char *pc)
{
    switch(*pc)
    {
    case 48:
        return 0;
        break;
    case 49:
        return 1;
        break;
    case 50:
        return 2;
        break;
    case 51:
        return 3;
        break;
    case 52:
        return 4;
        break;
    case 53:
        return 5;
        break;
    case 54:
        return 6;
        break;
    case 55:
        return 7;
        break;
    case 56:
        return 8;
        break;
    case 57:
        return 9;
        break;
    }
    return -1;
}
