#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node* right, *left;
};

struct Comparator {
    bool operator()(const Node* x, const Node* y) 
    {
        return x->data > y->data;
    }
};

Node* createTree() 
{
    
    int n;
    cout << "Introdu numarul de frunze = ";
    cin >> n;

    int* v = new int[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    Node** nodes = new Node * [n];
    priority_queue <Node*, vector<Node*>, Comparator> min_heap;

    for (int i = 0; i < n; i++) 
    {
        nodes[i] = new Node;
        nodes[i]->left = nullptr;
        nodes[i]->right = nullptr;
        nodes[i]->data = v[i];
        min_heap.push(nodes[i]);
    }

    while (min_heap.size() > 1) 
    {
        Node* temp = new Node;
        Node* left = min_heap.top();
        min_heap.pop();

        Node* right = min_heap.top();
        min_heap.pop();

        temp->data = left->data + right->data;
        temp->left = left;
        temp->right = right;

        min_heap.push(temp);
    }

    delete[] v;
    return min_heap.top();
}

int LEP(Node* root)
{
    if (root != nullptr && (root->left != nullptr || root->right != nullptr)) 
        return (root->data + LEP(root->left) + LEP(root->right));
    else
        return 0;
}

void levelPrint(Node* root, int level)
{
    for (int i = 0; i < level; i++)
        cout << "\t";

    if (level != 0)
        cout << "-> ";
    if (root)
    {
        cout << root->data << endl;
        levelPrint(root->left, level + 1);
        levelPrint(root->right, level + 1);
    }
    else
        cout << "leaf" << endl;
}

void freeMemory(Node*& root)
{
    if (root)
    {
        freeMemory(root->left);
        freeMemory(root->right);
        delete root;
        root = nullptr;
    }
}

int main() 
{
    Node* Tree = createTree();

    levelPrint(Tree, 0);
    cout << "\nLEP " << LEP(Tree);

    freeMemory(Tree);
    cout << endl;
    return 0;
}