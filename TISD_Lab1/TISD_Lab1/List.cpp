#include "List.h"
#include <fstream>
#include <iostream>
using namespace std;

List::List(void)
{
	top = NULL;
}

List::List(ifstream& file)
{
	top = NULL;
	char inf;
	while (!file.eof())
	{
		file >> inf;
		PushBack(inf);
	}
}

void List::PushBack(char temp)
{
	if (top == NULL)
	{
		top = new Tlist;
		top->inf = temp;
		top->next = NULL;
	}
	else
	{
		Tlist *p = top;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Tlist;
		p->next->inf = temp;
		p->next->next = NULL;
	}
}

void List::Insert(int position, char temp)
{
	if (position == 1)
	{
		PushFront(temp);
	}
	if (position == GetLength() + 1)
	{
		PushBack(temp);
	}
	if (position > 1 && position < GetLength())
	{
		Tlist *tElem;
		Tlist *p = top;
		tElem = new Tlist;
		tElem->inf = temp;
		tElem->next = NULL;
		for (int i = 1; i <= position - 2; i++)
		{
			p = p->next;
		}
		tElem->next = p->next;
		p->next = tElem;
	}
}

void List::PushFront(char temp)
{
	Tlist *p = top;
	top = new Tlist;
	top->inf = temp;
	top->next = p;
}

bool List::FindNextElement(char element)
{
	Tlist *t = top;
	bool result = false;
	while ((!(result)) && (t != NULL))
	{
		if (t->inf == element)
		{
			result = true;
		}
		t = t->next;
	}
	return result;
}

int List::GetLength()
{
	int count = 0;
	Tlist *TElem;
	TElem = new Tlist;
	TElem = top;
	while (TElem != NULL)
	{
		count++;
		TElem = TElem->next;
	}
	return count;
}

void List::ShowAll()
{
	Tlist *p = top;
	while (p != NULL)
	{
		cout << p->inf;
		p = p->next;
	}
}

List::~List(void)
{
}

void List::DeleteList()
{
	Tlist *p = top;
	while (top != NULL)
	{
		top = top->next;
		delete p;
		p = top;
	}
}

void List::ReadListOutFile(char* nameDataFile, char* nameErrorFile, ifstream &streamOut, ofstream &streamIn)
{
	DeleteList();
	streamOut.open(nameDataFile);
	if (streamOut.is_open())
	{
		char buf;
		while (1)
		{
			streamOut >> buf;
			if (streamOut.eof())
			{
				streamOut.close();
				cout << "List has been read from file." << endl;
				return;
			}
			PushBack(buf);
		}
	}
	else
	{
		streamIn.open(nameErrorFile, ios::app);
		streamIn << "File with this name doesn't exist.Reading isn't possible." << endl;
		streamIn.close();
		cout << "File with this name doesn't exist.Reading isn't possible." << endl;
	}
}

int List::Calculate()
{
	Tlist *p = top;
	int counter = 0;
	while (p != NULL)
	{
		if (p->inf <= '9' && p->inf >= '1' && p->inf % 2 == 0)
			counter++;
		p = p->next;
	}
	return counter;
}

void List::WriteListInFile(int result, char* nameResultFile, char* nameErrorFile, ofstream &stream)
{
	stream.open(nameResultFile);
	if (stream.is_open())
	{
		/*Tlist *p = top;
		while (p != NULL)
		{
			stream << p->inf;
			p = p->next;
		}*/
		stream << result;
		cout << "List has been written in file." << endl;
		stream.close();
	}
	else
	{
		stream.open(nameErrorFile, ios::app);
		stream << "File with this name doesn't exist. Recording isn't possible." << endl;
		stream.close();
		cout << "File with this name doesn't exist. Recording isn't possible." << endl;
	}
}