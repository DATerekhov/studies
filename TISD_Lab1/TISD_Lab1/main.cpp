#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

void PrintMenu()
{
	cout << "�����: " << endl;
	cout << " ������� 1 ��� �������� ������ �� �����" << endl;
	cout << " ������� 2 ��� ��������� ���������� ������ ���� " << endl;
	cout << " ������� 3 ��� ������ ������ �� ����� " << endl;
	cout << " ������� 4 ��� ������ ���������� � ����" << endl;
	cout << " ������� 5 ��� ���������� �������� � ������" << endl;
	cout << " ������� 6 ��� ������ �������� � ������" << endl;
	cout << " ������� 7 ��� �������� ������" << endl;
	cout << " ������� 0 ��� ������ �� ���������" << endl;
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
		cout << "���������� ������ ����: " << (MyList->Calculate()) << endl;
		break;
	case 3:
		MyList->ShowAll();
		break;
	case 4:
		MyList->WriteListInFile(MyList->Calculate(), nameResultFile, nameErrorFile, inputStream);
		break;
	case 5:
		cout << "������� �������:" << endl;
		cin >> element;
		cout << "������� ������� ��� ����:" << endl;
		cin >> number;
		MyList->Insert(number, element);
		break;
	case 6:
		cout << "������� �������:" << endl;
		cin >> element;
		if (MyList->FindElement(element))
		{
			cout << "������� ���� � ������" << endl;
		}
		else { cout << "������� �����������" << endl; }
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