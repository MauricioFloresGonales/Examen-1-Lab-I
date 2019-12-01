#include <stdio.h>
#include <stdlib.h>

#include "elenco.h"

#define TP 7
#define TG 4
#define TA 8
#define TE 8

int main()
{
    ePelicula peliculas[TP];
    eGenero generos[TG];
    eActor actores[TA];
    eElenco elencos[TE];

    eNacionalidad nacionalidades[5];

    int opcion;

    inicializarActores(actores,TA);
    inicializarPeliculas(peliculas,TP);
    inicializarElencos(elencos,TE);
    harcodeoActores(actores,6);
    harcodeoGeneros(generos,TG);
    harcodeoPeliculas(peliculas,TP);
    harcodeoElencos(elencos,5);

    harcodeoNacionalidades(nacionalidades,5);

    do{
        printf("1- Gestion de Actores:\n");
        printf("2- Gestion de Elencos:\n");
        printf("3- Informes:\n");
        printf("4- salir:\n");

        while(getInt(&opcion,"Elija una opcion:\n","Solo puede ingresar los numeros del menu",1,4)!=0);

        switch(opcion)
        {
        case 1:
            system("cls");
            menuActores(actores,TA,nacionalidades,5);
            break;
        case 2:
            system("cls");
            menuElencos(elencos,TE,peliculas,TP,generos,TG,actores,TA,nacionalidades,5);
            break;
        case 3:
            system("cls");
            menuInformes(elencos,TE,peliculas,TP,generos,TG,actores,TA,nacionalidades,5);
            break;
        default:
            printf("ADIOS.\n");
        }

    system("pause");
    system("cls");

    }while(opcion != 4);


    return 0;
}
