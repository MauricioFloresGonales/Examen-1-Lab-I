typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int codigo;
    char descripcion[51];
    int duracion;
    int idGenero;
    eFecha fecha;

}ePelicula;

typedef struct
{
    int id;
    char descripcion[51];

}eGenero;

void harcodeoGeneros(eGenero[],int len);

void harcodeoPeliculas(ePelicula[],int len);
void inicializarPeliculas(ePelicula[],int len);
//void ingresarPelicula(ePelicula[],int len);
int indiceLibrePelicualas(ePelicula[],int len);
int idAutoPeliculas(ePelicula[],int len,int valMenor);
int idMayorPeliculas(ePelicula[],int len,int valMenor);
int buscarCodigoPeliculas(ePelicula peliculas[],int len,eGenero generos[],int tg);
void mostrarUnaPelicula(ePelicula[],int index,eGenero[],int tamGen);
void MostrarPeliculas(ePelicula[],int len,eGenero[],int tamGen);

int validarCodigoDePelicula(ePelicula[],int tp,eGenero[],int tg);
