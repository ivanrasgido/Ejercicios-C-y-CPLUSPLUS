#include <stdio.h>

void multiplicacionrusa(int n1,int n2)
{

    int result=0;
    int impar=0;
    int par=0;
    if(n1%2!=0&&n2%2==0)
    {
        result+=n2;
    }
    while(n1!=1)
    {
        impar=n1/2;
        par=n2*2;
        if(impar%2!=0&&par%2==0)
        {
            result+=par;
        }
        n1=n1/2;
        n2=n2*2;
    }
    printf("El resultado de la multiplicacion es : %d",result);
}

void conversion(float n)
{
    int r=n;
    printf("el numero %f fue convertido a %d\n",n,r);
}
