#Montecarlo
* Do rozwiązania załączam wykres stworzony z danych poniżej.
#1. Testy montecarlo:
*	N				Czas
*	100000		 	0
*	1000000			30000
*	10000000	 	330000
*	100000000	 	3380000
*	1000000000	 	33800000
*	10000000000	 	47690000

#2. Testy mpimontecarlo dla czterech procesów:
*	N Czas
*   10000			80000
*	100000		 	80000
*	1000000			90000
*	10000000	 	190000
*	100000000	 	1180000
*	1000000000	 	11460000
*	10000000000	 	16230000
* dla n=10000000000 i 10 procesów czas wynosi: 6860000
* dla n=10000000000 i 15 procesów czas wynosi: 4490000

Program z MPI działa dużo szybciej na dużych liczbach niż program bez MPI.
Jak widać w testach, dla bardzo dużych 'n', im więcej procesów włączymy tym szybciej algorytm zostanie policzony. 
Dla 15 procesów algorytm jest prawie 11 razy szybszy od programu bez MPI, dla n=10000000000.
