#pragma once
#include <iostream>
#include "./binaryTrees.interface.h"

template <typename T>
class BinaryTree: public BinaryTreeInterface  {
private:
	T data;
	BinaryTree* left;
	BinaryTree* right;

public:
	BinaryTree() {
		left = right = nullptr;
	}
	BinaryTree(T v, BinaryTree* l = nullptr, BinaryTree* r = nullptr) {
		data = v; left = l; right = r;
	}
	~BinaryTree () {} 
	T& getValue () override  {
		return data;
	}
	void setValue (const T& v) override {
		data = v;
	}
	BinaryTree* getLeft () override  const {
		return left;
	}
	BinaryTree* getRight () override const {
		return right;
	}
	void setLeft (BinaryTree<T>* b) override {
		left = (BinaryTree*)b;
	}
	void setRight (BinaryTree<T>* b) override {
		right = (BinaryTree*)b;
	}
	bool isLeaf () override {
		return (left == nullptr) && (right == nullptr);
	}
	void printRange (BinaryTree<int>* root, int low, int high) override {
		if (root == nullptr)
			return;
		if (high < root -> getValue())
			printRange(root -> getLeft(), low, high);
		if (low <= root -> getValue() && high >= root -> getValue())
		{
			std :: cout << root -> getValue();
			std :: cout << " ";
		}
		if (high > root -> getValue())
			printRange(root -> getRight(), low, high);
	}
	bool search (BinaryTree<T>* root, T k) override {
		if (root == nullptr)
			return false;
		if (root -> getValue() == k)
			return true;
		return search(root -> getLeft(), k) && search(root -> getRight(), k);
	}
	int height (BinaryTree<T>* root) override {

		if (root == nullptr)
			return  0;
		return 1 + height(root -> getLeft);
		return 1 + height(root -> getRight);
	}
	int countLeaf (BinaryTree<T>* root) override {
		if (root == nullptr)
			return  0;
		if (root -> getLeft() == nullptr && root -> getRight() == nullptr)
			return 1;
		return countLeaf(root -> getLeft()) + countLeaf(root -> getRight());
	}
	int sumNode (BinaryTree<T>* root) override {
		if (root == nullptr)
			return 0;
		return sumNode(root -> getValue) + sumNode(root -> getLeft) + sumNode(root -> getRight);
	}
	void printMultipleOfK (BinaryTree<T>* root, int k) override {
		if (root == nullptr)
			return;
		if (root -> getValue() % k == 0) {
			cout << root -> getValue();
		    std :: cout << " ";
		}
		printMultipleOfK(root -> getLeft());
		printMultipleOfK(root -> getRight());
	}
	bool isBST (BinaryTree<T>* root) override {
		if (root == nullptr)
			return true;
		if (root -> getLeft -> getValue > root -> getValue && root -> getRight -> getValue < root -> getValue)
			return false;
		return isBST(root -> getLeft()) && isBST(root -> getRight());
	}
	bool isFull (BinaryTree<T>* root) override {
		if (root == nullptr)
			return true;
		if ((root -> getLeft() == nullptr && root -> getRight != nullptr) || (root -> getLeft() != nullptr && root -> getRight() == nullptr))
			return false;
		return isFull(root -> getLeft()) && isFull(root -> getRight());
	}
};