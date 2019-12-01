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

//---------------------------------------------------------------------------------------------------------------------------------

void menuInformes(eElenco elencos[],int te,ePelicula peliculas[],int tp,eGenero generos[], int tg,eActor actores[],int ta,eNacionalidad nacionalidad[],int tn)
{
    int opcion;
    char nombreAux[51];
    do{
        printf("\n1.Inf.Pelicuas de Terror del 2002\n");
        printf("2.Inf.Peliculas con actor Argentino\n");
        printf("3.Inf.Encontrar Peliculas de ...\n");
        printf("4.Inf.Cuanto recaudo ...\n");
        printf("5.Inf.Actores en ninguna Pelicula\n");
        printf("6.Salir\n");

        while(getInt(&opcion,"Elija una opcion: ","Solo puede ingresar los numeros del menu",1,6)!=0);

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("1.Inf.Pelicuas de Terror del 2002:\n");
            if(validarPeliculasDeTerror( peliculas,tp,generos,tg)!=0)
            {
                printf("No se encontro ninguna pelicula de terror del 2002\n");
            }
            break;
        case 2:
            system("cls");
            printf("2.Inf.Peliculas con actor Argentino:\n");
            if(peliculaConActorArg(elencos,te,actores,ta,peliculas,tp)!=0)
            {
                printf("No se encontro ninguna pelicula con un actor argentino\n");
            }
            break;
        case 3:
            system("cls");
            printf("3.Inf.Encontrar Peliculas de ...\n");
            while(getStringWithNums(nombreAux,"ingrese el nombre de un actor: ","El nombre es muy largo\n",0,50)!=0);
            if(peliculaConTalActor(elencos,te,actores,ta,peliculas,tp,nombreAux)!=0)
            {
                printf("No se encontro ninguna pelicula de %s.",nombreAux);
            }

            break;
        case 4:
            system("cls");
            printf("4.Inf.Cuanto recaudo en Peliculas Romanticas...\n");
            MostrarActores(actores,ta,nacionalidad,tn);
            while(getStringWithNums(nombreAux,"ingrese el nombre de un actor: ","El nombre es muy largo\n",0,50)!=0);
            if(cuantoRecaudoTalActorConRomanticas(elencos,te,actores,ta,peliculas,tp,nombreAux)!=0)
            {
                printf("No se encontro ninguna pelicula romantica con %s.",nombreAux);
            }
            break;
        case 5:
            system("cls");
            printf("5.Inf.Actores en ninguna Pelicula\n");
            printf("\nCodigo\t\t   Apellido\t\t Nombre\t\t      Sexo\t\tNacionalidad\n");
            actoresSinTrabajo(elencos,te,actores,ta,nacionalidad,tn);
            break;
        default:
            printf("Usted salio del menu de Informes\n");
        }
    }while(opcion!=6);
}

int peliculaConActorArg(eElenco elencos[],int te,eActor actores[],int ta,ePelicula peliculas[],int tp)
{
    int retorno = -1;
    int i;
    int j;
    int k;

    for(i=0;i<te;i++)
    {
        for(j=0;j<ta;j++)
        {
            if(elencos[i].codigoDeActor == actores[j].codigo)
            {
                if(actores[j].idNacinalidad == 1)
                {
                    for(k=0;k<tp;k++)
                    {
                        if(elencos[i].codigoDePelicula == peliculas[k].codigo)
                        {
                            printf("Actor: %s\tPelicula: %s\n",actores[j].nombre,peliculas[k].descripcion);
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int peliculaConTalActor(eElenco elencos[],int te,eActor actores[],int ta,ePelicula peliculas[],int tp,char nomActor[])
{
    int retorno = -1;
    int i;
    int j;
    int k;

    for(i=0;i<te;i++)
    {
        for(j=0;j<ta;j++)
        {
            if(elencos[i].codigoDeActor == actores[j].codigo)
            {
                if(stricmp(actores[j].nombre,nomActor)==0)
                {
                    for(k=0;k<tp;k++)
                    {
                        if(elencos[i].codigoDePelicula == peliculas[k].codigo)
                        {
                            printf("Actor: %s\tPelicula: %s\n",actores[j].nombre,peliculas[k].descripcion);
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int cuantoRecaudoTalActorConRomanticas(eElenco elencos[],int te,eActor actores[],int ta,ePelicula peliculas[],int tp,char nomActor[])
{
    int retorno = -1;
    int i;
    int j;
    int k;
    int recaudado = 0;

    for(i=0;i<te;i++)
    {
        for(j=0;j<ta;j++)
        {
            if(elencos[i].codigoDeActor == actores[j].codigo)
            {
                if(stricmp(actores[j].nombre,nomActor)==0)
                {
                    for(k=0;k<tp;k++)
                    {
                        if(elencos[i].codigoDePelicula == peliculas[k].codigo)
                        {
                            if(peliculas[k].idGenero == 3)
                            {
                                printf("Actor: %s\tPelicula: %s\tContrato: %d\n",actores[j].nombre,peliculas[k].descripcion,elencos[i].valorContrato);
                                recaudado = recaudado+elencos[i].valorContrato;
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    if(retorno==0)
    {
        printf("Lo que recaudo el %s fue en total: %d\n",nomActor,recaudado);
    }

    return retorno;
}

void actoresSinTrabajo(eElenco elencos[],int te,eActor actores[],int ta,eNacionalidad nacionalidad[],int tn)
{
    int validar = 0;
    int i;
    int j;
    int k;

    for(i=0;i<te;i++)
    {
        for(j=0;j<ta;j++)
        {
            if(actores[i].codigo == elencos[j].codigoDeActor)
            {
                validar=0;
                break;
            }
            else
            {
                validar = -1;
            }
        }
        if(validar!=0)
        {
            mostrarUnActor(actores,i,nacionalidad,tn);
        }
    }
}


