#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int numberLength(long long value) {
	int counter = 0;
	while (value != 0)
	{
		counter++;
		value /= 10;
	}
	return counter;
}

long long multiply(long x, long y) {
	int xLength = numberLength(x);
	int yLength = numberLength(y);

	int n = max(xLength, yLength);

	if (n < 10) {
        return x*y;
	}

    long multiplier = pow(10, n/2);
    long xS = x/multiplier;
    long xD = x - (xS * multiplier);
    long yS = y/multiplier;
    long yD = y - (yS * multiplier);

    return multiply(xS,yS) + multiply(xD,yD) + multiply((xS - xD),(yD - yS));

}


int main()
{
	clock_t start1, start2, finish1, finish2;
	long loop;
	double elapsed_time1, elapsed_time2, elapsed_time3, elapsed_time4;
	start1 = clock(); //inceputul experimentului
	//int res = multiply(12345678124234234,12345642342342378);
    int res = multiply(12333,43321);
	finish1 = clock(); //sfarsitul operatiilor cronometrate
	elapsed_time1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	elapsed_time2 = 1000.0*elapsed_time1; //(double)(finish1 - start1) / CLOCKS_PER_SEC;
    elapsed_time3 = 1000000.0*elapsed_time2;
	cout<<"Inmultirea smart necesita "<<elapsed_time1<< " secunde sau "<<elapsed_time2<<" milisecunde sau"<<elapsed_time3<<"nanosecunde"<<endl;
    cout<<res<<endl;
    return 0;
}
