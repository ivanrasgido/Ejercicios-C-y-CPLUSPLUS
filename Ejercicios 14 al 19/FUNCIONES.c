#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} t_fecha;

int bisiesto(t_fecha);
int cantdiasmes(t_fecha);
int modulodelmes(t_fecha);

void validarfecha(t_fecha f)
{
    if(f.anio>=1900&&f.anio<=2100)
    {
        if(f.mes>=1&&f.mes<=12)
        {
            if(f.dia>=1&&f.dia<=31)
            {
                if(f.mes==1||f.mes==3||f.mes==5||f.mes==7||f.mes==8||f.mes==10||f.mes==12)
                {
                    printf("fecha valida: %d/%d/%d \n",f.dia,f.mes,f.anio);//31
                }
                else
                {
                    if(f.mes==2&&f.dia<=bisiesto(f))
                    {
                        printf("fecha valida: %d/%d/%d \n",f.dia,f.mes,f.anio);
                    }
                    else
                    {
                        if(f.dia<=30&&f.mes!=2)
                        {
                            printf("fecha valida: %d/%d/%d \n",f.dia,f.mes,f.anio);//30
                        }
                        else
                            printf("no es una fecha valida vuelva a ingresar otra \n");

                    }
                }

            }
        }
    }
}

int bisiesto(t_fecha f)
{
    if(f.anio%4==0&&f.anio%100!=0)
    {
        return 29;
    }
    return 28;
}

void diasiguiente(t_fecha f)
{
    if(f.mes==12&&f.dia==31)
    {
        f.dia=1;
        f.mes=1;
        f.anio+=1;
        printf("el dia siguiente es %d/%d/%d \n",f.dia,f.mes,f.anio);
    }
    else
    {
        if(f.dia==31||f.dia==30||f.dia==29||f.dia==28)
        {
            f.dia=1;
            f.mes+=1;
            printf("el dia siguiente es %d/%d/%d \n",f.dia,f.mes,f.anio);
        }
        else
        {
            f.dia+=1;
            printf("el dia siguiente es %d/%d/%d \n",f.dia,f.mes,f.anio);
        }
    }
}

void sumndias(t_fecha f,int n)
{
    int mesini=f.mes;
    int acum=0;
    int anio=0;
    while(n>=acum)
    {

        if(mesini==f.mes&&f.anio!=anio)//se fija si es el mes inicial
        {
            if(f.mes==13)
            {
                f.mes=1;
                f.anio++;
                anio=f.anio;
            }
            acum+=cantdiasmes(f)-f.dia;//resta la cantidad total de dias del mes con el dia de la fecha
            f.mes++;


        }
        else
        {
            if(f.mes==13)
            {
                f.mes=1;
                f.anio++;
                anio=f.anio;
            }

            acum+=cantdiasmes(f);
            f.mes++;

        }

    }
    acum-=n;
    f.mes--;
    f.dia=cantdiasmes(f)-acum;
    printf("La fecha nueva es %d/%d/%d",f.dia,f.mes,f.anio);

}

int cantdiasmes(t_fecha f)//funcion para saber cuantos dias tiene cada mes
{
    if(f.mes==1||f.mes==3||f.mes==5||f.mes==7||f.mes==8||f.mes==10||f.mes==12)
    {
        return 31;
    }
    else
    {
        if(f.mes==2)
        {
            return bisiesto(f);
        }
        else
        {
            return 30;
        }
    }
}

void restarndias(t_fecha f,int n)
{
    int cont=0;
    int mesini=f.mes;
    int anio=0;
    while(n>=cont)
    {
        if(mesini==f.mes&&f.anio!=anio)
        {
            if(f.mes==0)
            {
                f.mes=12;
                f.anio--;
                anio=f.anio;
            }
            cont=f.dia;
            f.mes--;
        }
        else
        {
            if(f.mes==0)
            {
                f.mes=12;
                f.anio--;
                anio=f.anio;
            }
            cont+=cantdiasmes(f);
            f.mes--;
        }
    }
    f.dia=cont-n;
    f.mes++;
    printf("La fecha resultante es %d/%d/%d \n",f.dia,f.mes,f.anio);
}

void restarfechas(t_fecha f1,t_fecha f2)
{
    int i;
    int tope;
    int result=0;
    result=(f2.anio-f1.anio)-1;
    result*=365;
    result+=cantdiasmes(f1)-f1.dia;
    f1.mes++;
    tope=(12-f1.mes)+f2.mes;
    for(i=f1.anio; i<=f2.anio; i++)
    {
        if(i%4==0&&i%100!=0)
        {
            result+=1;
        }
    }

    for(i=0; i<tope; i++)
    {
        if(f1.mes==13)
        {
            f1.mes-=12;
            f1.anio=f2.anio;
        }
        result+=cantdiasmes(f1);
        f1.mes++;
    }
    result+=f2.dia;

    printf("la cantidad de dias entre las fechas es : %d",result);
}

void diadelasemana(t_fecha f)
{
    int d;

    d=(((f.anio-1)%7+((f.anio-1)/4-(3*(f.anio-1)/100+1)/4))%7+modulodelmes(f)+f.dia%7)%7;

    switch(d)
    {
    case 0:
        printf("Domingo \n");
        break;
    case 1:
        printf("Lunes \n");
        break;
    case 2:
        printf("Martes \n");
        break;
    case 3:
        printf("Miercoles \n");
        break;
    case 4:
        printf("Jueves \n");
        break;
    case 5:
        printf("Viernes \n");
        break;
    case 6:
        printf("Sabado \n");
        break;
    }
}

int modulodelmes(t_fecha f)
{
    int i;
    int result=0;
    for(i=0; i<f.mes; i++)
    {
        if(f.mes==1||f.mes==3||f.mes==5||f.mes==7||f.mes==8||f.mes==10||f.mes==12)
        {
            result+=31%7;
            f.mes--;
        }
        else
        {
            if(f.mes==4||f.mes==6||f.mes==9||f.mes==11)
            {
                result+=30%7;
                f.mes--;
            }
            else
            {
                if(f.anio%4==0&&f.anio%100!=0)
                {
                    result+=29%7;
                    f.mes--;
                }
                else
                {
                    result+=28%7;
                    f.mes--;
                }
            }
        }
    }
    return result;
}
