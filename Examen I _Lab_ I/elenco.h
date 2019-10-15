#include "actores.h"
#include "peliculas.h"

typedef struct
{
    int codigoDePelicula; /**Validar*/
    int codigoDeActor; /**Validar*/
    int valorContrato;

}eElenco;

void menuElencos(eElenco[],int te,ePelicula[],int tp,eGenero[],int tg,eActor[],int ta);
void harcodeoElencos(eElenco[],int len);
void inicializarElencos(eElenco[],int len);
int indiceLibreElenco(eElenco[],int len);

void ingreseElenco(eElenco[],int te,ePelicula[],int tp,eGenero[],int tg,eActor[],int ta);
void listarElencos(eElenco[],int te,ePelicula[],int tp,eActor[],int ta);
void mostrarUnElenco(eElenco[],int te,ePelicula[],int tp,eActor[],int ta);
