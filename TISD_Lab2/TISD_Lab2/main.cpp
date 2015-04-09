#include <iostream>
#include <fstream>
#include "BinTree.h"
using namespace std;

void main()
{
	ifstream outputStream;
	ofstream inputStream;

	BinTree *MyBinTree = new BinTree();
	/*Node *head = temp->InsertNode(28);

	outputStream.open("data.txt");
	if (outputStream.is_open())
	{
		int buf;
		while (!outputStream.eof())
		{
			outputStream >> buf;
			temp->InsertNode(buf);
		}

		outputStream.close();
		cout << "Yeear!!" << endl;
	}*/

	Node *head = MyBinTree->ReadOutFile("data.txt", outputStream, MyBinTree);
		
	MyBinTree->PrintBinTree(head, 0);
	cout << endl;

	/*
	Node *value = temp->Search(head, (int)53);
	cout << value->inf << endl;
	temp->PreOrderWalk(head);	cout << endl;
	temp->PostOrderWalk(head);	cout << endl;
	temp->InOrderWalk(head);	cout << endl;*/


	system("pause");
}