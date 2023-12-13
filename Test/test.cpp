#include "pch.h"
#include"../AVL/tree.h"
#include <string>

TEST(test, Testing_TEST) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(test, InsertTest_INT) {
	Tree<int>* tree = new Tree<int>();
	tree->insert(3);

	ASSERT_TRUE(tree->find(3));
}

TEST(test, RemoveTest_INT) {
	Tree<int>* tree = new Tree<int>();
	tree->insert(3);
	tree->remove(3);

	ASSERT_FALSE(tree->find(3));
}

TEST(test, InsertTest_DOBUBLE) {
	Tree<double>* tree = new Tree<double>();
	tree->insert(3.4);

	ASSERT_TRUE(tree->find(3.4));
}

TEST(test, RemoveTest_DOBUBLE) {
	Tree<double>* tree = new Tree<double>();
	tree->insert(2.1);
	tree->remove(2.1);

	ASSERT_FALSE(tree->find(2.1));
}

TEST(test, InsertTest_STRING) {
	Tree<std::string>* tree = new Tree<std::string>();
	tree->insert("3.4");

	ASSERT_TRUE(tree->find("3.4"));
}

TEST(test, RemoveTest_STRING) {
	Tree<std::string>* tree = new Tree<std::string>();
	tree->insert("2");
	tree->remove("2");

	ASSERT_FALSE(tree->find("2"));
}
