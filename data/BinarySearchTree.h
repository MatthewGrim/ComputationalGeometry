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
	getKey() { return mKey.first; }

	std::vector<data>
	getData() { return mKey.second; }

	Node*
	right() { 
		return mRight;
	}

	Node*
	left() { 
		return mLeft;
	}

	void
	setRight(Node* newPtr) {
		mRight = newPtr;
	}

	void
	setLeft(Node* newPtr) {
		mLeft = newPtr;
	}

	void
	addData(data newData) { mKey.second.push_back(newData); }

	void
	addData(std::vector<data> newDataVector) {
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

	BinarySearchTree(key rootKey, data rootData) {
		mRoot = new Node(rootKey, rootData);
	}

	BinarySearchTree(Node rootNode) {
		mRoot = &rootNode;
	}

	void
	insert(Node& newNode) {
		if (mRoot == NULL) {
			mRoot = &newNode; 
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
	insert(Node* parentNode,
		   Node& newNode) {
		if (parentNode == NULL) {
		    parentNode = &newNode; 
		}
		else if (parentNode->getKey() > newNode.getKey()) {
			insert(parentNode->left(), newNode);
		}
		else if (parentNode->getKey() < newNode.getKey()) {
			insert(parentNode->right(), newNode);
		}
		else {
			parentNode->addData(newNode.getData());
		}
	}

	bool
	search(key searchKey) {
		if (mRoot == NULL) { return false; }
		else if (mRoot->getKey() > searchKey) { search(mRoot->left(), searchKey); }
		else if (mRoot->getKey() < searchKey) { search(mRoot->right(), searchKey); }
		else { return true; }
	}

	bool
	search(Node* node,
		   key searchKey) {
		if (node == NULL) { return false; }
		else if (node->getKey() > searchKey) { search(node->left(), searchKey); }
		else if (node->getKey() < searchKey) { search(node->right(), searchKey); }
		else { return true; }
	}

	// void
	// insertData(key searchKey,
	// 	       data newData);

	// void
	// delete(key searchKey);
private:
	Node* mRoot;
};

}
