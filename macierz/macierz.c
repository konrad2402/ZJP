#include<stdio.h>
#include <stdlib.h>
#include <time.h>

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
	long int x = atoi(argv[1]);
	long int i = 0, l=x+2;
	long int k = 0, xx = 0;
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
