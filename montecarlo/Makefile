all: montecarlo mpimontecarlo run 

montecarlo: montecarlo.o
	gcc -o montecarlo montecarlo.c -lm
montecarlo.o: montecarlo.c
	gcc -c montecarlo.c -lm

mpimontecarlo: mpimontecarlo.o
	mpicc -o mpimontecarlo mpimontecarlo.c -lm
mpimontecarlo.o: mpimontecarlo.c
	mpicc -c mpimontecarlo.c -lm

run:
	mpirun -np 4 ./mpimontecarlo
	./montecarlo
	
clear:
	rm -r *.o