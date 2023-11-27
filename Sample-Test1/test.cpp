#include "pch.h"
#include <iostream>
#include <cassert>
#include "../AVL/tree.h"

void testInsertion() {
	// ������� AVL-������
	Tree tree;

	// ��������� ��������
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);

	// ���������, ��� �������� ������������� ���������
	assert(tree.find(10));
	assert(tree.find(20));
	assert(tree.find(30));
	assert(tree.find(40));
	assert(tree.find(50));
}

void testDeletion() {
	// ������� AVL-������
	Tree tree;

	// ��������� ��������
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);

	// ������� �������
	tree.remove(30);

	// ���������, ��� ������� ��� ������, � ������ ��������
	assert(tree.search(10));
	assert(tree.search(20));
	assert(!tree.search(30)); // 30 ������ ���� ������
	assert(tree.search(40));
	assert(tree.search(50));
}

void testBalancing() {
	// ������� AVL-������
	 tree;

	// ��������� ��������
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);

	// ���������, ��� ������ AVL-������ ����� ������� - ��� 30
	assert(tree.getRoot()->value == 30);

	// ������� ������� � ���������, ��� ������ ������ 40
	tree.remove(10);
	assert(tree.getRoot()->value == 40);

	// ������� ��� ���� �������, �� ������ ������ �������� 40
	tree.remove(50);
	assert(tree.getRoot()->value == 40);
}

int main() {
	// ��������� �����
	testInsertion();
	testDeletion();
	testBalancing();

	// ��� ����� ������ �������
	std::cout � "All tests passed!" � std::endl;

	return 0;
}