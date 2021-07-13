#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
const int dim = 26;

typedef struct Trie
{
	struct Trie* succ[dim];
	bool frunza;
}Trie;


Trie* genNod(void)
{
	Trie* n = new Trie;

	n->frunza = false;

	for (int i = 0; i < dim; i++)
		n->succ[i] = NULL;

	return n;
}


void inserare(struct Trie* root, string key)
{
	struct Trie* p = root;

	for (std::size_t i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!p->succ[index])
			p->succ[index] = genNod();

		p = p->succ[index];
	}


	p->frunza = true;
}


bool cautare(Trie* r, string key)
{
	struct Trie* p = r;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!p->succ[index])
			return false;

		p = p->succ[index];
	}

	return (p != NULL && p->frunza);
}


int main()
{

	string keys[4];
	keys[0] = "algoritm";
	keys[1] = "trie";
	keys[2] = "facultate";
	keys[3] = "laptop";


	int n = 4;

	Trie* T = genNod();


	for (int i = 0; i < n; i++)
		inserare(T, keys[i]);
	cout << "Cauta cuvantul trie in arbore  ";
	if (cautare(T, "trie"))
		cout << "Exista\n";
	else
		cout << "Nu exista\n";
	cout << "Cauta cuvantul calculator in arbore ";
	if (cautare(T, "calculator"))
		cout << "Exista\n";
	else
		cout << "Nu exista\n";
	return 0;
}