/*
Author: Rohan Ramasamy
Data: 31/03/16

This file contains the code for a binary search tree.
*/

#pragma once

#include <utility>
#include <vector>
#include <cstddef>

#include <iostream>

namespace compGeom {

namespace {

template<class key, class data>
class Node {
public:
	Node(key keyValue,
		data dataValue) : mRight(nullptr), mLeft(nullptr) {
		std::vector<data> tmpData = { dataValue };
		mKey = std::pair<key, std::vector<data> >(keyValue, tmpData);
	}

	key
	getKey() const { return mKey.first; }

	std::vector<data>
	getData() const { return mKey.second; }

	Node*&
	right() { 
		return mRight;
	}

	Node*&
	left() { 
		return mLeft;
	}

	void
	setRight(const Node& newNode) {
		mRight = new Node(newNode);
	}

	void
	setLeft(const Node& newNode) {
		mLeft = new Node(newNode);
	}

	void
	addData(const data& newData) { mKey.second.push_back(newData); }

	void
	addData(const std::vector<data>& newDataVector) {
		for (auto newData : newDataVector) {
			mKey.second.push_back(newData);
		}
	}
private:
	std::pair<key, std::vector<data> > mKey;
	Node* mRight;
	Node* mLeft;
};

}

template<class key, class data>
class BinarySearchTree {
	typedef Node<key, data> Node;
public:
	BinarySearchTree() : mRoot(nullptr) {}

	BinarySearchTree(const key& rootKey,
		             const data& rootData) {
		mRoot = new Node(rootKey, rootData);
	}

	BinarySearchTree(Node rootNode) {
		mRoot = &rootNode;
	}

	void
	insert(const Node& newNode) {
		if (mRoot == NULL) {
			mRoot = new Node(newNode); 
		}
		else if (mRoot->getKey() > newNode.getKey()) {
			insert(mRoot->left(), newNode);
		}
		else if (mRoot->getKey() < newNode.getKey()) {
			insert(mRoot->right(), newNode);
		}
		else {
			mRoot->addData(newNode.getData());
		}
	}

	void
	insert(Node*& parentNode,
		   const Node& newNode) {
		if (parentNode == NULL) { parentNode = new Node(newNode); }
		else if (parentNode->getKey() > newNode.getKey()) {
			insert(parentNode->left(), newNode);
		}
		else if (parentNode->getKey() < newNode.getKey()) { 
			insert(parentNode->right(), newNode); 
		}
		else { parentNode->addData(newNode.getData()); }
	}

	bool
	search(const key& searchKey) const {
		if (mRoot == NULL) { return false; }
		else if (mRoot->getKey() > searchKey) {return search(mRoot->left(), searchKey); }
		else if (mRoot->getKey() < searchKey) {return search(mRoot->right(), searchKey); }
		else { return true; }
	}

	bool
	search(Node* node,
		   const key& searchKey) const {
		if (node == NULL) { return false; }
		else if (node->getKey() > searchKey) { return search(node->left(), searchKey); }
		else if (node->getKey() < searchKey) { return search(node->right(), searchKey); }
		else { return true; }
	}

	std::vector<data>
	find(const key& searchKey) const {
		if (mRoot == NULL) { throw std::runtime_error("Invalid Search Key"); }
		else if (mRoot->getKey() > searchKey) {return find(mRoot->left(), searchKey); }
		else if (mRoot->getKey() < searchKey) {return find(mRoot->right(), searchKey); }
		else { return mRoot->getData(); }
	}

	std::vector<data>
	find(Node* node,
		const key& searchKey) const {
		if (node == NULL) { throw std::runtime_error("Invalid Search Key"); }
		else if (node->getKey() > searchKey) {return find(node->left(), searchKey); }
		else if (node->getKey() < searchKey) {return find(node->right(), searchKey); }
		else { return node->getData(); }
	}

	// void
	// insertData(key searchKey,
	// 	       data newData);

	void
	deleteNode(Node*& node) {
		if (node == NULL) { }
		else {
			if (node->left()) { deleteNode(node->left()); }
			if (node->right()) { deleteNode(node->right()); }
			delete node;
			node = nullptr;
		}
	}

	void
	deleteNode(const key& searchKey) {
		if (mRoot == NULL) { }
		else if (mRoot->getKey() > searchKey) {deleteNode(mRoot->left(), searchKey); }
		else if (mRoot->getKey() < searchKey) {deleteNode(mRoot->right(), searchKey); }
		else { 
			deleteNode(mRoot->left());
			deleteNode(mRoot->right());
			delete mRoot;
			mRoot = nullptr;
		}
	}

	void
	deleteNode(Node*& node,
		       const key& searchKey) {
		if (node == NULL) { }
		else if (node->getKey() > searchKey) {deleteNode(node->left(), searchKey); }
		else if (node->getKey() < searchKey) {deleteNode(node->right(), searchKey); }
		else { 
			deleteNode(node->left());
			deleteNode(node->right());
			delete node;
			node = nullptr;
		}
	}
private:
	Node* mRoot;
};

}
