/*
Dat fiind un text memorat intr-un fisier, scrieti un program C/C++ care codifica binar textul
astfel incat lungimea medie a codului rezultat sa fie minima (Vezi algoritmul lep, figura 4 si
algoritmul de constructie a arborelui Huffman optim).
*/


#include <iostream> 
#include <iterator> 
#include <map> 
#include<vector>
#include<queue>
using namespace std; 

map<char, string> codes; // hash table pentru codurile caracterelor  
map<char, int> freq; // hash table pentru frecventa caracterelor
  
// min heap pentru arborele huffman
struct MinHeapNod 
{ 
    char caracter;             
    int frecventa;            
    MinHeapNod *left, *right; 
  
    MinHeapNod(char c, int frecv) 
    { 
        left = right = NULL; 
        this->caracter = c; 
        this->frecventa = frecv; 
    } 
}; 
  

struct compare 
{ 
    bool operator()(MinHeapNod* left, MinHeapNod* right) 
    { 
        return (left->frecventa > right->frecventa); 
    } 
}; 
  
  //functie care adauga codurile in tabela codes
void addCodes(struct MinHeapNod* r, string str) 
{ 
    if (r==NULL) 
        return; 
    if (r->caracter != '\0') 
       codes[r->caracter]=str; 
    addCodes(r->left, str + "0"); // daca merg pe stanga adaug bitul 0
    addCodes(r->right, str + "1"); // daca merg pe dreapta adaug bitul 1
} 
  

priority_queue<MinHeapNod*, vector<MinHeapNod*>, compare> minHeap; 
  
// construiesc arborele huffman
void HuffmanCod(int size) 
{ 
    struct MinHeapNod *left, *right, *root; 
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++) 
        minHeap.push(new MinHeapNod(v->first, v->second)); 
    while (minHeap.size() != 1) 
    { 
        left = minHeap.top(); 
        minHeap.pop(); 
        right = minHeap.top(); 
        minHeap.pop(); 
        root = new MinHeapNod('\0', left->frecventa + right->frecventa);
    
        root->left = left; 
        root->right = right; 
        minHeap.push(root); 
    } 
    addCodes(minHeap.top(), ""); 
} 
  
void findFreq(string str) 
{ 
    for (int i=0; i<str.size(); i++) 
        freq[str[i]]++; 
} 
  

int main() 
{ 
    string coded;
    string str = "HARABABURA"; 
    cout<<"Inainte de encode:\n"<<str<<endl;
  
    findFreq(str); 
    HuffmanCod(str.length()); 
    cout << "\nFrecventele caracterelor:\n"; 
    for (auto v : freq) 
        cout << v.first <<":" << v.second << endl; 
    
    cout << "\nCodurile caracterelor:\n"; 
    for (auto v : codes) 
        cout << v.first <<":" << v.second << endl; 
  
    for (auto i: str) 
        coded+=codes[i]; 
  
    cout << "\nDupa encode:\n" << coded << endl; 
   
    return 0; 
} 
