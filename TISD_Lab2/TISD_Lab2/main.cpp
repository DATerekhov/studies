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
		cout << "Введите элемент, до которого хотите найти путь" << endl;
		cin >> element;

		cout << "Прямой обход дерева: " << endl;
		MyBinTree->PreOrderWalk(head); cout << endl;
		cout << "Путь: " << endl;
		MyBinTree->PreOrderSearch(head, *mas2);
		while (mas2[k] != element)
		{
			cout << mas2[k] << "  ";
			k++;
		}
		cout << endl;
		break;
	case 4:
		cout << "Введите элемент, до которого хотите найти путь" << endl;
		cin >> element;

		cout << "Обратный обход дерева: " << endl;
		MyBinTree->PostOrderWalk(head); cout << endl;
		cout << "Путь: " << endl;
		MyBinTree->PostOrderSearch(head, *mas);
		while (mas[i] != element)
		{
			cout << mas[i] << "  ";
			i++;
		}
		cout << endl;
		break;
	case 5:
		cout << "Введите элемент, до которого хотите найти путь" << endl;
		cin >> element;

		cout << "Симметричный обход дерева: " << endl;
		MyBinTree->InOrderWalk(head); cout << endl;
		cout << "Путь: " << endl;
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