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
	cout << "Рекурсивный прямой: " << endl;
	MyBinTree->PreOrderWalk(head); cout << endl;
	cout << "Рекурсивный обратный: " << endl;
	MyBinTree->PostOrderWalk(head);	cout << endl;
	cout << "Рекурсивный симметричный: " << endl;
	MyBinTree->InOrderWalk(head);	cout << endl;
	cout << "НЕрекурсивный прямой обход: " << endl;
	MyBinTree->Printic(head); cout << endl;
	cout << "Бинарный поиск: " << endl;
	int val = 46;
	Node *tr = MyBinTree->Search(head, val);

	system("pause");
}

