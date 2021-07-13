#include <iostream>
#include <vector>
using namespace std;

#define INF 99999


vector<vector<int>> floydWarshall (vector<vector<int>> graph) {
    vector<vector<int>> dist(graph);

    int V = graph.size();

    for(int k=0; k<V; k++) {
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}


int main() {


    vector<vector<int>> graph = {
        {0, INF , -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}

    };

   auto result =  floydWarshall(graph);

   for(int i=0; i<result.size(); i++) {
       for(int j=0; j<result.size(); j++) {
           cout<<result[i][j]<<" ";
       }
       cout<<endl;
   }
}