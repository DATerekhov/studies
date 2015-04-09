#include <iostream>
#include <fstream>
#include "BinTree.h"
using namespace std;

void main()
{
	setlocale(0, "");
	ifstream outputStream;

	BinTree *MyBinTree = new BinTree();
	Node *head = MyBinTree->ReadOutFile("data.txt", outputStream, MyBinTree);

	MyBinTree->PrintBinTree(head, 0);
	cout << endl;
	cout << "����������� ������: " << endl;
	MyBinTree->PreOrderWalk(head); cout << endl;
	cout << "����������� ��������: " << endl;
	MyBinTree->PostOrderWalk(head);	cout << endl;
	cout << "����������� ������������: " << endl;
	MyBinTree->InOrderWalk(head);	cout << endl;
	cout << "������������� ������ �����: " << endl;
	MyBinTree->Printic(head); cout << endl;
	cout << "�������� �����: " << endl;
	int val = 46;
	Node *tr = MyBinTree->Search(head, val);

	system("pause");
}

