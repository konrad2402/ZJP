#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char **argv){
		clock_t start, stop;
		start=clock();
		double timee;
        int rank;
        int size;
        int i,j;
        long int n,tmp,k;  
        long int wycinek=2;
		
        MPI_Init(&argc, &argv);        
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
 
        n = atoi(argv[1]);

        tmp = n%size;
        if(tmp!=0){
            tmp = size - tmp;
            n = n + tmp;
		}
        long int macierz1[l][l], wektor[l], wynik[l];
	srand(time(NULL)); // zapewnia losowanie roznych liczb
/* LOSOWANIE LICZB I WYPELNIENIE MACIERZY */
	for(i;i<x;i++){
		long int j = 0;
		wektor[i] = randome();
		for(j;j<x;j++){
			macierz1[i][j] = randome();			
		}
	}
	for(k = 0; k<x; k++){
		for(i = 0;i<x;i++){
			long int j = 0;
			wynik[k] = 0;
			int suma = 0;
			for(j;j<x;j++){	
				xx = macierz1[k][j] * wektor[j];
//				printf("%ld XXX %ld\n", macierz1[k][i], wektor[i][j]);
				wynik[k] = wynik[k] + xx;
			}
		}	
	}
		printf("\n");
	/* WYPISANIE MACIERZY */
	i = 0;
	for(i;i<x;i++){
		long int j = 0;
		for(j;j<x;j++){
			wypisz(macierz1[i][j]);
		}
		if(i == (x/2)) printf("  *  ");
		else printf("     ");	
		wypisz(wektor[i]);
		if(i == (x/2)) printf("  =  ");
		else printf("     ");	
		wypisz(wynik[i]);
		printf("\n");
	}
		stop=clock();
		timee=(stop - start);
		printf("Czas wykonania algorytmu to: %ld\n", stop-start);
        return 0;
}
