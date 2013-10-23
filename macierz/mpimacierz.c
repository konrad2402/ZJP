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
        int i,j,a=0,b=0,lol=0;
        long int n,tmp,k;  
        long int wycinek;
		
		
        MPI_Init(&argc, &argv);        
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
 
        n = atoi(argv[1]);

        tmp = n%size;
        if(tmp!=0){
            tmp = size - tmp;
            n = n + tmp;
		}
		long int macierz1[n*n+5], wektor[n*n+5], wynik[n*n+5], pomocnicza[n*n+5], pomoc2[n*n+5];
		pomocnicza[0] = 0;
		wycinek = (n*n)/size;
		for(j=0;j<n;j++){          
           wektor[j]=j+1;
           }
		 if (rank == 0){ 
				srand(time(NULL)); // zapewnia losowanie roznych liczb
                int liczba = atoi(argv[1]); // n bez zer
                        for (i = 0; i<n*n; i++){ 
                                lol++;   
                                if(i>=((n*n)-(n*tmp))) macierz1[i]=0;
                                else if(lol-1<liczba) macierz1[i]=i;  
                                else if (lol<=n) macierz1[i]=0; 
                                else if(lol>=n+1){
                                        lol=0; i--;
                                }
                        }
                    }
		
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
			k = lala;
			i = 0;
				j = 0;
			for(i;i<lala;i++){
				for(j;j<k;j++){
					wypisz(macierz1[j]);
				}
				k = k + lala + tmp;
				j = j + tmp;
				if(i == (lala/2)) printf("  *  ");
				else printf("     ");	
				wypisz(wektor[i]);
				if(i == (lala/2)) printf("  =  ");
				else printf("     ");	
				wypisz(wynik[i]);
				printf("\n");
			}
		stop=clock();
		timee=(stop - start);
		printf("Czas wykonania algorytmu to: %ld\n", stop-start);
		}
        return 0;
}
