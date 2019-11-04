#include "elenco.h"

void menuElencos(eElenco elencos[],int te,ePelicula peliculas[],int tp,eGenero generos[],int tg,eActor actores[],int ta,eNacionalidad nacionalidades[],int tn)
{
    int opcion;

    do{
            printf("Opciones:\n1- Generar Elenco.\n2- Listar Elenncos.\n3- Salir\nElija una Opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                ingreseElenco(elencos,te,peliculas,tp,generos,tg,actores,ta,nacionalidades,tn);
                break;
            case 2:
                //listarElencos(elencos,te,peliculas,tp,actores,ta);
                mostrarUnElenco(elencos,te,peliculas,tp,actores,ta);
                system("pause");
                break;
            case 3:
                printf("Salir\n");
                break;
            default:
                printf("No ingreso ninguna de las opciones\n");
            }
        system("cls");
    }while(opcion != 2);
}

//---------------------------------------------------------------------------------------------------------------------

void harcodeoElencos(eElenco elencos[],int len)
{
    int codigoDePeliculaAux[] = {1,2,3,1,5};
    int codigoDeActorAux[] = {2,3,1,4,5};
    int valorContratoAux[] = {2000,5000,10000,66000,200};
    int i;
    for(i=0;i<len;i++)
    {
        elencos[i].codigoDeActor = codigoDeActorAux[i];
        elencos[i].codigoDePelicula = codigoDePeliculaAux[i];
        elencos[i].valorContrato = valorContratoAux[i];
    }
}

//---------------------------------------------------------------------------------------------------------------------

void inicializarElencos(eElenco elencos[],int len)
 {
     int i;
     for(i=0;i<len;i++)
     {
         elencos[i].codigoDePelicula = 0;
         elencos[i].codigoDeActor = 0;
     }
 }

//---------------------------------------------------------------------------------------------------------------------

int indiceLibreElenco(eElenco elencos[],int len)
{
    int i;
    int index = -1;

    for(i=0;i<len;i++)
    {
        if(elencos[i].codigoDePelicula == 0 && elencos[i].codigoDeActor == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

//---------------------------------------------------------------------------------------------------------------------

void ingreseElenco(eElenco elencos[],int te,ePelicula peliculas[],int tp,eGenero generos[],int tg,eActor actores[],int ta,eNacionalidad nacionalidades[],int tn)
{
    eElenco auxElenco;
    int index;
    int codePelicula;
    int codeActor;
    int i;
    int j;

    index = indiceLibreElenco(elencos,te);

    codePelicula = validarCodigoDePelicula(peliculas,tp,generos,tg);
    codeActor = validarCodigoDeActores(actores,ta,nacionalidades,tn);

    //if(elencoExistente(elencos,te,codePelicula,codeActor)==1)
    //{
        for(i=0;i<te;i++)
        {
            if(codePelicula == peliculas[i].codigo)
            {
                auxElenco.codigoDePelicula = peliculas[i].codigo;

                    for(j=0;j<ta;j++)
                    {
                        if(codeActor == actores[j].codigo)
                        {
                            auxElenco.codigoDeActor = actores[j].codigo;

                            while(getInt(&auxElenco.valorContrato,"ingrese el valor del Contrato: ","Error,el contrato no puede pasar de 1.000.000",0,1000000)!=0);

                            if(confirmar("Confirmar:","Canselar:")==0)
                            {
                                elencos[index].codigoDePelicula = auxElenco.codigoDePelicula;
                                elencos[index].codigoDeActor = auxElenco.codigoDeActor;
                                elencos[index].valorContrato = auxElenco.valorContrato;

                            }else{
                                printf("La operecion fue cancelada.\n");
                            }
                        }
                    }
            }
        }

    //}else{
        //printf("\nEl elenco ya existe\n");
    //}
}

//---------------------------------------------------------------------------------------------------------------------

void listarElencos(eElenco elencos[],int te,ePelicula peliculas[],int tp,eActor actores[],int ta)
{
    int i;
    int j;
    int k;

    printf(" Peliculas:\t\t\t\tActores:\t\tValor del Contratos:\n\n");

    for(i=0;i<te;i++)
    {
        for(j=0;j<tp;j++)
        {
            if(elencos[i].codigoDePelicula == peliculas[j].codigo)
            {
                printf(" %s",peliculas[j].descripcion);

                for(k=0;k<ta;k++)
                {
                    if(elencos[i].codigoDeActor == actores[k].codigo)
                    {
                        printf("\t\t%22s",actores[k].apellido);
                        printf("\t\t%15d\n",elencos[i].valorContrato);
                    }
                }
            }
        }
    }

}

//---------------------------------------------------------------------------------------------------------------------

void mostrarUnElenco(eElenco elencos[],int te,ePelicula peliculas[],int tp,eActor actores[],int ta)
{
    int i;
    int j;
    int k;
    int idPelicula = 0;

    printf(" Peliculas:\t\t\t\t\tActores:\t\tValor del Contratos:\n\n");

    while(idPelicula != idMayorPeliculas(peliculas,tp,1))
    {
        for(i=0;i<te;i++)
        {
            for(j=0;j<tp;j++)
            {
                if(elencos[i].codigoDePelicula == peliculas[j].codigo && stricmp(peliculas[j].descripcion,peliculas[idPelicula].descripcion)==0)
                {
                    for(k=0;k<ta;k++)
                    {
                        if(elencos[i].codigoDeActor == actores[k].codigo && actores[k].estado != LIBRE)
                        {
                            printf(" %-20s",peliculas[idPelicula].descripcion);
                            printf("\t\t%22s",actores[k].apellido);
                            printf("\t\t%22d\n",elencos[i].valorContrato);
                        }
                    }
                }
            }

        }
    printf("\n");

        idPelicula++;
    }

}

int elencoExistente(eElenco elencos[],int te,int codePelicula,int codeActor)
{
    int i;
    int retorno;

    for(i=0;i<te;i++)
    {
        if(elencos[i].codigoDePelicula == codePelicula && elencos[i].codigoDeActor==codeActor)
        {
            retorno = 1;
        }else{
            retorno = 0;
        }
    }

    return retorno;

}


