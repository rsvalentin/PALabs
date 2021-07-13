#include <iostream>
using namespace std;
#define INFINITY 9999
#define n 5

void dijkstra(int G[n][n],int L[n][n],int i0,int D[n],int P[n]) {
   int visited[n],count,min,next,i,j;
   for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
   if(G[i][j]==0)
      L[i][j]=INFINITY;
   else
      L[i][j]=G[i][j];
   for(i=0;i<n;i++) {
      D[i]=L[i0][i];
      P[i]=i0;
      visited[i]=0;
   }
   D[i0]=0;
   visited[i0]=1;
   count=1;
   while(count<n-1) {
      min=INFINITY;
      for(i=0;i<n;i++)
         if(D[i]<min&&!visited[i]) {
         min=D[i];
         next=i;
      }
      visited[next]=1;
      for(i=0;i<n;i++)
         if(!visited[i])
      if(min+L[next][i]<D[i]) {
         D[i]=min+L[next][i];
         P[i]=next;
      }
      count++;
   }
   for(i=0;i<n;i++)
   if(i!=i0) {
      cout<<"\nDistanta"<<i<<"="<<D[i];
      cout<<"\nDrum="<<i;
      j=i;
      do {
         j=P[j];
         cout<<"<-"<<j;
      }while(j!=i0);
   }
}

int main()
{

   int G[n][n]={{1,0,0,2,8},{1,0,7,0,1},{0,2,0,4,1},{3,0,3,0,6},{9,1,0,6,0}};
   int L[n][n],i0=0,D[n],P[n];
   dijkstra(G,L,i0,D,P);
   return 0;
}