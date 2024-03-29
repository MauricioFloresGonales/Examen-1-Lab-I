#include "actores.h"

void menuActores(eActor actores[],int len,eNacionalidad nacionalidades[],int tn)
{
    int opcion;

    do{
            getInt(&opcion,"Opciones:\n1- Alta\n2- Modificar\n3- Baja\n4- Listar\n5- Salir\nElija una Opcion: ","Solo puede ingresar los numeros del menu",1,5);
            switch(opcion)
            {
            case 1:
                ingresarActores(actores,len);
                break;
            case 2:
                MostrarActores(actores,len,nacionalidades,tn);
                modicficarActor(actores,len,nacionalidades,tn);
                break;
            case 3:
                MostrarActores(actores,len,nacionalidades,tn);
                borrarActor(actores,len,nacionalidades,tn);
                break;
            case 4:
                MostrarActores(actores,len,nacionalidades,tn);
                system("pause");
                break;
            case 5:
                printf("Salir\n");
                break;
            default:
                printf("Vuelva a intentar\n");

            }
        system("cls");

    }while(opcion != 5);
}

//---------------------------------------------------------------------------------------------------------------------------------

void harcodeoActores(eActor this[],int len)
{
    char nombre[][51]={"ana","juan","pepe","rosa","carlos","jose"};
    char apellido[][51]={"catunta","gonzalez","mesa","sanchez","rodriguez","flores"};
    char sexo[]={'f','m','m','f','m','m'};
    int estado[]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};
    int idNacionalidad[] = {1,5,1,4,2,3};
    char calle[][51]={"piedras","tacuari","av.caseros","av.independencia","av.cordoba","iliarte"};
    int altura[]={500,123,547,888,1002,1147};
    char localidad[][51]={"contitucion","belgrano","congreso","la boca","avellaneda","lanus"};
    int cantPremios[]={1,2,0,3,1,5};
    int diaNacimiento[]={1,25,8,6,23,14};
    int mesNacimiento[]={1,8,4,3,2,4};
    int anioNacimiento[]={1999,1952,1988,1999,2001,1992};
    int i;

    for(i=0;i<len;i++)
    {
        this[i].codigo = idAuto(this,len,1);
        strcpy(this[i].nombre,nombre[i]);
        strcpy(this[i].apellido,apellido[i]);
        this[i].sexo = sexo[i];
        this[i].estado = estado[i];
        this[i].idNacinalidad = idNacionalidad[i];
        strcpy(this[i].direccion.calle,calle[i]);
        this[i].direccion.altura = altura[i];
        strcpy(this[i].direccion.localidad,localidad[i]);
        this[i].cantPremios = cantPremios[i];
        this[i].fechaNacimiento.dia = diaNacimiento[i];
        this[i].fechaNacimiento.mes = mesNacimiento[i];
        this[i].fechaNacimiento.anio = anioNacimiento[i];
    }
}

//---------------------------------------------------------------------------------------------------------------------------------

void inicializarActores(eActor this[],int len)
 {
     int i;
     for(i=0;i<len;i++)
     {
         this[i].codigo = 0;
         this[i].estado = LIBRE;
     }
 }

 //---------------------------------------------------------------------------------------------------------------------------------

void ingresarActores(eActor this[],int len)
{
    int indice;

      indice = indiceLibreActores(this,len);

        if(indice != -1)
        {
            this[indice].codigo = idAuto(this,len,1);
            while(getStringWithNums(this[indice].nombre,"Ingrese el Nombre: ","El limite de caracteres fue pasado",0,51)!=0);
            while(getStringWithNums(this[indice].apellido,"Ingrese el Apellido: ","El limite de caracteres fue pasado",0,51)!=0);
            while(getOneChar(&this[indice].sexo,"ingrese\n[M] = Masculino\n[F] = Femenino\n","No ingreso ninguna de las dos opciones",'m','f')!=0);
            while(getInt(&this[indice].idNacinalidad,"Ingrese la Nacionalidad:\n[1] Argentina\n[2] Chile\n[3]Bolivia\n[4]Estadoos Unidos\n[5]Inglaterrea\nopcion: ","Error,No ingreso niguna de las opciones",1,5)!=0);
            while(getStringWithNums(this[indice].direccion.calle,"ingrese la calle del actor: ","error,nombre muy largo",1,51)!=0);
            while(getIntIlimit(&this[indice].direccion.altura,"ingrese la altura de la calle: ","error,solo puede ingresar numros",1)!=0);
            while(getStringWithNums(this[indice].direccion.localidad,"ingrese la localidad del actor: ","error,nombre muy largo",1,51)!=0);
            while(getIntIlimit(&this[indice].cantPremios,"ingrese la cantPremios del actor: ","error,solo puede ingresar numros",0)!=0);
            while(getInt(&this[indice].fechaNacimiento.dia,"ingrese el dia de nacimiento","error,maximo num es 31",1,31)!=0);
            while(getInt(&this[indice].fechaNacimiento.mes,"ingrese el mes de nacimiento","error,maximo num es 12",1,12)!=0);
            while(getInt(&this[indice].fechaNacimiento.anio,"ingrese el anio de nacimiento","error,maximo num es invalido",1,2019)!=0);
            this[indice].estado = OCUPADO;
        }
}

//---------------------------------------------------------------------------------------------------------------------------------

int idAuto(eActor this[],int len,int valMenor)
{
    int indexAnterior;
    int idFinal;

    indexAnterior = idMayor(this,len,valMenor);

    idFinal = indexAnterior +1;

    return idFinal;

}

int idMayor(eActor this[],int len,int valMenor)
{
    int i;
    int mayor = valMenor-1;

    for(i=0;i<len;i++)
    {
        if(mayor<this[i].codigo)
        {
            mayor = this[i].codigo;
        }
    }
    return mayor;
}

//---------------------------------------------------------------------------------------------------------------------------------

int indiceLibreActores(eActor this[],int len)
{
    int i;
    int index = -1;

    for(i=0;i<len;i++)
    {
        if(this[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

//---------------------------------------------------------------------------------------------------------------------------------

void modicficarActor(eActor actores[],int len,eNacionalidad nacionalidades[],int tn)
{
    eActor auxActor;
    int index;
    int opcion;

    index = buscarCodigoActores(actores,len,nacionalidades,tn);

    do{
            getInt(&opcion,"Modificar:\n1-Nombre\n2-Apellido\n3-Sexo\n4-Nacionalidad\n5-Salir\nOpcion: ","Solo puede ingresar los numeros que aparecen en el menu",1,4);
            switch(opcion)
            {
            case 1:
                while(getString(auxActor.nombre,"Ingrese el Nombre: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    strcpy(actores[index].nombre,auxActor.nombre);
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                break;
            case 2:
                while(getString(auxActor.apellido,"Ingrese el Apellido: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    strcpy(actores[index].apellido,auxActor.apellido);
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                break;
            case 3:
                while(getOneChar(&auxActor.sexo,"ingrese\n[M] = Masculino\n[F] = Femenino\n","No ingreso ninguna de las dos opciones",'m','f')!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    actores[index].sexo = auxActor.sexo;
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                break;
            case 4:
                while(getInt(&auxActor.idNacinalidad,"Ingrese la Nacionalidad:\n[1] Argentina\n[2] Chile\n[3]Bolivia\n[4]Estadoos Unidos\n[5]Inglaterrea\nopcion: ","Error,No ingreso niguna de las opciones",1,5)!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    actores[index].idNacinalidad = auxActor.idNacinalidad;
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                break;
            default:
                printf("salir");
            }

    }while(opcion != 5);
}

//---------------------------------------------------------------------------------------------------------------------------------

int buscarCodigoActores(eActor actores[],int len,eNacionalidad nacionalidades[],int tn)
{
    int legAux;
    int i;
    int loEncontro = 0;

    do{
        getInt(&legAux,"igrese el codigo del Actor que quiere encontrar: ","Asegurese de haber ingresado un codigo valido",1,len+1);

        for(i=0;i<len;i++)
            {
                if(actores[i].codigo == legAux && actores[i].estado == OCUPADO)
                {
                    mostrarUnActor(actores,i,nacionalidades,tn);
                    loEncontro = 1;

                    break;
                }//IF
            }//for
        if(loEncontro == 0)
        {
            printf("No se encontro\n");
        }

     }while(loEncontro != 1);

    return i;
}

//---------------------------------------------------------------------------------------------------------------------------------

void mostrarUnActor(eActor actores[],int indice,eNacionalidad nacionalidades[],int tn)
{
    int i;

    if(actores[indice].estado == OCUPADO)
    {
        printf("\n%d",actores[indice].codigo);
        printf("\t%10s",actores[indice].apellido);
        printf("\t%-7s",actores[indice].nombre);
        printf("\t%-5c",actores[indice].sexo);

        for(i=0;i<tn;i++)
        {
            if(actores[indice].idNacinalidad == nacionalidades[i].idNacinalidad)
            {
                printf("\t%-10s",nacionalidades[i].descripcionPais);
            }
        }
        printf("\t%10s",actores[indice].direccion.localidad);
        printf("\t%d\n",actores[indice].fechaNacimiento.anio);
    }

}

//---------------------------------------------------------------------------------------------------------------------------------

void MostrarActores(eActor actores[],int len,eNacionalidad nacionalidades[],int tn)
{
    int flag = 0;
    int i;
    printf("\nCodigo\t  Apellido\tNombre\tSexo\tNacionalidad\tlocalidad\tanioNaci\n");
    for(i=0;i<len;i++)
    {
        if(actores[i].estado == OCUPADO)
        {
            flag = 1;
            mostrarUnActor(actores,i,nacionalidades,tn);
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos para mostrar\n");
    }
}

//---------------------------------------------------------------------------------------------------------------------------------

void borrarActor(eActor actores[],int len,eNacionalidad nacionalidades[],int tn)
{
    eActor auxActores;
    int index;

    index = buscarCodigoActores(actores,len,nacionalidades,tn);

    auxActores.estado = LIBRE;

    if(confirmar("Confirmar:","Cancelar")==0)
    {
        actores[index].estado = auxActores.estado;
    }else{
        printf("Fuue cancelado\n");
    }

}

//---------------------------------------------------------------------------------------------------------------------

int validarCodigoDeActores(eActor actores[],int ta,eNacionalidad nacionalidades[],int tn)
{
    int i;
    int flag = -1;
    int numero;

    MostrarActores(actores,ta,nacionalidades,tn);

    while( flag != 0)
    {
        getInt(&numero,"Ingrese el codigo de un Actor para el Elenco: ","Asegurese de haber un codigo valido",1,ta+1);

        for(i=0;i<ta;i++)
        {
            if(numero == actores[i].codigo)
            {
                flag=0;
                break;
            }
        }
    }

    return numero;

}

//---------------------------------------------------------------------------------------------------------------------

void harcodeoNacionalidades(eNacionalidad nacionalidad[],int len)
{
    int id[] = {1,2,3,4,5};
    char descripcion[][51] = {"argentina","chile","bolivia","EEUU","inglaterra"};
    int i;

    for(i=0;i<len;i++)
    {
        nacionalidad[i].idNacinalidad = id[i];
        strcpy(nacionalidad[i].descripcionPais,descripcion[i]);
    }
}
