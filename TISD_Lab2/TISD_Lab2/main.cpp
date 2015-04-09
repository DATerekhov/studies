#include <iostream>
#include <fstream>
#include "BinTree.h"
using namespace std;

void main()
{
	ifstream outputStream;

	BinTree *MyBinTree = new BinTree();
	Node *head = MyBinTree->ReadOutFile("data.txt", outputStream, MyBinTree);
		
	MyBinTree->PrintBinTree(head, 0);
	cout << endl;

	MyBinTree->PreOrderWalk(head);	cout << endl;
	MyBinTree->PostOrderWalk(head);	cout << endl;
	MyBinTree->InOrderWalk(head);	cout << endl;

	system("pause");
}