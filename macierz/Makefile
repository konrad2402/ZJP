all: macierz run 

macierz: macierz.o
	gcc -o macierz macierz.c -lm
macierz.o: macierz.c
	gcc -c macierz.c -lm

mpimacierz: mpimacierz.o
	mpicc -o mpimacierz mpimacierz.c -lm
mpimacierz.o: mpimacierz.c
	mpicc -c mpimacierz.c -lm

run:
	./macierz 400
	
clear:
	rm -r *.o
	ls
