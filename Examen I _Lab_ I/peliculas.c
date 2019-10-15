#include <stdio.h>
#include <string.h>
#include "Inputs.h"

#include "peliculas.h"

void harcodeoGeneros(eGenero generos[],int len)
{
    int id[]={1,2,3,4};
    char descripcion[][51]={"Accion","Terror", "Romance", "Suspenso"};
    int i;

    for(i=0;i<len;i++)
    {
        generos[i].id = id[i];
        strcpy(generos[i].descripcion,descripcion[i]);
    }
}

//---------------------------------------------------------------------------------------------------------------------------------

void harcodeoPeliculas(ePelicula peliculas[],int len)
{
    char descripcion[][51]={"destino final","Bajo la misma estrella","depredador","los juegos del hambre","El juego del miedo","IT"};
    int duracion[] = {1,2,1,2,2,1};
    int idGenero[] = {4,3,1,1,4,2};
    int i;

    for(i=0;i<len;i++)
    {
        peliculas[i].codigo = idAutoPeliculas(peliculas,len,1);
        strcpy(peliculas[i].descripcion,descripcion[i]);
        peliculas[i].duracion = duracion[i];
        peliculas[i].idGenero = idGenero[i];
    }
}

//---------------------------------------------------------------------------------------------------------------------------------

void inicializarPeliculas(ePelicula peliculas[],int len)
 {
     int i;
     for(i=0;i<len;i++)
     {
         peliculas[i].codigo = 0;
     }
 }

 //---------------------------------------------------------------------------------------------------------------------------------

void ingresarPelicula(ePelicula peliculas[],int len)
{
    int indice;

      indice = indiceLibrePelicualas(peliculas,len);

      printf("\nindice: %d\n",indice);

        if(indice != -1)
        {
            peliculas[indice].codigo = idAutoPeliculas(peliculas,len,1);
            while(getString(peliculas[indice].descripcion,"Ingrese el Nombre: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
            while(getInt(&peliculas[indice].duracion,"Ingrese la duracion: ","El limite de horas se paso",1,5)!=0);
            while(getInt(&peliculas[indice].idGenero,"1- Accion\n2- Terror\n3- Romanse\n4- Suspenso\nIngrese un codigo: ","No ingreso ningun codigo valido",1,4)!=0);
        }
}

//---------------------------------------------------------------------------------------------------------------------------------

int indiceLibrePelicualas(ePelicula peliculas[],int len)
{
    int i;
    int index = -1;

    for(i=0;i<len;i++)
    {
        if(peliculas[i].codigo != 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

//---------------------------------------------------------------------------------------------------------------------------------

int buscarCodigoPeliculas(ePelicula peliculas[],int len,eGenero generos[],int tg)
{
    int legAux;
    int i;
    int loEncontro = 0;

    do{
        printf("igrese el codigo de la pelicula que quiere encontrar: ");
        scanf("%d",&legAux);

        for(i=0;i<len;i++)
            {
                if(peliculas[i].codigo == legAux)
                {
                    mostrarUnaPelicula(peliculas,i,generos,tg);
                    loEncontro = 1;

                    break;
                }//if
            }//for

     }while(loEncontro != 1);

    return i;
}

//---------------------------------------------------------------------------------------------------------------------------------

int idAutoPeliculas(ePelicula peliculas[],int len,int valMenor)
{
    int indexAnterior;
    int idFinal;

    indexAnterior = idMayorPeliculas(peliculas,len,valMenor);

    idFinal = indexAnterior +1;

    return idFinal;

}

int idMayorPeliculas(ePelicula peliculas[],int len,int valMenor)
{
    int i;
    int mayor = valMenor-1;

    for(i=0;i<len;i++)
    {
        if(mayor<peliculas[i].codigo)
        {
            mayor = peliculas[i].codigo;
        }
    }
    return mayor;
}

//---------------------------------------------------------------------------------------------------------------------------------

void mostrarUnaPelicula(ePelicula peliculas[],int index,eGenero generos[],int tg)
{
    int i;

    printf("\n%d",peliculas[index].codigo);
    printf("\t\t%-5s",peliculas[index].descripcion);
    printf("\t\t%10d hs",peliculas[index].duracion);

    for(i=0;i<tg;i++)
    {
        if(peliculas[index].idGenero == generos[i].id)
        {
            printf("\t\t%15s\n",generos[i].descripcion);
        }
    }

}

//---------------------------------------------------------------------------------------------------------------------------------

void MostrarPeliculas(ePelicula peliculas[],int len,eGenero generos[],int tg)
{
    int flag = 0;
    int i;

    printf("\nCodigo\t\tPelicula\t\t\tDuracion\t\tGenero\n");

    for(i=0;i<len;i++)
    {
        flag = 1;
        mostrarUnaPelicula(peliculas,i,generos,tg);
    }

    if(flag == 0)
    {
        printf("No hay Peliculas para mostrar\n");
    }
}

//---------------------------------------------------------------------------------------------------------------------------------

int validarCodigoDePelicula(ePelicula peliculas[],int tp,eGenero generos[],int tg)
{
    int i;
    int flag = -1;
    int numero;

    MostrarPeliculas(peliculas,tp,generos,tg);

    while( flag != 0)
    {
        printf("ingrese el codigo de una pelicula: ");
        scanf("%d",&numero);

        for(i=0;i<tp;i++)
        {
            if(numero == peliculas[i].codigo)
            {
                flag=0;
                break;
            }
        }
    }

    return numero;
}
