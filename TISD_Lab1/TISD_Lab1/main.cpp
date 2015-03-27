#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

void PrintMenu()
{
	cout << "Выбор: " << endl;
	cout << " Нажмите 1 для создания списка из файла" << endl;
	cout << " Нажмите 2 для получения количества четных цифр " << endl;
	cout << " Нажмите 3 для вывода списка на экран " << endl;
	cout << " Нажмите 4 для записи результата в файл" << endl;
	cout << " Нажмите 5 для добавления элемента в список" << endl;
	cout << " Нажмите 6 для поиска элемента в списке" << endl;
	cout << " Нажмите 7 для удаления списка" << endl;
	cout << " Нажмите 0 для выхода из программы" << endl;
}

void ChooseCommand(int command, List *MyList, char* nameDataFile, char* nameResultFile, char* nameErrorFile)
{
	ifstream outputStream;
	ofstream inputStream;
	int number;
	char element;
	switch (command)
	{
	case 1:
		MyList->ReadListOutFile(nameDataFile, nameErrorFile, outputStream, inputStream);
		break;
	case 2:
		cout << "Количество четных цифр: " << (MyList->Calculate()) << endl;
		break;
	case 3:
		MyList->ShowAll();
		break;
	case 4:
		MyList->WriteListInFile(MyList->Calculate(), nameResultFile, nameErrorFile, inputStream);
		break;
	case 5:
		cout << "Введите элемент:" << endl;
		cin >> element;
		cout << "Введите позицию для него:" << endl;
		cin >> number;
		MyList->Insert(number, element);
		break;
	case 6:
		cout << "Введите элемент:" << endl;
		cin >> element;
		if (MyList->FindElement(element))
		{
			cout << "Элемент есть в списке" << endl;
		}
		else { cout << "Элемент отсутствует" << endl; }
		break;
	case 7:
		MyList->DeleteList();
		break;
	}
}

void main(int count, char* arg[])
{
	setlocale(0, "");
	List *MyList = new List();
	int command = 10;
	char* nameDataFile = arg[1];
	char* nameResultFile = arg[2];
	char* nameErrorFile = arg[3];
	char element;
	int number;
	ifstream outputStream;
	ofstream inputStream;
	while (command != 0)
	{
		PrintMenu();
		cin >> command;
		ChooseCommand(command, MyList, nameDataFile, nameResultFile, nameErrorFile);
	}
	cout << endl;
	system("pause");
}