#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>



//CREACION DE FUNCIONES

//ALGORITMO DE INSERTION
void insertion_sort (double *arr, unsigned int length);
//ALGORITMO DE BURBUJA
void bubble_sort(double *arr, unsigned int len);
//FUNCION DEL SWAP
void swap(double *a, double *b);
//fUNCION PARA CONVIERTIR UN ARCHIVO .csv A UNA LISTA DE DOUBLE
void conv_buffer( char *buff_user,unsigned int size, double *ARR1);
//FUNCION TAMA�O ARREGLO
unsigned int tam_arr(char *dir_buf, unsigned int len);




//FUNCION PARA LEER UN ARCHIVO
char *read_file_to_buffer (const char *path, unsigned int *size);
//Para liberar la memoria en cada ejecucuion
void free_buffer_mem(char *b);
//Para guardar en elarchivo los valores ordenados
void write_dArray_to_file (const double *arr, unsigned int len, const char *path);



void main (int argc, char *argv[])
{
	if (argc!=4)
	{
		printf("\n ERROR la cantidad de argumentos ingresados no es correcta\n");
		exit(1);
	}

	clock_t tiempo_inicio, tiempo_fin;
	double tiempo_usado=0;



	//convertir a double
	char *direc_buffer;
	unsigned int ls_buff_len;
	direc_buffer = read_file_to_buffer (argv[2], &ls_buff_len);

	tiempo_inicio = clock();

	unsigned int TAMD;
	TAMD = tam_arr(direc_buffer,ls_buff_len);
	double ARR[TAMD];
 	conv_buffer(direc_buffer, TAMD, &ARR[0]);
       
	tiempo_fin = clock(); //fin t_1
	tiempo_usado = (double)(tiempo_fin - tiempo_inicio) / CLOCKS_PER_SEC;

	printf("\n El tiempo 1 es: %f\n",tiempo_usado);

	int i;
	i = atoi(argv[1]);

        if (i ==1){
		tiempo_inicio =clock();
		insertion_sort(&ARR[0], TAMD);
		tiempo_fin =clock();
	}
	else
	{
                tiempo_inicio =clock();
		bubble_sort(&ARR[0],TAMD);
		tiempo_fin =clock();
	}

	tiempo_usado = (double)(tiempo_fin - tiempo_inicio) / CLOCKS_PER_SEC;

	printf("\n El tiempo 2 es: %f\n",tiempo_usado);


	free_buffer_mem(direc_buffer);
	tiempo_inicio =clock();
	write_dArray_to_file (&ARR[0], TAMD , argv[3]);
	tiempo_fin =clock();
	tiempo_usado = (double)(tiempo_fin - tiempo_inicio) / CLOCKS_PER_SEC;
	printf("\n El tiempo 3 es: %f\n",tiempo_usado);

}



char *read_file_to_buffer (const char *file_path, unsigned int *file_size)
{
	char *f_buff;
	FILE *file_in = fopen (file_path,"r"); /*Open CFG file*/

    if ( file_in == NULL )
    {
		fprintf(stderr,"\n\n¡Error!. No pudo leer archivo cfg: %s\n\n",file_path);
		exit(1);
    }
	/*CFG file size*/
	fseek ( file_in , 0 , SEEK_END );
	*file_size = ftell (file_in);
	
	rewind (file_in);

	f_buff = (char*) malloc (sizeof(char)*(*file_size));
	if (f_buff == NULL)
	{
		fputs ("Memory error",stderr);
		fprintf(stderr,"Error!");
		exit (2);
	}
	// copy the file into the buffer:
	if (fread ( f_buff , 1 , *file_size , file_in ) != *file_size) {
		fputs ("Reading error",stderr);
		exit (3);
	}

	f_buff[*file_size] = '\0';

	//close file
	fclose(file_in);
	
	return f_buff;
}

void free_buffer_mem(char *b)
{
	int a;
	free (b);
}

void write_dArray_to_file (const double *arr, unsigned int len, const char *path)
{
	unsigned long int cont1 = 0;
	
	FILE *file_out = fopen (path,"w"); /*Open CFG file*/
	for (cont1 = 0 ; cont1 < len ; cont1++)
		fprintf(file_out, "%.10f\n", *(arr + cont1));
	fclose(file_out);
}




//----------------------------------------------------------------
//ALGORITMO DE INSERTION
void insertion_sort (double *arr, unsigned int length)
{
        int i=0, j=0;
	double key=0;
        for (j=1;j<length;j++)
	{
                key=arr[j];
                ////Inserta A[j] dentro de la secuencia ordenada A[1... j - 1 ]
                i=j-1;
                while (i>=0 && arr[i]>key)
		{
                        arr[i+1]=arr[i];
                        i=i-1;
                }
                arr[i+1]=key;
        }
}

//----------------------------------------------------------------
//ALGORITMO DE BURBUJA
void bubble_sort(double *arr, unsigned int len)
{
	int i, j;
	for(i = 0; i < len-1; i++)
	{
		for(j = len-1; j > i; j--)
		{
			if(arr[j] < arr[j-1])
			{
				swap(&arr[j], &arr[j-1]);
			}
		}
	}
}

void swap(double *a, double *b)
{
	double temp;
	temp = *a;
	*a = *b;
        *b = temp;
}


//-----------------------------------------------------------------
//fUNCION PARA RECORRER EL ARREGLO Y CONVERTIR CHAR A DOUBLE
//CONVIERTE EL ARCHIVO .csv A UNA LISTA DE DOUBLE
void conv_buffer( char *buff_user,unsigned int size, double *ARR1)
{

    char *sig_n;
    char *temp;
    double val;
    unsigned int j;
    temp = buff_user;

   for(j = 0; j < size; j++)
    {
        sig_n = strchr(temp, '\n');
        val = atof(temp);
        temp = sig_n+1;
        ARR1[j] = val;
    }

}

//-----------------------------------------------------------------
//ALGORTMO PARA SABER EL TAMAÑO DEL ARREGLO
unsigned int tam_arr(char *dir_buf, unsigned int len)
{
	unsigned int j, cont=0;
		for(j=0;j<len;j++)
		{
			if (dir_buf[j]=='\n')
			{
			cont++;
			}
		}
	return (cont);
}





