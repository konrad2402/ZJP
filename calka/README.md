#CAŁKA
* Do rozwiązania załączam wykres stworzony z danych poniżej.
#1. Testy całki dla x=(-2;2):
#	N			Czas
*	10000		0
*	100000		20000
*	1000000		170000
*	10000000	1860000
*	100000000	17390000

#2. Testy mpicałki dla x=(-2;2) i czterech procesów:
#	N			Czas
*  	10000		80000
*	100000		80000
*	1000000		140000
*	10000000	700000
*	100000000	5950000
* 	dla n = 100000000 i 10 procesów czas wynosi: 2320000
* 	dla n = 100000000 i 15 procesów czas wynosi: 1350000

Wnioski: 
- Dla małych liczb mpi może się nie sprawdzać, ale jeśli algoryt działa na dużych liczbach mpi działa szybciej niż program nie używający mpi. 
- Jak widać na przykładzie powyżej, mpicałka szybciej wykonała obliczenia dla 15 procesów niż dla 10 czy 4.