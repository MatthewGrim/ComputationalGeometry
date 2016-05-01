/*
Author: Rohan Ramasamy
Data: 31/03/16

This file contains the code for a binary search tree.
*/

#pragma once

#include <utility>
#include <vector>

#include <iostream>

namespace compGeom {

namespace {

template<class key, class data>
class Node {
public:
	Node(key keyValue, data dataValue) : mLeftInitialised(false), mRightInitialised(false) {
		std::vector<data> tmpData = { dataValue };
		mKey = std::pair<key, std::vector<data> >(keyValue, tmpData);
	}

	key
	getKey() { return mKey.first; }

	std::vector<data>
	getData() { return mKey.second; }

	Node*
	right() { 
		if (mRightInitialised)	{ return mRight; }
		else { throw std::runtime_error("Null Pointer"); }
	}

	Node*
	left() { 
		if (mLeftInitialised) { return mLeft; }
		else { throw std::runtime_error("Null Pointer"); }
	}

	void
	setRight(Node* newPtr) { 
		if (!mRightInitialised) { mRightInitialised = true; }
		mRight = newPtr;
	}

	void
	setLeft(Node* newPtr) {
		if (!mLeftInitialised) { mLeftInitialised = true; }
		mLeft = newPtr;
	}

	void
	addData(data newData) { mKey.second.push_back(newData); }
private:
	std::pair<key, std::vector<data> > mKey;
	Node* mRight;
	Node* mLeft;
	bool mLeftInitialised;
	bool mRightInitialised;
};

}

}
