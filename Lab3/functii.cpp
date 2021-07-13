#include "header.h"

BTreeNode* allocateNode(int leaf) {
	BTreeNode* x = new BTreeNode();
	x->leaf = leaf;
	x->n = 0;
	return x;

}
void createBTree(BTree* T) {
	BTreeNode* x = allocateNode(1);
	x->leaf = 1;
	x->n = 0;
	T->root = x;
}
void BTreeSplitChild(BTreeNode* x, int i) {
	BTreeNode* y = x->children[i];
	BTreeNode* z = allocateNode(y->leaf);
	z->n = fact - 1;
	int j;
	for (j = 0; j < fact - 1; j++) {
		z->keys[j] = y->keys[j + fact];
	}
	if (y->leaf == 0) {
		for (j = 0; j < fact; j++) {
			z->children[j] = y->children[j + fact];
		}
	}
	y->n = fact - 1;
	for (j = x->n; j >= i + 1; j--) {
		x->children[j + 1] = x->children[j];
	}
	x->children[i + 1] = z;
	for (j = x->n - 1; j >= i; j--) {
		x->keys[j + 1] = x->keys[j];
	}
	x->keys[i] = y->keys[fact - 1];
	x->n += 1;
}

void BTreeInsertIncomplete(BTreeNode* x, int k) {
	int i = x->n - 1;
	if (x->leaf == 1) {
		while (i >= 0 && x->keys[i] > k) {
			x->keys[i + 1] = x->keys[i];
			i--;
		}
		x->keys[i + 1] = k;
		x->n += 1;
	}
	else {
		while (i >= 0 && x->keys[i] > k) {
			i--;
		}
		if (x->children[i + 1]->n == 2 * fact - 1) {
			BTreeSplitChild(x, i + 1);
			if (k > x->keys[i + 1]) {
				i++;
			}
		}
		BTreeInsertIncomplete(x->children[i + 1], k);
	}
}
void BTreeInsert(BTree* T, int k) {
	BTreeNode* r = T->root;
	if (r->n == 2 * fact - 1) {
		BTreeNode* s = allocateNode(0);
		T->root = s;
		s->children[0] = r;
		BTreeSplitChild(s, 0);
		int i = 0;
		if (s->keys[0] < k) {
			i++;
		}
		BTreeInsertIncomplete(s->children[i], k);
	}
	else {
		BTreeInsertIncomplete(r, k);
	}
}

void BTreeTraverseRec(BTreeNode *x) {
	int i;
	for (i = 0; i < x->n; i++) {
		if (x->leaf == 0) BTreeTraverseRec(x->children[i]);
		cout<<" "<<x->keys[i];
	}

	if (x->leaf == 0) BTreeTraverseRec(x->children[i]);
}

void BTreeTraverse(BTreeNode *x) {

	BTreeTraverseRec(x);
	cout << endl;
}

BTreeNode* search(BTreeNode* x, int k) {
	int i = 0;
	while (i < x->n && k > x->keys[i]) {
		i++;
	}
	if (x->leaf == 1) {
		return nullptr;
	}
	else {
		return search(x->children[i], k);
	}
}
