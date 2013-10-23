#include <stdio.h>
#include <stdlib.h>
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
		clock_t start, stop;
		start=clock();
		double timee;
        int rank;
        int size;
        int i,j,a=0,b=0;
        long int n,tmp,k;  
        long int wycinek;
		
		
        MPI_Init(&argc, &argv);        
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
 
        n = atoi(argv[1]);

		long int macierz1[n*n], wektor[n*n], wynik[n*n], pomocnicza[n*n], pomoc2[n*];
		
        tmp = n%size;
        if(tmp!=0){
            tmp = size - tmp;
            n = n + tmp;
		}
		wycinek = (n*n)/size;
		
        MPI_Scatter( &macierz1 , wycinek  , MPI_INT , &pomoc2, wycinek  , MPI_INT , 0 , MPI_COMM_WORLD);
		j = n/size;
        for (i=0; i<wycinek; i++){
                if(a>=n) {a=0; b++; }
                pomocnicza[b]=pomocnicza[b]+(pomoc2[i]*wektor[a]);
                a++;
        }
		
        MPI_Gather(&pomocnicza,j, MPI_INT, &wynik,j, MPI_INT, 0, MPI_COMM_WORLD);
        if (rank == 0){
		/* WYPISANIE MACIERZY */
			int lala = atoi(argv[1]);
			i = 0;
			for(i;i<lala;i++){
				j = 0;
				for(j;j<lala;j++){
					wypisz(macierz1[j]);
				}
				if(i == (lala/2)) printf("  *  ");
				else printf("     ");	
				wypisz(wektor[i]);
				if(i == (lala/2)) printf("  =  ");
				else printf("     ");	
				wypisz(wynik[i]);
				printf("\n");
			}
        }
		stop=clock();
		timee=(stop - start);
		printf("Czas wykonania algorytmu to: %ld\n", stop-start);
        return 0;
}
