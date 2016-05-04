/*
Author: Rohan Ramasamy
Data: 31/03/16

This file contains unit tests for BinarySearchTree
*/

// Linked Includes
#include "gtest/gtest.h"

// Project Includes
#include "../data/BinarySearchTree.h"

namespace compGeom {

class BinarySearchTreeTest : public ::testing::Test {
public:
	BinarySearchTree<double, double> bST;

	Node<double, double> node1;
	Node<double, double> node2;
	Node<double, double> node3;
	Node<double, double> node4;
	Node<double, double> node5;

	virtual void SetUp() {
		node1 = Node<double, double>(-1.0, 5.0);
		node2 = Node<double, double>(-2.0, 4.0);
		node3 = Node<double, double>(2.0, 2.0);
		node4 = Node<double, double>(2.0, 4.0);
		node5 = Node<double, double>(3.0, 5.0);

		bST.insertNode(node1);
		bST.insertNode(node2);
		bST.insertNode(node3);
		bST.insertNode(node4);
		bST.insertNode(node5);
	}

	virtual void TearDown() {

	}
};

TEST_F(BinarySearchTreeTest, NodeTest) {
	Node<int, double> testNode(1, 3.0);

	EXPECT_EQ(1, testNode.getKey());
	EXPECT_EQ(3.0, testNode.getData().at(0));

	testNode.addData(2.0);
	EXPECT_EQ(3.0, testNode.getData().at(0));
	EXPECT_EQ(2.0, testNode.getData().at(1));
	EXPECT_ANY_THROW(testNode.getData().at(2));

	std::vector<double> dataVector = { 3.0, 4.0 };
	testNode.addData(dataVector);
	EXPECT_EQ(3.0, testNode.getData().at(0));
	EXPECT_EQ(2.0, testNode.getData().at(1));
	EXPECT_EQ(3.0, testNode.getData().at(2));
	EXPECT_EQ(4.0, testNode.getData().at(3));
	EXPECT_ANY_THROW(testNode.getData().at(4));

	testNode.setRight(Node<int, double>(3, 5.0));
	testNode.setLeft(Node<int, double>(3, 5.0));

	EXPECT_EQ(3, testNode.right()->getKey());
	EXPECT_EQ(5.0, testNode.right()->getData().at(0));
	EXPECT_EQ(3, testNode.left()->getKey());
	EXPECT_EQ(5.0, testNode.left()->getData().at(0));
}

TEST_F(BinarySearchTreeTest, InsertionTest) {
	EXPECT_NO_THROW(bST.insertNode(node1));
	EXPECT_NO_THROW(bST.insertNode(node2));
	EXPECT_NO_THROW(bST.insertNode(node3));
	EXPECT_NO_THROW(bST.insertNode(node4));
	EXPECT_NO_THROW(bST.insertNode(node4));

	EXPECT_NO_THROW(bST.insertData(-1.0, 6.0));
	std::vector<double> newData = {3.0, 5.0};
	EXPECT_NO_THROW(bST.insertData(2.0, newData));
	EXPECT_ANY_THROW(bST.insertData(6.0, 2.0));
}

TEST_F(BinarySearchTreeTest, SearchTest) {
	EXPECT_TRUE(bST.search(-1.0));
	EXPECT_TRUE(bST.search(-2.0));
	EXPECT_TRUE(bST.search(2.0));
	EXPECT_TRUE(bST.search(3.0));
	EXPECT_FALSE(bST.search(6.0));

	EXPECT_EQ(5.0, bST.find(-1.0).at(0));
	EXPECT_EQ(4.0, bST.find(-2.0).at(0));
	EXPECT_EQ(2.0, bST.find(2.0).at(0));
	EXPECT_EQ(4.0, bST.find(2.0).at(1));
	EXPECT_EQ(5.0, bST.find(3.0).at(0));
	EXPECT_ANY_THROW(bST.find(3.0).at(1));
	EXPECT_ANY_THROW(bST.find(6.0));
}

TEST_F(BinarySearchTreeTest, DeletionTest) {
	EXPECT_TRUE(bST.search(-2.0));
	bST.deleteNode(-2.0);
	EXPECT_FALSE(bST.search(-2.0));

	EXPECT_TRUE(bST.search(2.0));
	bST.deleteNode(2.0);
	EXPECT_FALSE(bST.search(2.0));
	EXPECT_FALSE(bST.search(3.0));
}

}