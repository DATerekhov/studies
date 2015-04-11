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

void ChooseCommand(int command, BinTree *MyBinTree, char* nameDataFile)
{
	int element;
	ifstream outputStream;
	int i = 0, j = 0, k = 0;
	int mas[30];
	int mas1[30];
	int mas2[30];
	Node *head = MyBinTree->ReadOutFile(nameDataFile, outputStream, MyBinTree);
	switch (command)
	{
	case 1:
		break;
	case 2:
		MyBinTree->PrintBinTree(head, 0);
		cout << endl;
		break;
	case 3:
		cout << "������� �������, �� �������� ������ ����� ����" << endl;
		cin >> element;

		cout << "������ ����� ������: " << endl;
		MyBinTree->PreOrderWalk(head); cout << endl;
		cout << "����: " << endl;
		MyBinTree->PreOrderSearch(head, *mas2);
		while (mas2[k] != element)
		{
			cout << mas2[k] << "  ";
			k++;
		}
		cout << endl;
		break;
	case 4:
		cout << "������� �������, �� �������� ������ ����� ����" << endl;
		cin >> element;

		cout << "�������� ����� ������: " << endl;
		MyBinTree->PostOrderWalk(head); cout << endl;
		cout << "����: " << endl;
		MyBinTree->PostOrderSearch(head, *mas);
		while (mas[i] != element)
		{
			cout << mas[i] << "  ";
			i++;
		}
		cout << endl;
		break;
	case 5:
		cout << "������� �������, �� �������� ������ ����� ����" << endl;
		cin >> element;

		cout << "������������ ����� ������: " << endl;
		MyBinTree->InOrderWalk(head); cout << endl;
		cout << "����: " << endl;
		MyBinTree->InOrderSearch(head, *mas1);
		while (mas1[j] != element)
		{
			cout << mas1[j] << "  ";
			j++;
		}
		cout << endl;
		break;
	}
}
void main(int count, char* arg[])
{
	setlocale(0, "");
	char* nameDataFile = arg[1];
	int command = 10;
	ifstream outputStream;

	BinTree *MyBinTree = new BinTree();

	while (command != 0)
	{
		PrintMenu();
		cin >> command;
		ChooseCommand(command, MyBinTree, "data.txt");
	}

	system("pause");
}