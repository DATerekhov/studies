#include <iostream>
#include <fstream>
#include "BinTree.h"
using namespace std;

void PrintMenu()
{
	cout << "Выбор: " << endl;
	cout << " Нажмите 1 для генерации дерева" << endl;
	cout << " Нажмите 2 для вывода дерева на экран" << endl;
	cout << " Нажмите 3 для Прямого обхода и Поиска узла" << endl;
	cout << " Нажмите 4 для Обратного обхода и Поиска узла" << endl;
	cout << " Нажмите 5 для Симметричного обхода и Поиска узла" << endl;
	cout << " Нажмите 0 для выхода из программы" << endl;
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
		cout << "Прямой обход дерева: " << endl;
		MyBinTree->PreOrderWalk(head); cout << endl;

		cout << "Введите элемент, до которого хотите найти путь" << endl;
		cin >> element;
		cout << MyBinTree->PreOrderSearch(head, element) << endl;
		break;
	case 4:
		cout << "Введите элемент, до которого хотите найти путь" << endl;
		cin >> element;

		cout << "Обратный обход дерева: " << endl;
		MyBinTree->PostOrderWalk(head); cout << endl;

		MyBinTree->PostOrderSearch(head, *mas);
		while (mas[i] != element)
		{
			cout << mas[i] << "  ";
			i++;
		}
		break;
	case 5:
		cout << "Введите элемент, до которого хотите найти путь" << endl;
		cin >> element;

		cout << "Симметричный обход дерева: " << endl;
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