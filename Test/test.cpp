#include "pch.h"
#include"../AVL/tree.cpp"

TEST(test, DefaultConstructorTest) {
	Tree t = Tree();

	ASSERT_EQ(nullptr, t.getRoot());
}

TEST(test, InsertTest) {
	Tree t;
	t.insert(3);

	ASSERT_TRUE(t.find(3));
}

TEST(test, RemoveTest) {
	Tree t;
	t.insert(3);
	t.remove(3);

	ASSERT_FALSE(t.find(3));
}

TEST(test, DeleteTest) {
	Tree t;
	t.insert(3);
	t.insert(6);
	t.insert(12);
	t.insert(1);
	t.del();

	ASSERT_EQ(nullptr, t.getRoot());
}