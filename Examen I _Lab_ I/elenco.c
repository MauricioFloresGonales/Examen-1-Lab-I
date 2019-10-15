#include "elenco.h"

void menuElencos(eElenco elencos[],int te,ePelicula peliculas[],int tp,eGenero generos[],int tg,eActor actores[],int ta)
{
    int opcion;

    do{
            printf("Opciones:\n1- Generar Elenco.\n2- Listar Elenncos.\n3- Salir\nElija una Opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                ingreseElenco(elencos,te,peliculas,tp,generos,tg,actores,ta);
                break;
            case 2:
                //listarElencos(elencos,te,peliculas,tp,actores,ta);
                mostrarUnElenco(elencos,te,peliculas,tp,actores,ta);
                break;
            default:
                printf("salir");

            }

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

void ingreseElenco(eElenco elencos[],int te,ePelicula peliculas[],int tp,eGenero generos[],int tg,eActor actores[],int ta)
{
    int index;
    int codePelicula;
    int codeActor;
    int i;
    int j;

    index = indiceLibreElenco(elencos,te);

    codePelicula = validarCodigoDePelicula(peliculas,tp,generos,tg);


    for(i=0;i<te;i++)
    {
        if(codePelicula == peliculas[i].codigo)
        {
            elencos[index].codigoDePelicula = peliculas[i].codigo;

            codeActor = validarCodiigoDeActores(actores,ta);

            for(j=0;j<ta;j++)
            {
                if(codeActor == actores[j].codigo)
                {
                    elencos[index].codigoDeActor = actores[j].codigo;

                    while(getInt(&elencos[index].valorContrato,"ingrese el valor del Contrato: ","Error,el contrato no puede pasar de 1.000.000",0,1000000)!=0);
                }
            }
        }
    }
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

    printf(" Peliculas:\t\t\t\tActores:\t\tValor del Contratos:\n\n");

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
                        if(elencos[i].codigoDeActor == actores[k].codigo)
                        {
                            printf(" %s\t\t%22s\t\t%15d\n",peliculas[idPelicula].descripcion,actores[k].apellido,elencos[i].valorContrato);
                        }
                    }
                }
            }

        }

        idPelicula++;
    }

}



