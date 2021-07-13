#include "header.h"
#include <stdlib.h>


int main() {
	BTree T;
	createBTree(&T);
	for (int i = 0; i < 100; i++) {
		BTreeInsert(&T, rand()%1000);
	}
	BTreeTraverse(T.root);

	return 0;
}