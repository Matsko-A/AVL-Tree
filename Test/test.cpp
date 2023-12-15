#include "pch.h"
#include"../AVL/tree.h"
#include <string>

TEST(test, Testing_TEST) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(test_INT, InsertTest_INT) {
	Tree<int>* tree = new Tree<int>();
	tree->insert(3);

	ASSERT_TRUE(tree->find(3));
}

TEST(test_INT, RemoveTest_INT) {
	Tree<int>* tree = new Tree<int>();
	tree->insert(3);
	tree->remove(3);

	ASSERT_FALSE(tree->find(3));
}

TEST(test_INT, Size_Int_Success) {
	Tree<int>* tree = new Tree<int>();
	tree->insert(3);
	tree->insert(1);

	ASSERT_EQ( tree->height() , 1);
}


TEST(test_INT, FindTest_INT_True) {
	Tree<int>* tree = new Tree<int>();
	tree->insert(3);
	tree->insert(20);
	tree->insert(1);
	tree->insert(23);
	tree->insert(50);

	ASSERT_TRUE(tree->find(23));
}

TEST(test_INT, DisplayTest_INT) {
	Tree<int>* tree = new Tree<int>();
	tree->insert(3);
	tree->insert(23);
	tree->insert(50);

	ASSERT_EQ(tree->display(),"3 23 50 ");
}

TEST(test_DOBUBLE, InsertTest_DOBUBLE) {
	Tree<double>* tree = new Tree<double>();
	tree->insert(3.4);

	ASSERT_TRUE(tree->find(3.4));
}

TEST(test_DOBUBLE, RemoveTest_DOBUBLE) {
	Tree<double>* tree = new Tree<double>();
	tree->insert(2.1);
	tree->remove(2.1);

	ASSERT_FALSE(tree->find(2.1));
}

TEST(test_DOBUBLE, Size_Double_Success) {
	Tree<double>* tree = new Tree<double>();
	tree->insert(3.4);
	tree->insert(2.1);

	ASSERT_EQ(tree->height(), 1);
}

TEST(test_DOBUBLE, FindTest_DOBUBLE_True) {
	Tree<double>* tree = new Tree<double>();
	tree->insert(3.1);
	tree->insert(2.3);
	tree->insert(12.7);
	tree->insert(23.0);
	tree->insert(50.2);

	ASSERT_TRUE(tree->find(3.1));
}

TEST(test_DOBUBLE, DisplayTest_DOBUBLE) {
	Tree<double>* tree = new Tree<double>();
	tree->insert(3.4);
	tree->insert(12.7);
	tree->insert(23.2);

	ASSERT_EQ(tree->display(), "3.4 12.7 23.2 ");
}

TEST(test_STRING, InsertTest_STRING) {
	Tree<std::string>* tree = new Tree<std::string>();
	tree->insert("3.4");

	ASSERT_TRUE(tree->find("3.4"));
}

TEST(test_STRING, RemoveTest_STRING) {
	Tree<std::string>* tree = new Tree<std::string>();
	tree->insert("2");
	tree->remove("2");

	ASSERT_FALSE(tree->find("2"));
}

TEST(test_STRING, Size_String_Success) {
	Tree<std::string>* tree = new Tree<std::string>();
	tree->insert("3.4");
	tree->insert("2");

	ASSERT_EQ(tree->height(), 1);
}



TEST(test_STRING, FindTest_STRING_True) {
	Tree<std::string>* tree = new Tree<std::string>();
	tree->insert("3.1");
	tree->insert("2.3");
	tree->insert("12.7");
	tree->insert("23.0");
	tree->insert("50.2");

	ASSERT_TRUE(tree->find("12.7"));
}

TEST(test_STRING, DisplayTest_STRING) {
	Tree<std::string>* tree = new Tree<std::string>();
	tree->insert("3.4");
	tree->insert("3");
	tree->insert("2.3");

	ASSERT_EQ(tree->display(), "2.3 3 3.4 ");
}
