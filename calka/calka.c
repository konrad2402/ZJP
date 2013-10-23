/* calka dla x=(-2;2) dla n=512 */
// dla n=512 program działa bardzo szybko, dlatego zmieniam 512 na 1 000 000, żeby lepiej zaobserwowac czas działania
#include<stdio.h>
#include<math.h>
#include<time.h>

/* e^-x^2 */
double f (double x){
	return pow(M_E, -x*x);
}

/* f(x) = ([f(x_0*h) + f(x_1*h) + ... + f(x_n-1*h)]/2) *h */
int main(int argc, char **argv){
    clock_t start, stop;
	start=clock();
	double i, time;
	double calka = 0 ;
	double x=atoi(argv[2]), y=atoi(argv[3]), n = atoi(argv[1]);
	double h = (y-x)/n;

	for(i=1;i<(n-1);i++){
        calka += (f(x+i*h) + f(x+(i+1.0)*h))/2.0;
	}
    calka = calka * h;
    printf("\nCalka dla x=(%.0f;%.0f) i n=%d wynosi: %f \n", x, y, atoi(argv[1]), calka);
	stop=clock();
    time=(stop - start);
	printf("Czas wykonania algorytmu to: %ld\n", stop-start);
	return 0;
}
