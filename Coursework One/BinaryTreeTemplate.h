// Coursework One - Binary Tree Template
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#pragma once
#include <iostream>
#include <cstddef>

using namespace std;

template <typename T>
struct node {
	T value;
	node* left, * right;
};

template <typename T>
class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	node<T>* getRoot();
	node<T>* newNode(T item);
	void insertNode(T item);
	node<T>* deleteNode(node<T>* tree, T item);
	node<T>* minValueSearch(node<T>* tree);
	void inOrder(node<T>* tree);
	void preOrder(node<T>* tree);
	void postOrder(node<T>* tree);
protected:
	node<T>* root;
};

template <typename T>
BinaryTree<T>::BinaryTree() :
	root(nullptr) {
	static_assert(is_same<T, unsigned int>::value || is_same<T, int>::value || is_same<T, float>::value || is_same<T, double>::value, "Binary Tree Template must be of type <float>, <int>, <unsigned int> or <double>.");
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
	delete root;
}

template <typename T>
node<T>* BinaryTree<T>::getRoot() {
	return root;
}

template <typename T>
node<T>* BinaryTree<T>::newNode(T item) {
	node<T>* branch = new node<T>;
	branch->left = branch->right = nullptr;
	branch->value = item;
	return branch;
}

template <typename T>
void BinaryTree<T>::insertNode(T item) {
	if (root == nullptr) {
		root = newNode(item);
	}
	else {
		node<T>* parent = new node<T>;
		node<T>* child = root;

		while (child != nullptr) {
			parent = child;
			child = (item > child->value) ? child->right : child->left;
		}

		if (item < parent->value) {
			parent->left = newNode(item);
		}
		else {
			parent->right = newNode(item);
		}
	}
}

template <typename T>
node<T>* BinaryTree<T>::deleteNode(node<T>* tree, T item) {
	if (tree == nullptr) {
		return tree;
	}

	if (item > tree->value) {
		tree->right = deleteNode(tree->right, item);
	}
	else if (item < tree->value) {
		tree->left = deleteNode(tree->left, item);
	}
	else {
		if (tree->left == nullptr) {
			node<T>* temp = tree->right;
			free(tree);
			return temp;
		}
		else if (tree->right == nullptr) {
			node<T>* temp = tree->left;
			free(tree);
			return temp;
		}

		node<T>* temp = minValueSearch(tree->right);
		tree->value = temp->value;
		tree->right = deleteNode(tree->right, temp->value);
	}
	return tree;
}

template <typename T>
node<T>* BinaryTree<T>::minValueSearch(node<T>* tree) {
	node<T>* current = tree;
	while (current && current->left != nullptr) {
		current = current->left;
	}
	return current;
}

template <typename T>
void BinaryTree<T>::inOrder(node<T>* tree) {
	if (tree != nullptr) {
		inOrder(tree->left);
		cout << tree->value << endl;
		inOrder(tree->right);
	}
}

template <typename T>
void BinaryTree<T>::preOrder(node<T>* tree) {
	if (tree != nullptr) {
		cout << tree->value << endl;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <typename T>
void BinaryTree<T>::postOrder(node<T>* tree) {
	if (tree != nullptr) {
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->value << endl;
	}
}