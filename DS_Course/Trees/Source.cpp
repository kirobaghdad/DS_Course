#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree<int> BT;

	BT.addNode(4, BT.getRoot());
	
	BT.addNode(3, BT.getRoot());
	BT.addNode(1, BT.getRoot());
	BT.addNode(0, BT.getRoot());
	BT.addNode(19, BT .getRoot());
	BT.addNode(5, BT.getRoot());

	BT.printPreOrderTraversal(BT.getRoot());
}