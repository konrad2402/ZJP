all: montecarlo mpimontecarlo run clear

montecarlo: montecarlo.o
	gcc -o montecarlo montecarlo.c -lm
montecarlo.o: montecarlo.c
	gcc -c montecarlo.c -lm

mpimontecarlo: mpimontecarlo.o
	mpicc -o mpimontecarlo mpimontecarlo.c -lm
mpimontecarlo.o: mpimontecarlo.c
	mpicc -c mpimontecarlo.c -lm

run:
	mpirun -np 4 ./mpimontecarlo 100000
	./montecarlo 100000
	
clear:
	rm -r *.o