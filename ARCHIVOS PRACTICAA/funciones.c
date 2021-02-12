#include "ARCHIVOS.h"


int crearArchivobinario(char *nombrearchivo )
{
    t_persona per[]=
    {
        {12345678,{11,12,2010},"pancracio dominguez",1000.500},
        {13435256,{12,01,2000},"juan manuel alvarez",500.470},
        {43253421,{01,04,1990},"silvio soldan",700.45},
        {43232113,{07,05,1995},"benito juarez",350.34}
    };
    FILE *pf;
    pf=fopen(nombrearchivo,"wb");
    if(pf)
    {
        fwrite(per,sizeof(per),1,pf);
        fclose(pf);
        return 0;
    }
    return -2;
}

int LeeryMostrarArchivobinario(char *nombredearchivo)
{
    t_persona per;
    FILE *pf;
    pf=fopen(nombredearchivo,"rb");
    if(!pf)
    {
        return -1;
    }
    mostrarempleado(NULL);
    fread(&per,sizeof(t_persona),1,pf);
    while(!feof(pf))
    {
        mostrarempleado(&per);
        fread(&per,sizeof(t_persona),1,pf);
    }
    fclose(pf);
    return 0;
}

void mostrarempleado(const t_persona *emp)
{
    if(!emp)
    {
        printf("DNI         FECHA DE NACIMIENTO           NOMBRE Y APELLIDO     \t\t\t\t SUELDO\n");
        printf("--------    ---------                     ------------------    \t\t\t\t -------\n");
        return;
    }
    printf("%08ld    %02d/%02d/%04d \t\t\t %-*.*s  %10.2f \n",
           emp->dni,
           emp->fnac.dia,
           emp->fnac.mes,
           emp->fnac.anio,
           sizeof(emp->nomyap)-1,
           sizeof(emp->nomyap)-1,
           emp->nomyap,
           emp->sueldo);

}



int buscarporDNIarchivobinario(t_persona *per, char *nom1)
{
    long dni;
    FILE *pf;
    pf=fopen(nom1,"rb");
    if(!pf)
    {
        return -1;
    }
    printf("\ningrese el dni a buscar\n");
    scanf("%ld",&dni);
    fread(per,sizeof(t_persona),1,pf);

    while(per->dni!=dni&&!feof(pf))
    {

        fread(per,sizeof(t_persona),1,pf);
    }
    mostrarempleado(per);
    return 0;
    fclose(pf);
}

int creararchivotextolf(char *nom1,char *nom2)
{
    t_persona per;
    FILE *fpbin,
         *fptxtlf;

    fpbin=fopen(nom1,"rb");
    if(!fpbin)
    {
        return -1;
    }
    fptxtlf=fopen(nom2,"wt");
    if(!fptxtlf)
    {
        fclose(fptxtlf);
        return -2;
    }
    printf("\nListado ________\n\n");
    fread(&per,sizeof(t_persona),1,fpbin);
    while(!feof(fpbin))
    {
        fprintf(fptxtlf,"%08ld\t\t%02d%02d%04d\t\t%-*.*s%9.2f\n",
                per.dni,
                per.fnac.dia,
                per.fnac.mes,
                per.fnac.anio,
                sizeof(per.nomyap)-1,
                sizeof(per.nomyap)-1,
                per.nomyap,
                per.sueldo
                );
        fread(&per,sizeof(t_persona),1,fpbin);
    }
    fclose(fpbin);
    fclose(fptxtlf);
    return 0;
}

int leerymostrararchivodetexto(char *nom)
{
    char cad[100];
    FILE *pf=fopen(nom,"rt");
    if(!pf)
    {
        return -1;
    }
    while(fgets(cad,sizeof(cad),pf))
    {
        printf("%s\n",cad);
    }
    fclose(pf);
    return 1;
}

int creararchivotextolv(char *nom1,char *nom2)
{
    t_persona per;
    FILE *fpbin,
         *fptxtlf;

    fpbin=fopen(nom1,"rb");
    if(!fpbin)
    {
        return -1;
    }
    fptxtlf=fopen(nom2,"wt");
    if(!fptxtlf)
    {
        fclose(fptxtlf);
        return -2;
    }
    fread(&per,sizeof(t_persona),1,fpbin);
    while(!feof(fpbin))
    {
        fprintf(fptxtlf,"%ld;%d/%d/%d;%s;%.3f\n",
                per.dni,
                per.fnac.dia,
                per.fnac.mes,
                per.fnac.anio,
                per.nomyap,
                per.sueldo);
        fread(&per,sizeof(t_persona),1,fpbin);
    }
    fclose(fpbin);
    fclose(fptxtlf);
    return 0;
}

int buscarporDNIarchivodetexto(t_persona *per,char *nom2)
{
    char cadena[100];
    FILE *pj;
    long dni;
    int encontrado=0;

    pj=fopen(nom2,"rt");
    printf("ingrese el dni que desea buscar en el archivo:\n\n");
    scanf("%ld",&dni);
    fscanf(pj,"%ld",&per->dni);
    while(!encontrado&&fgets(cadena,sizeof(cadena),pj))
    {
        if(per->dni==dni)
        {
            encontrado=1;
            puts("registro encontrado\n");
            printf("%ld",per->dni);
            printf("%s\n",cadena);
            fclose(pj);
            return 1;
        }
        fscanf(pj,"%ld",&per->dni);


    }
    printf("El registro que usted busca no se encuentra\n");
    fclose(pj);
    return 0;
}
