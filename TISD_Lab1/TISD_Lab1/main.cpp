#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

void PrintMenu()
{
	cout << "�����: " << endl;
	cout << " ������� 1 ��� �������� ������ �� �����" << endl;
	cout << " ������� 2 ��� ��������� ���������� ������ ���� " << endl;
	cout << " ������� 3 ��� ���������� ������ ��������" << endl;
	cout << " ������� 4 ��� ��������� ����� ������� ������" << endl;
	cout << " ������� 5 ��� �������� ����� ������" << endl;
	cout << " ������� 6 ��� ������ �������� � ������" << endl;
	cout << " ������� 0 ��� ������ �� ���������" << endl;
}

void main(int count, char* arg[])
{
	setlocale(0, "");
	List *MyList = new List();
	
	ifstream outputStream;
	ofstream inputStream;
	MyList->ReadListOutFile("data.txt", "error.txt", outputStream, inputStream);
	MyList->ShowAll();
	cout << endl;
	cout << (MyList->Calculate()) << endl;
	cout << (MyList->GetLength()) << endl;
	MyList->ShowAll();
	cout << (MyList->FindNextElement('4')) << endl;
	MyList->WriteListInFile(MyList->Calculate(),"result.txt", "error.txt", inputStream);
	system("pause");
}