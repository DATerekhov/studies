#include <iostream>
#include "BinTree.h"
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));
	BinTree *temp = new BinTree(8);
	Node *node = temp->InsertNode(125);
	temp->InsertNode(101);
	temp->InsertNode(45);
	temp->InsertNode(47);
	temp->InsertNode(134);
	temp->InsertNode(100);
	temp->InsertNode(97);
	temp->InsertNode(7);
	temp->PrintBinTree(node, 0);
	system("pause");
}