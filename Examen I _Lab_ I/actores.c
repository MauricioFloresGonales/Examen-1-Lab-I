#include "actores.h"

void menuActores(eActor actores[],int len)
{
    int opcion;

    do{
            printf("Opciones:\n1- Alta\n2- Modificar\n3- Baja\n4- Listar\n5- Salir\nElija una Opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                ingresarActores(actores,len);
                break;
            case 2:
                MostrarActores(actores,len);
                modicficarActor(actores,len);
                break;
            case 3:
                MostrarActores(actores,len);
                 borrarActor(actores,len);
                break;
            case 4:
                MostrarActores(actores,len);
                break;
            default:
                printf("salir");

            }

    }while(opcion != 4);
}

//---------------------------------------------------------------------------------------------------------------------------------

void harcodeoActores(eActor actores[],int len)
{
    char nombre[][51]={"ana","juan","pepe","rosa","carlos"};
    char apellido[][51]={"catunta","gonzalez","mesa","sanchez"};
    char sexo[]={'m','h','h','m','h'};
    int estado[]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};
    int i;

    for(i=0;i<len;i++)
    {
        actores[i].codigo = idAuto(actores,len,1);
        strcpy(actores[i].nombre,nombre[i]);
        strcpy(actores[i].apellido,apellido[i]);
        actores[i].sexo = sexo[i];
        actores[i].estado = estado[i];
    }
}

//---------------------------------------------------------------------------------------------------------------------------------

void inicializarActores(eActor actores[],int len)
 {
     int i;
     for(i=0;i<len;i++)
     {
         actores[i].codigo = 0;
         actores[i].estado = LIBRE;
     }
 }

 //---------------------------------------------------------------------------------------------------------------------------------

void ingresarActores(eActor actores[],int len)
{
    int indice;

      indice = indiceLibreActores(actores,len);

      printf("\nindice: %d\n",indice);

        if(indice != -1)
        {
            actores[indice].codigo = idAuto(actores,len,1);
            while(getString(actores[indice].nombre,"Ingrese el Nombre: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
            while(getString(actores[indice].apellido,"Ingrese el Apellido: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
            while(getOneChar(&actores[indice].sexo,"ingrese\n[M] = Masculino\n[F] = Femenino\n","No ingreso ninguna de las dos opciones",'h','m')!=0);
            actores[indice].estado = OCUPADO;
        }
}

//---------------------------------------------------------------------------------------------------------------------------------

int idAuto(eActor actores[],int len,int valMenor)
{
    int indexAnterior;
    int idFinal;

    indexAnterior = idMayor(actores,len,valMenor);

    idFinal = indexAnterior +1;

    return idFinal;

}

int idMayor(eActor actores[],int len,int valMenor)
{
    int i;
    int mayor = valMenor-1;

    for(i=0;i<len;i++)
    {
        if(mayor<actores[i].codigo)
        {
            mayor = actores[i].codigo;
        }
    }
    return mayor;
}

//---------------------------------------------------------------------------------------------------------------------------------

int indiceLibreActores(eActor actores[],int len)
{
    int i;
    int index = -1;

    for(i=0;i<len;i++)
    {
        if(actores[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

//---------------------------------------------------------------------------------------------------------------------------------

void modicficarActor(eActor actores[],int len)
{
    int index;
    int opcion;

    index = buscarCodigoActores(actores,len);

    do{
            printf("Modificar:\n1-Nombre\n2-Apellido\n3-Sexo\n4-Salir\nOpcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                while(getString(actores[index].nombre,"Ingrese el Nombre: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
                break;
            case 2:
                while(getString(actores[index].apellido,"Ingrese el Apellido: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
                break;
            case 3:
                while(getOneChar(&actores[index].sexo,"ingrese\n[M] = Masculino\n[F] = Femenino\n","No ingreso ninguna de las dos opciones",'m','f')!=0);
                break;
            default:
                printf("salir");

            }

    }while(opcion != 4);
}

//---------------------------------------------------------------------------------------------------------------------------------

int buscarCodigoActores(eActor actores[],int len)
{
    int legAux;
    int i;
    int loEncontro = 0;

    do{
        printf("igrese el codigo que quiere encontrar: ");
        scanf("%d",&legAux);

        for(i=0;i<len;i++)
            {
                if(actores[i].codigo == legAux && actores[i].estado == OCUPADO)
                {
                    mostrarUnActor(actores,i);
                    loEncontro = 1;

                    break;
                }//if
            }//for

     }while(loEncontro != 1);

    return i;
}

//---------------------------------------------------------------------------------------------------------------------------------

void mostrarUnActor(eActor actores[],int indice)
{
    if(actores[indice].estado == OCUPADO)
    {
        printf("\n%d",actores[indice].codigo);
        printf("\t\t%10s",actores[indice].apellido);
        printf("\t\t%-10s",actores[indice].nombre);
        printf("\t\t%c\n",actores[indice].sexo);
    }

}

//---------------------------------------------------------------------------------------------------------------------------------

void MostrarActores(eActor actores[],int len)
{
    int flag = 0;
    int i;
    printf("\nCodigo\t\tApellido\t\tNombre\t\tSexo\n");
    for(i=0;i<len;i++)
    {
        if(actores[i].estado == OCUPADO)
        {
            flag = 1;
            mostrarUnActor(actores,i);
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos para mostrar\n");
    }
}

//---------------------------------------------------------------------------------------------------------------------------------

void borrarActor(eActor actores[],int len)
{
    int index;

    index = buscarCodigoActores(actores,len);

    actores[index].estado = LIBRE;
}
