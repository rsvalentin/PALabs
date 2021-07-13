#include "header.h"


void ListaCirculara::inserareLiniara(int val) {
	Node* u = new Node();
	u->data = val;

	if (head == nullptr) {
		u->next = u;
		head = u;
	}
	else {
		u->next = head;
		Node* it = head;
		while (it->next != head) {
			it = it->next;
		}
		it->next = u;
	}
}

Node* ListaCirculara::inserareConstanta(Node* first, int val) {
	Node* u = new Node();
	if (first == nullptr) {
		if (first != nullptr) {
			return first;
		}
		u->data = val;
		first = u;
		first->next = first;
		return first;
	}
	else {
		u->data = val;
		u->next = first->next;
		first->next = u;
		first = u;
		return first;
	}
}
