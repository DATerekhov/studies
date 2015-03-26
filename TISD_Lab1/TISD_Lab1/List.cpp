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
	else
	{
		int count = 1;
		Tlist *p = top;
		while (count != position - 1)
		{
			if (p->next == NULL)
			{
				p->next = new Tlist;
				p->next->next = NULL;
				p->next->inf = temp;
				return;
			}
			p = p->next;
		}
		Tlist *t = new Tlist;
		t->inf = temp;
		t->next = p->next;
		p->next = t;
	}
}

void List::PushFront(char temp)
{
	Tlist *p = top;
	top = new Tlist;
	top->inf = temp;
	top->next = p;
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
		if (p->inf <= '9' && p->inf % 2 == 0)
			counter++;
		p = p->next;
	}
	return counter;
}