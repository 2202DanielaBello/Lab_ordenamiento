#ifndef LIB1_H
#define LIB1_H

//FUNCION PARA LEER UN ARCHIVO
char *read_file_to_buffer (const char *path, unsigned int *size);
//Para liberar la memoria en cada ejecucion
void free_buffer_mem(char *b);
//Para guardar en elarchivo los valores ordenados
void write_dArray_to_file (const double *arr, unsigned int len, const char *path);

#endif
