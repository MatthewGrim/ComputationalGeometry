/*
Author: Rohan Ramasamy
Data: 31/03/16

This file contains unit tests for BinarySearchTree
*/

// Linked Includes
#include "gtest/gtest.h"

#include <iostream>

// Project Includes
#include "../data/BinarySearchTree.h"

namespace compGeom {

class BinarySearchTreeTest : public ::testing::Test {};

TEST_F(BinarySearchTreeTest, NodeTest) {
	Node<int, double> node1(1, 3.0);

	EXPECT_EQ(1, node1.getKey());
	EXPECT_EQ(3.0, node1.getData().at(0));

	EXPECT_ANY_THROW(node1.right());
	EXPECT_ANY_THROW(node1.left());

	node1.addData(2.0);
	EXPECT_EQ(3.0, node1.getData().at(0));
	EXPECT_EQ(2.0, node1.getData().at(1));
	EXPECT_ANY_THROW(node1.getData().at(2));

	Node<int, double>* rightPtr = new Node<int, double>(3, 5.0);
	Node<int, double>* leftPtr = new Node<int, double>(3, 5.0);

	node1.setRight(rightPtr);
	node1.setLeft(leftPtr);

	EXPECT_EQ(3, node1.right()->getKey());
	EXPECT_EQ(5.0, node1.right()->getData().at(0));
	EXPECT_EQ(3, node1.left()->getKey());
	EXPECT_EQ(5.0, node1.left()->getData().at(0));
}

// TEST_F(BinarySearchTreeTest, InsertionTest) {
// 	BinarySearchTree<double, double> bST();

// 	EXPECT_NO_THROW(bST.insert(5));
// 	EXPECT_NO_THROW(bST.insert(1));
// 	EXPECT_NO_THROW(bST.insert(3));
// 	EXPECT_NO_THROW(bST.insert(9));
// }

// TEST_F(BinarySearchTreeTest, SearchTest) {
// 	BinarySearchTree<int, int> bST();

// 	bST.insert(std::pair<int, int>(5, 3));
// 	bST.insert(1);
// 	bST.insert(4);

// 	EXPECT_TRUE(bST.search(5));
// 	EXPECT_FALSE(bST.search(0));

// 	EXPECT_EQ(3, bST.find(5));
// }

// TEST_F(BinarySearchTreeTest, DeletionTest) {
// 	BinarySearchTree<int, int> bST();

// 	bST.insert(std::pair<int, int>(5, 3));
// 	bST.insert(1);
// 	bST.insert(4);

// 	EXPECT_TRUE(bST.search(5));

// 	bST.delete(5);

// 	EXPECT_FALSE(bST.search(5));

// 	EXPECT_ANY_THROW(bST.delete(5));
// }

}