/*
Author: Rohan Ramasamy
Data: 31/03/16

This file contains the code for a binary search tree.
*/

#pragma once

// Standard includes
#include <utility>
#include <vector>
#include <cstddef>
#include <memory>

// Temporary Includes
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
	// Constructors
	BinarySearchTree() : mRoot(nullptr) {}

	BinarySearchTree(const key& rootKey,
		             const data& rootData) {
		mRoot = new Node(rootKey, rootData);
	}

	BinarySearchTree(Node rootNode) {
		mRoot = &rootNode;
	}

	/*
	@description: Inserts a new node into the binary search tree.
	@param newNode: node to be added to the binary search tree
	*/
	void
	insertNode(const Node& newNode) {
		if (mRoot == NULL) {
			mRoot = new Node(newNode); 
		}
		else if (mRoot->getKey() > newNode.getKey()) {
			insertNode(mRoot->left(), newNode);
		}
		else if (mRoot->getKey() < newNode.getKey()) {
			insertNode(mRoot->right(), newNode);
		}
		else {
			mRoot->addData(newNode.getData());
		}
	}

	/*
	@description: searches to see if a particular key exists within the binary search tree.
	@param searchKey: the key to be searched for within the tree.
	*/
	bool
	search(const key& searchKey) const {
		if (mRoot == NULL) { return false; }
		else if (mRoot->getKey() > searchKey) {return search(mRoot->left(), searchKey); }
		else if (mRoot->getKey() < searchKey) {return search(mRoot->right(), searchKey); }
		else { return true; }
	}

	/*
	@description: gets the data for a particular key value. It is assumed that the key is
				  known to exist and so the funtion throws an error if it does not.
	@param searchKey: the corresponding to the data being retrieved.
	*/
	std::vector<data>
	find(const key& searchKey) const {
		if (mRoot == NULL) { throw std::runtime_error("Invalid Search Key"); }
		else if (mRoot->getKey() > searchKey) {return find(mRoot->left(), searchKey); }
		else if (mRoot->getKey() < searchKey) {return find(mRoot->right(), searchKey); }
		else { return mRoot->getData(); }
	}

	/*
	@description: inserts additional data into an existing node.
	@param searchKey: the key for the node to be added to.
	@param newData: the singular data to be added to the node.
	*/
	void
	insertData(const key& searchKey,
		       const data& newData) {
		if (mRoot == NULL) { throw std::runtime_error("Invalid Search Key"); }
		else if (mRoot->getKey() > searchKey) {return insertData(mRoot->left(), searchKey, newData); }
		else if (mRoot->getKey() < searchKey) {return insertData(mRoot->right(), searchKey, newData); }
		else { return mRoot->addData(newData); }
	}

	/*
	@description: inserts additional data into an existing node.
	@param searchKey: the key for the node to be added to.
	@param newData: the vector of data to be added to the node.
	*/
	void
	insertData(const key& searchKey,
		       const std::vector<data>& newData) {
		if (mRoot == NULL) { throw std::runtime_error("Invalid Search Key"); }
		else if (mRoot->getKey() > searchKey) {return insertData(mRoot->left(), searchKey, newData); }
		else if (mRoot->getKey() < searchKey) {return insertData(mRoot->right(), searchKey, newData); }
		else { return mRoot->addData(newData); }
	}

	/*
	@description: removes a node and any existing children nodes from the data structure.
	@param searchKey: the key of the node to be deleted should it exist.
	*/
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

private:
	Node* mRoot;
	
	/*
	Private implementations of API functions that are used to act on children nodes within
	the data hierarchy of the binary search tree.
	*/
	void
	insertNode(Node*& parentNode,
		   const Node& newNode) {
		if (parentNode == NULL) { parentNode = new Node(newNode); }
		else if (parentNode->getKey() > newNode.getKey()) {
			insertNode(parentNode->left(), newNode);
		}
		else if (parentNode->getKey() < newNode.getKey()) { 
			insertNode(parentNode->right(), newNode); 
		}
		else { parentNode->addData(newNode.getData()); }
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
	find(Node* node,
		const key& searchKey) const {
		if (node == NULL) { throw std::runtime_error("Invalid Search Key"); }
		else if (node->getKey() > searchKey) {return find(node->left(), searchKey); }
		else if (node->getKey() < searchKey) {return find(node->right(), searchKey); }
		else { return node->getData(); }
	}

	void
	insertData(Node* node,
			   const key& searchKey,
		       const data& newData) {
		if (node == NULL) { throw std::runtime_error("Invalid Search Key"); }
		else if (node->getKey() > searchKey) {return insertData(node->left(), searchKey, newData); }
		else if (node->getKey() < searchKey) {return insertData(node->right(), searchKey, newData); }
		else { return node->addData(newData); }
	}

	void
	insertData(Node* node,
			   const key& searchKey,
		       const std::vector<data>& newData) {
		if (node == NULL) { throw std::runtime_error("Invalid Search Key"); }
		else if (node->getKey() > searchKey) {return insertData(node->left(), searchKey, newData); }
		else if (node->getKey() < searchKey) {return insertData(node->right(), searchKey, newData); }
		else { return node->addData(newData); }
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
};

}
