#include "actores.h"
#include "peliculas.h"

typedef struct
{
    int codigoDePelicula; /**Validar*/
    int codigoDeActor; /**Validar*/
    int valorContrato;

}eElenco;

void menuElencos(eElenco[],int te,ePelicula[],int tp,eGenero[],int tg,eActor[],int ta,eNacionalidad nacionalidades[],int tn);
void harcodeoElencos(eElenco[],int len);
void inicializarElencos(eElenco[],int len);
int indiceLibreElenco(eElenco[],int len);
void ingreseElenco(eElenco[],int te,ePelicula[],int tp,eGenero[],int tg,eActor[],int ta,eNacionalidad nacionalidades[],int tn);

void listarElencos(eElenco[],int te,ePelicula[],int tp,eActor[],int ta);
void mostrarUnElenco(eElenco[],int te,ePelicula[],int tp,eActor[],int ta);

int elencoExistente(eElenco[],int te,int codePelicula,int codeActor);

void menuInformes(eElenco[],int te,ePelicula[],int tp,eGenero[], int tg,eActor[],int ta,eNacionalidad[],int tn);
int peliculaConActorArg(eElenco[],int te,eActor[],int ta,ePelicula[],int tp);
int peliculaConTalActor(eElenco[],int te,eActor[],int ta,ePelicula[],int tp,char nomActor[]);
int cuantoRecaudoTalActorConRomanticas(eElenco[],int te,eActor[],int ta,ePelicula[],int tp,char nomActor[]);
void actoresSinTrabajo(eElenco [],int te,eActor [],int ta,eNacionalidad [],int tn);
