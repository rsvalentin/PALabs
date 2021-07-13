#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int power(int x, int y) {
   int i,power=1;
   if(y == 0)
   return 1;
   for(i=1;i<=y;i++)
   power=power*x;
   return power;
}

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
        return (long long)x*y;
	}

    long long multiplier = pow(10, n/2);
    long long xS = x/multiplier;
    long long xD = x - (xS * multiplier);
    long long yS = y/multiplier;
    long long yD = y - (yS * multiplier);

    multiply(xS,yS*lround(pow(10,n))) + multiply(xS,yD*lround(pow(10,n/2))) + multiply(xD,yS*lround(pow(10,n/2))) + multiply(xD,yD);

}


int main()
{
	clock_t start1, start2, finish1, finish2;
	long loop;
	double elapsed_time1, elapsed_time2, elapsed_time3, elapsed_time4;
	start1 = clock(); //inceputul experimentului
	int res = multiply(123231,21312);
	finish1 = clock(); //sfarsitul operatiilor cronometrate
	elapsed_time1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	elapsed_time2 = 1000.0*(double)(finish1 - start1) / CLOCKS_PER_SEC;
    elapsed_time3 = 1000000000.0*(double)(finish1 - start1) / CLOCKS_PER_SEC;
	cout<<"Inmultirea naiva necesita "<<elapsed_time1<< " secunde sau "<<elapsed_time2<<" milisecunde sau"<<elapsed_time3<<"nanosecunde"<<endl;
    cout<<res<<endl;
    return 0;
}
