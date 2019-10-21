#include <stdio.h>
#include "Inputs.h"

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int codigo; /**(autoincremental)*/
    char nombre[51];/**Validar**/
    char apellido[51];/**Validar*/
    char sexo; /**Validar */
    int estado;

}eActor;

void menuActores(eActor[],int len);
void harcodeoActores(eActor[],int len);
void inicializarActores(eActor[],int len);//PRINCIPAL
void ingresarActores(eActor[],int len);
int idAuto(eActor[],int len,int valMenor);
int idMayor(eActor[],int len,int valMenor);
int indiceLibreActores(eActor[],int len);
void modicficarActor(eActor[],int len);//PRINCIPAL
int buscarCodigoActores(eActor[],int len);
void mostrarUnActor(eActor[],int indice);
void MostrarActores(eActor[],int len);//PRINCIPAL
void borrarActor(eActor[],int len);

int validarCodigoDeActores(eActor[],int ta);
