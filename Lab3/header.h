#pragma once
#include <iostream>
using namespace std;
#define fact 2

struct BTreeNode {
	int keys[2 * fact - 1];
	BTreeNode* children[2 * fact];
	int n;
	bool leaf;
};


struct BTree {
	BTreeNode* root;
};

BTreeNode* allocateNode(int leaf);
void createBTree(BTree* T);
void BTreeSplitChild(BTreeNode* x, int i);
void BTreeInsertIncomplete(BTreeNode* x, int k);
void BTreeInsert(BTree* T, int k);
void BTreeTraverseRec(BTreeNode *x);
void BTreeTraverse(BTreeNode *x);
BTreeNode* search(BTreeNode* x, int k);