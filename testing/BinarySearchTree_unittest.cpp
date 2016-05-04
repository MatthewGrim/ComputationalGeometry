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

class BinarySearchTreeTest : public ::testing::Test {};

TEST_F(BinarySearchTreeTest, NodeTest) {
	Node<int, double> node1(1, 3.0);

	EXPECT_EQ(1, node1.getKey());
	EXPECT_EQ(3.0, node1.getData().at(0));

	node1.addData(2.0);
	EXPECT_EQ(3.0, node1.getData().at(0));
	EXPECT_EQ(2.0, node1.getData().at(1));
	EXPECT_ANY_THROW(node1.getData().at(2));

	std::vector<double> dataVector = { 3.0, 4.0 };
	node1.addData(dataVector);
	EXPECT_EQ(3.0, node1.getData().at(0));
	EXPECT_EQ(2.0, node1.getData().at(1));
	EXPECT_EQ(3.0, node1.getData().at(2));
	EXPECT_EQ(4.0, node1.getData().at(3));
	EXPECT_ANY_THROW(node1.getData().at(4));

	node1.setRight(Node<int, double>(3, 5.0));
	node1.setLeft(Node<int, double>(3, 5.0));

	EXPECT_EQ(3, node1.right()->getKey());
	EXPECT_EQ(5.0, node1.right()->getData().at(0));
	EXPECT_EQ(3, node1.left()->getKey());
	EXPECT_EQ(5.0, node1.left()->getData().at(0));
}

TEST_F(BinarySearchTreeTest, InsertionTest) {
	BinarySearchTree<double, double> bST(Node<double, double>(1.0, 5.0));

	Node<double, double> node1(-1.0, 5.0);
	Node<double, double> node2(-2.0, 4.0);
	Node<double, double> node3(2.0, 2.0);
	Node<double, double> node4(5.0, 5.0);

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
	BinarySearchTree<double, double> bST;

	Node<double, double> node1(-1.0, 5.0);
	Node<double, double> node2(-2.0, 4.0);
	Node<double, double> node3(2.0, 2.0);
	Node<double, double> node4(2.0, 4.0);
	Node<double, double> node5(3.0, 5.0);

	bST.insertNode(node1);
	bST.insertNode(node2);
	bST.insertNode(node3);
	bST.insertNode(node4);
	bST.insertNode(node5);

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
	BinarySearchTree<double, double> bST;

	Node<double, double> node1(-1.0, 5.0);
	Node<double, double> node2(-2.0, 4.0);
	Node<double, double> node3(2.0, 2.0);
	Node<double, double> node4(2.0, 4.0);
	Node<double, double> node5(3.0, 5.0);

	bST.insertNode(node1);
	bST.insertNode(node2);
	bST.insertNode(node3);
	bST.insertNode(node4);
	bST.insertNode(node5);

	EXPECT_TRUE(bST.search(-2.0));
	bST.deleteNode(-2.0);
	EXPECT_FALSE(bST.search(-2.0));

	EXPECT_TRUE(bST.search(2.0));
	bST.deleteNode(2.0);
	EXPECT_FALSE(bST.search(2.0));
	EXPECT_FALSE(bST.search(3.0));
}

}