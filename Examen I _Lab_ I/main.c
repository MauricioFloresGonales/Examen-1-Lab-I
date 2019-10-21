#include <stdio.h>
#include <stdlib.h>

#include "elenco.h"

#define TP 5
#define TG 4
#define TA 8
#define TE 8

int main()
{
    ePelicula peliculas[TP];
    eGenero generos[TG];
    eActor actores[TA];
    eElenco elencos[TE];

    int opcion;

    inicializarActores(actores,TA);
    inicializarPeliculas(peliculas,TP);
    inicializarElencos(elencos,TE);
    harcodeoActores(actores,5);
    harcodeoGeneros(generos,TG);
    harcodeoPeliculas(peliculas,5);
    harcodeoElencos(elencos,5);

    do{
        printf("1- Gestion de Actores:\n");
        printf("2- Gestion de Elencos:\n");
        printf("3- salir:\n");

        getInt(&opcion,"Elija una opcion:\n","Solo puede ingresar los numeros del menu",1,3);

        switch(opcion)
        {
        case 1:
            system("cls");
            menuActores(actores,TA);
            break;
        case 2:
            system("cls");
            menuElencos(elencos,TE,peliculas,TP,generos,TG,actores,TA);
            break;
        case 3:
            printf("SALIR\n");
        default:
            printf("Vuelva a intentar\n");
        }

    system("pause");
    system("cls");

    }while(opcion != 3);


    return 0;
}
