#include <iostream>
#include <fstream>
#include "BinTree.h"
using namespace std;

void PrintMenu()
{
	cout << "�����: " << endl;
	cout << " ������� 1 ��� ��������� ������" << endl;
	cout << " ������� 2 ��� ������ ������ �� �����" << endl;
	cout << " ������� 3 ��� ������� ������ � ������ ����" << endl;
	cout << " ������� 4 ��� ��������� ������ � ������ ����" << endl;
	cout << " ������� 5 ��� ������������� ������ � ������ ����" << endl;
	cout << " ������� 0 ��� ������ �� ���������" << endl;
}

void ChooseCommand(int command, BinTree *MyBinTree, Node *head)
{
	int element;
	int i = 0;
	int j = 0;
	int *mas = new int[];
	int *mas1 = new int[];
	switch (command)
	{
	case 1:
		break;
	case 2:
		MyBinTree->PrintBinTree(head, 0);
		cout << endl;
		break;
	case 3:
		cout << "������ ����� ������: " << endl;
		MyBinTree->PreOrderWalk(head); cout << endl;

		cout << "������� �������, �� �������� ������ ����� ����" << endl;
		cin >> element;
		cout << MyBinTree->PreOrderSearch(head, element) << endl;
		break;
	case 4:
		cout << "������� �������, �� �������� ������ ����� ����" << endl;
		cin >> element;

		cout << "�������� ����� ������: " << endl;
		MyBinTree->PostOrderWalk(head); cout << endl;

		MyBinTree->PostOrderSearch(head, *mas);
		while (mas[i] != element)
		{
			cout << mas[i] << "  ";
			i++;
		}
		break;
	case 5:
		cout << "������� �������, �� �������� ������ ����� ����" << endl;
		cin >> element;

		cout << "������������ ����� ������: " << endl;
		MyBinTree->InOrderWalk(head); cout << endl;

		MyBinTree->InOrderSearch(head, *mas1);
		while (mas1[j] != element)
		{
			cout << mas1[j] << "  ";
			j++;
		}
		break;
	}
}
void main(int count, char* arg[])
{
	setlocale(0, "");
	char* nameDataFile = arg[1];
	int command = 10;
	ifstream outputStream;
	ofstream inputStream;
	BinTree *MyBinTree = new BinTree();
	Node *head = MyBinTree->ReadOutFile("data.txt", outputStream, MyBinTree);
	while (command != 0)
	{
		PrintMenu();
		cin >> command;
		ChooseCommand(command, MyBinTree, head);
	}

	system("pause");
}