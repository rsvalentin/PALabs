#include <iostream>
using namespace std;

void interschimba(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitioneaza(int a[], int p, int q) {
    int k;
    int x = a[p];
    int i = p + 1;
    int j = q;

    while (i <= j) {
        if (a[i] <= x) {
            i = i + 1;
        }
        if (a[j] >= x) {
            j = j - 1;
        }
        if (i < j) {
            if ((a[i] > x) && (x > a[j])) {
                interschimba(a+i, a+j);
                i = i + 1;
                j = j - 1;
            }
        }
    }
    k = i - 1;
    a[p] = a[k];
    a[k] = x;
    return k;
}

void quickSort1(int a[], int p, int q) {
    if (p < q) {
        int k = partitioneaza(a,p,q);
        quickSort1(a,p,k-1);
        quickSort1(a,k+1,q);
    }
}

void afisare(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


int main() {
    int arr[500000];
	clock_t start1, finish1;
	for (int i = 0; i < 500000; i++) {
		arr[i] = rand() % 500000 + 1;
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	double elapsed_time1, elapsed_time2;
	start1 = clock(); //inceputul experimentului
	quickSort1(arr, 0, n-1);
	finish1 = clock(); //sfarsitul operatiilor cronometrate
	elapsed_time1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	elapsed_time2 = 1000.0* (double)(finish1 - start1) / CLOCKS_PER_SEC;
	cout<<"Quick Sort necesita "<<elapsed_time1<< " secunde sau "<<elapsed_time2<<" milisecunde"<<endl;
}
