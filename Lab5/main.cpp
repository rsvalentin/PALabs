#include <iostream>
#include <math.h>
#include <chrono>
#include <time.h>
using namespace std;


void insertionSort(int a[], int n) {
	int i, k, temp;
	for (k = 1; k <= n - 1; k++) {
		i = k - 1;
		temp = a[k];
		while ((i >= 0) && (temp < a[i])) {
			a[i + 1] = a[i];
			i = i - 1;
		}
		if (i != k - 1) {
			a[i + 1] = temp;
		}
	}
}

void shellSort(int a[], int n) {
	int i, k;
	int start = (int)log(n) - 2;
	if (start < 0) {
		start = 0;
	}
	for (k = start; k >= 0; --k) {
		int h = pow(2, k + 1) - 1;
		for (i = h; i <= n - 1; ++i) {
			int temp = a[i];
			int j = i - h;
			while ((j >= 0) && (temp < a[j])) {
				a[j + h] = a[j];
				j = j - h;
				if (j + h != i) {
					a[j + h] = temp;
				}
			}
		}
	}
}

int main() {
	int arr[200000];
	clock_t start1, start2, finish1, finish2;
	long loop;
	for (int i = 0; i < 200000; i++) {
		arr[i] = rand() % 200000 + 1;
	}
	double elapsed_time1, elapsed_time2, elapsed_time3, elapsed_time4;
	start1 = clock(); //inceputul experimentului
	insertionSort(arr, 200000);
	finish1 = clock(); //sfarsitul operatiilor cronometrate
	elapsed_time1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	elapsed_time2 = 1000.0* (double)(finish1 - start1) / CLOCKS_PER_SEC;
	printf("\nInsertion Sort necesita %6.2f secunde sau %6.2f milisecunde.\n", elapsed_time1, elapsed_time2);

	start1 = clock(); //inceputul experimentului
	shellSort(arr, 200000);
	finish1 = clock(); //sfarsitul operatiilor cronometrate
	elapsed_time1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	elapsed_time2 = 1000.0* (double)(finish1 - start1) / CLOCKS_PER_SEC;
	printf("\Shell Sort necesita %6.2f secunde sau %6.2f milisecunde.\n", elapsed_time1, elapsed_time2);

	return 0;
}