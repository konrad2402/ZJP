all: calkaa mpicalkaa run 

calkaa: calka.o
	gcc -o calka calka.c -lm
calka.o: calka.c
	gcc -c calka.c -lm

mpicalkaa: mpicalka.o
	mpicc -o mpicalka mpicalka.c -lm
mpicalka.o: mpicalka.c
	mpicc -c mpicalka.c -lm

run:
	mpirun -np 4 ./mpicalka
	./calka
	
clear:
	rm -r *.o
	ls
