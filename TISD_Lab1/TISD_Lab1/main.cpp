#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

void PrintMenu()
{
	cout << "Выбор: " << endl;
	cout << " Нажмите 1 для создания списка из файла" << endl;
	cout << " Нажмите 2 для получения количества четных цифр " << endl;
	cout << " Нажмите 3 для добавления нового элемента" << endl;
	cout << " Нажмите 4 для получения длины данного списка" << endl;
	cout << " Нажмите 5 для удаления всего списка" << endl;
	cout << " Нажмите 6 для поиска элемента в списке" << endl;
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
	cout << (MyList->GetLength()) << endl;
	MyList->ShowAll();
	cout << (MyList->FindNextElement('4')) << endl;
	MyList->WriteListInFile(MyList->Calculate(),"result.txt", "error.txt", inputStream);
	system("pause");
}