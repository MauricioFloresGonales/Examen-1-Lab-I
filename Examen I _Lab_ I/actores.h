#include <stdio.h>
#include "Inputs.h"

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idNacinalidad;
    char descripcionPais[51];

}eNacionalidad;

typedef struct
{
    int codigo; /**(autoincremental)*/
    char nombre[51];/**Validar**/
    char apellido[51];/**Validar*/
    char sexo; /**Validar */
    int estado;
    int idNacinalidad;

}eActor;

void menuActores(eActor[],int len,eNacionalidad[],int tn);
void harcodeoActores(eActor[],int len);
void inicializarActores(eActor[],int len);//PRINCIPAL
void ingresarActores(eActor[],int len);
int idAuto(eActor[],int len,int valMenor);
int idMayor(eActor[],int len,int valMenor);
int indiceLibreActores(eActor[],int len);
void modicficarActor(eActor[],int len,eNacionalidad nacionalidades[],int tn);//PRINCIPAL
int buscarCodigoActores(eActor[],int len,eNacionalidad[],int tn);
void mostrarUnActor(eActor[],int indice,eNacionalidad[],int tn);
void MostrarActores(eActor[],int len,eNacionalidad[],int tn);//PRINCIPAL
void borrarActor(eActor[],int len,eNacionalidad nacionalidades[],int tn);

int validarCodigoDeActores(eActor[],int ta,eNacionalidad[],int tn);

void harcodeoNacionalidades(eNacionalidad[],int len);
