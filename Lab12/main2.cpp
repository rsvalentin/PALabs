#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p[] = {10, 30, 20};
    int wt[] = {3, 5, 6};

    int m = 7, n = 3;

    int k[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (w >= wt[i-1])
                k[i][w] = max(k[i - 1][w], k[i - 1][w - wt[i-1]] + p[i-1]);
            else
                k[i][w] = k[i - 1][w];
        }
    }

    cout << k[n][m] << "\n";

    int i = n, j = m;
    while(i>0 && j >0)
    {
        if(k[i][j] == k[i-1][j])
        {
            cout<<i<<"=0"<<endl;
            i--;
        }
        else
        {
            cout <<i<< "=1"<<endl;
            i--;
            j=j-wt[i];
        }
        
    }
}