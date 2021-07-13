#pragma once
#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;


struct Node {
	Node* next;
	int data;
};


class ListaCirculara {
public:
	Node* head;
	ListaCirculara() {
		this->head = nullptr;
	}
	void inserareLiniara(int val);
	Node* inserareConstanta(Node* first, int val);
};