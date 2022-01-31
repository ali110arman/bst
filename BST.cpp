#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
};
node* root;
class BST {
public:
	BST();
	~BST();
	void insert(int);
	void remove(int);
	void display();
	void search(int);
private:
	node* makeEmpty(node*);
	node* insert(int, node*);
	node* findMin(node*);
	node* findMax(node*);
	node* remove(int, node*);
	void inorder(node*);
	node* find(node*, int);
};
BST::BST() {
	root = NULL;
}

BST::~BST() {
	root = makeEmpty(root);
}

void BST::insert(int x) {
	root = insert(x, root);
}

void BST::remove(int x) {
	root = remove(x, root);
}

void BST::display() {
	inorder(root);
	cout << endl;
}

void BST::search(int x) {
	root = find(root, x);
}

node* BST::makeEmpty(node* t) {
	if (t == NULL)
		return NULL;
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	return NULL;
}

node* BST::insert(int x, node* t) {
	if (t == NULL) {
		t = new node;
		t->data = x;
		t->left = t->right = NULL;
	}
	else if (x < t->data)
		t->left = insert(x, t->left);
	else if (x > t->data)
		t->right = insert(x, t->right);
	return t;
}

node* BST::findMin(node* t) {
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

node * BST::findMax(node * t) {
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	else
		return findMax(t->right);
}

node * BST::remove(int x, node * t) {
	node* temp;
	if (t == NULL)
		return NULL;
	else if (x < t->data)
		t->left = remove(x, t->left);
	else if (x > t->data)
		t->right = remove(x, t->right);
	else if (t->left && t->right) {
		temp = findMin(t->right);
		t->data = temp->data;
		t->right = remove(t->data, t->right);
	}
	else {
		temp = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		delete temp;
	}
	return t;
}

void BST::inorder(node * t) {
	if (t == NULL)
		return;
	inorder(t->left);
	cout << t->data << " ";
	inorder(t->right);
}

node* BST::find(node * t, int x) {
	if (t == NULL)
		return NULL;
	else if (x < t->data)
		return find(t->left, x);
	else if (x > t->data)
		return find(t->right, x);
	else
		return t;
}

int main() {
	BST t;
	t.insert(20);
	t.insert(25);
	t.insert(30);
	t.display();
	t.remove(20);
	t.display();
	t.remove(30);
	t.display();
	return 0;
}