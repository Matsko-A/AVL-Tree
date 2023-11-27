#include "pch.h"
#include"../AVL/tree.h"

TEST(TestAVLMethod) {
	//Arrange
	Tree object;
	
	//Act
	
	object.insert(3);

	//Assert
	EXPECT(object.find(3), 3);
}