
#ifndef LIB_GR2_H
#define LIB_GR2_H

//directorios

#include<stdio.h>//para inclusion de entradas y  salidas
#include<time.h> //para runtime - clock_t, clock(),CLOKS_PER_SEC
#include<stdlib.h> // Para atoi()

#include<math.h> //para define variables matematicas y una macro
#include<stdint.h> //para definir tamaños de tipo enteros
#include<string.h> //para manipular datos, copiar, cambiar caracteres, comparar cadenas
#define TAM //Tamaño de la lista de reales


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

#endif

