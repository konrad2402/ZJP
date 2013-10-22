#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"


int randome(){
        int a = rand()%10;
        return a;
}
void wypisz(long int x){
        if (x >= 1000) printf("%ld ", x);
        else if (x >= 100) p
		printf("%ld  ", x);
        else if (x >= 10) printf("%ld   ", x);
        else printf("%ld    ", x);
}

int main(int argc, char **argv){
		int rank; // dany proces
		int namelen;
		int numprocs; // ilosc procesow
		long int i = 0, l=x+2;
		int k = 0, xx = 0;
		long int macierz1[l][l], wektor[l], wynik[l][l];
		srand(time(NULL)); // zapewnia losowanie roznych liczb

		/* Message tag */
		int tag = 1;
		//MPI_Status status;
		long int x, tmp;
        x = atoi(argv[1]);
		i = x;
		/* LOSOWANIE LICZB I WYPELNIENIE MACIERZY I WEKTORA */
		for(i;i<x;i++){
			int j = 0;
			wektor[i] = randome();
			for(j;j<x;j++){
				macierz1[i][j] = randome();
			}
		}
		MPI_Init(&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	
		if(numprocs==x) {
			int l;
			l = x+1;
		}
		else {
			int l = x/numprocs;
			l = l*numprocs;
			l = x-l;
			printf("%d LOLOL \n\n", l);
		}
			
	/* LICZENIE MACIERZY */
		for(k = 0; k<x; k++){
				for(i = 0;i<x;i++){
						int j = 0;
						wynik[k][i] = 0;
						for(j;j<x;j++){
								xx = macierz1[k][j] * wektor[j];
								wynik[k][i] = wynik[k][i] + xx;
						}
				}
		}
				printf("\n");
		/* WYPISANIE MACIERZY */
		i = 0;
		for(i;i<x;i++){
				int j = 0;
				for(j;j<x;j++){
						wypisz(macierz1[i][j]);
				}
				if(i == (x/2)) printf("  *  ");
				else printf("     ");
				
				wypisz(wektor[i]);
				
				if(i == (x/2)) printf("  =  ");
				else printf("     ");
				for(j = 0;j<x;j++){
						wypisz(wynik[i][j]);
				}
				printf("\n");
		}
		MPI_Finalize();
		return 0;
}


