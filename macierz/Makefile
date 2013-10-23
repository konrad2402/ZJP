all: macierz mpimacierz

macierz: macierz.o
	gcc -o macierz macierz.c -lm
macierz.o: macierz.c
	gcc -c macierz.c -lm

mpimacierz: mpimacierz.o
	mpicc -o mpimacierz mpimacierz.c -lm
mpimacierz.o: mpimacierz.c
	mpicc -c mpimacierz.c -lm

run:
	mpirun -np 4 mpimacierz 7
	./macierz 400
	
clear:
	rm -r *.o
	ls
