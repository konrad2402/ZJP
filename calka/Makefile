all: calkaa mpicalkaa 

calkaa: calka.o
	gcc -o calka calka.c -lm
calka.o: calka.c
	gcc -c calka.c -lm

mpicalkaa: mpicalka.o
	mpicc -o mpicalka mpicalka.c -lm
mpicalka.o: mpicalka.c
	mpicc -c mpicalka.c -lm

run:
	mpirun -np 4 ./mpicalka 1000000 -2 2
	./calka 1000000 -2 2
	
clear:
	rm -r *.o
	ls
