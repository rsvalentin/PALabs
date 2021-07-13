#include "header.h"


int main() {
	ListaCirculara LC;
	Node* first = nullptr;
	clock_t start1,start2,finish1,finish2;
	long loop;
	double elapsed_time1, elapsed_time2, elapsed_time3, elapsed_time4;
	start1 = clock(); //inceputul experimentului
	for (int i = 0; i < 10000; i++) {
		LC.inserareLiniara(i);
	}
	finish1 = clock(); //sfarsitul operatiilor cronometrate
	elapsed_time1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	elapsed_time2 = 1000.0* (double)(finish1 - start1) / CLOCKS_PER_SEC;
	printf("\nInserearea liniara necesita %6.2f secunde sau %6.2f milisecunde.\n", elapsed_time1, elapsed_time2);

	start2 = clock(); //inceputul experimentului
	for (int i = 0; i < 10000; i++) {
		first = LC.inserareConstanta(first, 3);
	}
	finish2 = clock(); //sfarsitul operatiilor cronometrate
	elapsed_time3 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
	elapsed_time4 = 1000.0* (double)(finish2 - start2) / CLOCKS_PER_SEC;
	printf("\nInserearea constanta necesita %6.2f secunde sau %6.2f milisecunde.\n", elapsed_time3, elapsed_time4);
	
	return 0;
}