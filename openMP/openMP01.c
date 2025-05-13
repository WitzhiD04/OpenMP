/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Carlos Guiza
        Fecha: 13 de Mayo 2025
        Materia: Sistemas Operativos
        Tema: openMP
        Fichero: openMP01.c
        Objetivo: Crea hilos de ejecucion para cada core e imprime cadena de caracteres por cada llamada
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // Header necesario para invocar APi OMP

// Gestion y creacion de los 3 hilos
int main(int argc, char *argv[]) {

	
	// Se imprime cuantos hilos maximos se puede ejecutar segun la cantidad de cores
	printf("OPenMP ejecutando con %d hilos \n", omp_get_max_threads());
	
	// se usa pragma para dar la directiva al compilador
	#pragma omp parallel
	{
		//SE imprime por cada hilo su id respectivo
		printf("Hello World desde el thread %d\n", omp_get_thread_num());
	}
	return 0;
}


