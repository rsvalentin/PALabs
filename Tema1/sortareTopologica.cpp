/*
Scrieti un program C/C++ care sorteaza topologic varfurile unui digraf aciclic D = (V,A)
*/



#include<iostream> 
#include<list> 
#include<vector> 
#include<queue> 
using namespace std;
#define n 6
list<int>* adjList= new list<int>[n];


void sortareTopologica() 
{  
    vector<int> indegree(n, 0); //vector unde pun indegree-ul fiecarui nod, initiale toate-s 0.
    //parcurg lista de adiacenta si pentru fiecare nod, cresc indegree-ul nodurilor cu muchia spre ele.
    for (int u=0; u<n; u++) 
    { 
      //pt fiecare nod parcurg si lista cu nodurile catre care se indreapta, incrementand indegree-ul lor.
        list<int>::iterator itr; 
        for (itr = adjList[u].begin(); itr != adjList[u].end(); itr++) 
             indegree[*itr]++; 
    } 
  //dupa ce s-a format vectorul cu indegree, nodurile cu indegree 0 sunt puse in coada
    queue<int> q; 
    for (int i = 0; i < n; i++) 
        if (indegree[i] == 0) 
            q.push(i); 
  
    int count = 0; // variabila pentru numarat nodurile procesate
    vector <int> L; //vector unde sunt stocate nodurile in ordine topologica
    
    while (!q.empty()) 
    { 
       //scoatem nodu cu 0 indegree din coada si l bagam in L
        int u = q.front(); 
        q.pop(); 
        L.push_back(u); 
        // cand parcurgem lista cu vectorii aferenti nodului pe care vrem sa-l eliminam si eliminam o muchiile, indegree-ul nodurilor coresp. scade cu 1.
        list<int>::iterator itr; 
        for (itr = adjList[u].begin(); itr != adjList[u].end(); itr++) 
        // cand un nod ajunge cu indegree=0 atunci il bagam in coada
            if (--indegree[*itr] == 0) 
                q.push(*itr);
               
        count++; //am mai vizitat un nod
    } 
   
    if (count!= n) //daca count != n atunci nodul are circuite
    { 
        cout << "Graful contine circuite\n"; 
        return; 
    } 
   
    for (int i=0; i<L.size(); i++) // afisam elementele sortate topologic
        cout << L[i] << " "; 
    cout << endl; 
} 

    
int main() 
{ 
//afisarea AFBCDE corespunde cu 051234   

adjList[0].push_back(1);
adjList[0].push_back(3);
adjList[1].push_back(2);
adjList[2].push_back(3);
adjList[2].push_back(4);
adjList[3].push_back(4);

cout << "Nodurile sortate topologic:\n"; 
sortareTopologica(); 
  
return 0; 
} 
