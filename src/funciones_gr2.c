#include"lib1.h"
#include"lib_gr2.h"

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






