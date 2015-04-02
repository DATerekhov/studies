#include <iostream>
#include "BinTree.h"
using namespace std;

void main()
{
	BinTree *temp = new BinTree();
	Node *head = temp->InsertNode(28);
	temp->InsertNode(20);
	temp->InsertNode(34);
	temp->InsertNode(53);
	temp->InsertNode(29);
	temp->InsertNode(27);
	temp->InsertNode(11);
	temp->InsertNode(3);
	temp->PrintBinTree(head, 0);
	cout << endl;

	Node *value = temp->Search(head, (int)53);
	cout << value->inf;
	system("pause");
}