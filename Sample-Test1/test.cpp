#include "pch.h"
#include <iostream>
#include <cassert>
#include "../AVL/tree.h"

void testInsertion() {
	// Создаем AVL-дерево
	Tree tree;

	// Вставляем элементы
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);

	// Проверяем, что элементы действительно вставлены
	assert(tree.find(10));
	assert(tree.find(20));
	assert(tree.find(30));
	assert(tree.find(40));
	assert(tree.find(50));
}

void testDeletion() {
	// Создаем AVL-дерево
	Tree tree;

	// Вставляем элементы
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);

	// Удаляем элемент
	tree.remove(30);

	// Проверяем, что элемент был удален, а другие остались
	assert(tree.search(10));
	assert(tree.search(20));
	assert(!tree.search(30)); // 30 должен быть удален
	assert(tree.search(40));
	assert(tree.search(50));
}

void testBalancing() {
	// Создаем AVL-дерево
	 tree;

	// Вставляем элементы
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);

	// Проверяем, что корень AVL-дерева после вставки - это 30
	assert(tree.getRoot()->value == 30);

	// Удаляем элемент и проверяем, что корень теперь 40
	tree.remove(10);
	assert(tree.getRoot()->value == 40);

	// Удаляем еще один элемент, но корень должен остаться 40
	tree.remove(50);
	assert(tree.getRoot()->value == 40);
}

int main() {
	// Запускаем тесты
	testInsertion();
	testDeletion();
	testBalancing();

	// Все тесты прошли успешно
	std::cout « "All tests passed!" « std::endl;

	return 0;
}