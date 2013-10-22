#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<time.h>

#define N 10000000

main(int argc, char* argv)
{
    clock_t start, stop;
	start=clock();
	long int n=N; 
	double x,y,timee;
	int i; 
	double z;
	double pi, wynik;

	srand(time(NULL)); // zapewnia losowanie roznych liczb
	wynik=0;
	for ( i=0; i<n; i++) {
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		z = x*x+y*y;
		if (z<=1) wynik++;
	}
	pi=(double)wynik/n*4;
	printf("\nPi wynosi: %f \n",pi);
	stop=clock();
    timee=(stop - start);
	printf("Czas wykonania algorytmu to: %ld\n", stop-start);
}