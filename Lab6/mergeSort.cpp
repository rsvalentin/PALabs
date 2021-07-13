#include<iostream>
using namespace std;


void interclasare(int a[], int p, int q, int m, int* temp) {
    int i = p;
    int j = m + 1;
    int k = -1;
    while ((i <= m) && (j <= q)) {
        k = k + 1;
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            i = i + 1;
        }
        else {
            temp[k] = a[j];
            j = j + 1;
        }
    }
    while (i <= m) {
        k = k + 1;
        temp[k] = a[i];
        i = i + 1;
    }
    while (j <= q) {
        k = k + 1;
        temp[k] = a[j];
        j = j + 1;
    }
}


void mergeSort(int a[], int p, int q) {
    int n = q - p + 1;
    if (p < q) {
        int m = (p + q) / 2;
        mergeSort(a, p, m);
        mergeSort(a, m + 1, q);
        int* temp = new int[n];
        interclasare(a, p, q, m,temp);
        for (int i = p; i <= q; i++) {
        a[i] = temp[i - p];
    }
    delete[] temp;
    }
}


void afisare(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << a[i]<<" ";
    cout << endl;
}


int main() {

    int arr[500000];
	clock_t start1, start2, finish1, finish2;
	long loop;
	for (int i = 0; i < 500000; i++) {
		arr[i] = rand() % 500000 + 1;
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	double elapsed_time1, elapsed_time2, elapsed_time3, elapsed_time4;
	start1 = clock(); //inceputul experimentului
	mergeSort(arr, 0, n-1);
	finish1 = clock(); //sfarsitul operatiilor cronometrate
	elapsed_time1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	elapsed_time2 = 1000.0* (double)(finish1 - start1) / CLOCKS_PER_SEC;
	cout<<"Merge Sort necesita "<<elapsed_time1<< " secunde sau "<<elapsed_time2<<" milisecunde"<<endl;
	return 0;
}

