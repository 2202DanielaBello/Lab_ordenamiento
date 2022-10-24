
#include"lib1.h"
#include"lib_gr2.h"

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

