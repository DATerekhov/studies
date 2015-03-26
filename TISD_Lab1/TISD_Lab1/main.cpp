#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

void PrintMenu()
{
	cout << "Выбор: " << endl;
	cout << " Нажмите 1 для создания списка" << endl;
	cout << " Нажмите 2 для получения результата умножения " << endl;
	cout << " Нажмите 3 для добавления элемента" << endl;
	cout << " Нажмите 4 для удаления элемента " << endl;
	cout << " Нажмите 5 для поиска элемента по позиции" << endl;
	cout << " Нажмите 6 для проверки списка на наличие элементов" << endl;
	cout << " Нажмите 0 для выхода из программы" << endl;
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
	system("pause");
}