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
        else if (x >= 100) printf("%ld  ", x);
        else if (x >= 10) printf("%ld   ", x);
        else printf("%ld    ", x);
}

int main(int argc, char **argv){
		int rank; // dany proces
		int tmp;// do sprawdzenia czy ilosc procesow jest rowna wielkosci macierzy
		int namelen;
		long int x;
		int numprocs; // ilosc procesow
		long int i = 0, l=x+2;
		int k = 0, xx = 0;
		long int macierz1[l][l], wektor[l], wynik[l][l];
		srand(time(NULL)); // zapewnia losowanie roznych liczb

		/* Message tag */
		int tag = 1;
		//MPI_Status status;
        x = atoi(argv[1]);
		MPI_Init(&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
		tmp = x%numprocs; // wyliczenie różnicy między ilosica procesow i wielkosica macierzy
		if(tmp != 0) {
		printf("%d   tmp\n", tmp);
			tmp = numprocs-tmp;		
		printf("%d   tmp\n", tmp);	
		}
		i = 0;
		if(rank == 0){
			/* LOSOWANIE LICZB I WYPELNIENIE MACIERZY I WEKTORA */
			for(i;i<x;i++){
				int j = 0;
				wektor[i] = randome();
				for(j;j<x;j++){
					macierz1[i][j] = randome();
				}
			}	
			// dopisanie zer
			if(tmp != 0) {
				for(tmp; tmp>=0; tmp--){
					int j = 0;
					wektor[i] = 0;
					for(j;j<x;j++){
						macierz1[i][j] = 0;
					}
				}
			}
		}
		
	/* LICZENIE MACIERZY */
		for(k = 0; k<x; k++){
			int begin = (rank-1)*n/size;
			int end = (rank)*n/size;  
			for(i = begin; i < end; i++){
				int j = 0;
				wynik[k][i] = 0;
				for(j;j<x;j++){
					xx = macierz1[k][j] * wektor[j];
					wynik[k][i] = wynik[k][i] + xx;
				}
			}
		}
				printf("\n");
		/* WYPISANIE MACIERZY 
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
		}*/
		MPI_Finalize();
		return 0;
}


