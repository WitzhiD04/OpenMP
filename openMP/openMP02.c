/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Carlos Guiza
        Fecha: 20 de Mayo 2025
        Materia: Sistemas Operativos
        Tema: OpenMP
        Fichero: openMP02.c
        Descripcion: Uso de directivas basadas en openMP para hacer concurrencia y aprovechar el paralelismo con hilos de ejecucion
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // Header necesario para invocar Api OMP

// Gestion y creacion de los 3 hilos
int main(int argc, char *argv[]) {
	
	if (argc < 2) {
		printf("error falta argumento\n");
		printf("\n $Ejecutable numHIlos \n\n");
		exit(0);
	}
	
	int hilosTotales = omp_get_max_threads();	
	int setHilos = (int) atoi(argv[1]);
	omp_set_num_threads(setHilos);
	int i;
	int a = 50;
	int b = 0;
	const int N = 1000; // constante de valor 1000
	
	// se usa pragma para dar la directiva al compilador
#pragma omp parallel
	//int HilosEstablecidos = omp_get_num_threads();
	printf("\n Hilos totales = %d \t \t HIlos Establecidos = %d\n\n", hilosTotales, omp_get_num_threads());	

#pragma omp parallel for private(i,a)

	for ( i = 0; i < N; i++) {
		b= a + i;
	}

	printf("Valor de a: %d; Valor de b = %d; (se espera b = 1049) \n", a,b);
	return 0;
}


