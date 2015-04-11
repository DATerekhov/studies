#include "BinTree.h"
#include <iostream>
#include <fstream>
using namespace std;

BinTree::BinTree()
{
}

BinTree::~BinTree()
{
}

void BinTree::PrintBinTree(Node *head, int temp)
{
	if (head != NULL)
	{
		PrintBinTree(head->right, temp + 2);
		for (int i = 1; i <= temp; i++)
		{
			cout << " ";
		}
		cout << head->inf << endl;
		PrintBinTree(head->left, temp + 2);
	}
}

Node *BinTree::InsertNode(int value)
{
	Node *x, *current, *parent;
	current = head;
	parent = NULL;
	while (current != NULL)
	{
		if (value == current->inf)
			return current;
		parent = current;
		current = (value < current->inf ? current->left : current->right);
	}
	x = new Node;
	x->inf = value;
	x->left = x->right = 0;
	x->parent = parent;
	if (parent != NULL)
	{
		if (x->inf < parent->inf)
		{
			parent->left = x;
		}
		else
		{
			parent->right = x;
		}
	}
	else head = x;
	return x;
	}

Node *BinTree::BinSearch(Node *head, int temp)
{
	while (head != NULL)
	{
		cout << head->inf << "\t";
		if (temp == head->inf)
			return head;
		head = (temp < head->inf ? head->left : head->right);
	}
}

void BinTree::PreOrderWalk(Node *head)
{
	if (head != NULL)
	{
		cout << head->inf << "  ";
		PreOrderWalk(head->left);
		PreOrderWalk(head->right);
	}
}

int BinTree::PreOrderSearch(Node *head, int temp)
{
	if ((head != NULL) && (head->inf != temp))
	{
		cout << head->inf << "  ";
		PreOrderSearch(head->left, temp);
		PreOrderSearch(head->right, temp);
	}
	return temp;
}

void BinTree::PostOrderWalk(Node *head)
{
	if (head != NULL)
	{
		PostOrderWalk(head->left);
		PostOrderWalk(head->right);
		cout << head->inf << "  ";
	}
}
int i = 0;
int j = 0;
void BinTree::PostOrderSearch(Node *head, int& mas)
{
	if (head != NULL)
	{
		PostOrderSearch(head->left, mas);
		PostOrderSearch(head->right, mas);
		(&mas)[i] = head->inf;
		i++;
	}
}

void BinTree::InOrderWalk(Node *head)
{
	if (head != NULL)
	{
		InOrderWalk(head->left);
		cout << head->inf << "  ";
		InOrderWalk(head->right);
	}
}

void BinTree::InOrderSearch(Node *head, int& mas)
{
	if (head != NULL)
	{
		InOrderSearch(head->left, mas);
		(&mas)[j] = head->inf;
		j++;
		InOrderSearch(head->right, mas);
	}
}

Node *BinTree::ReadOutFile(char* dataFile, ifstream &outStream, BinTree *tempTree)
{
	outStream.open(dataFile);

	if (outStream.is_open())
	{
		int buf;
		outStream >> buf;
		Node *head = tempTree->InsertNode(buf);

		while (!outStream.eof())
		{
			outStream >> buf;
			tempTree->InsertNode(buf);
		}

		outStream.close();
		cout << "Yeear!!" << endl;
	}
	return head;
}
/*
void BinTree::Printic(Node *dr)
{
	struct stek
	{
		Node *d;
		stek *s;
	} *st, *st1 = NULL;
	Node *dr1;
	dr1 = dr;
	int pr = 1, i = 0;
	for (i = 0; i<2; i++)
	{
		st = new stek[sizeof(stek)];
		st->d = dr1;
		st->s = st1;
		st1 = st;
	}
	cout << dr1->inf << "\t";
	while (st)
	{
		do
		{
			if (pr && dr1->left) dr1 = dr1->left;
			else if (dr1->right) dr1 = dr1->right;
			pr = 1;
			if (dr1->left && dr1->right)
			{
				st = new stek [sizeof(stek)];
				st->d = dr1;
				st->s = st1;
				st1 = st;
			}
			cout << dr1->inf << "\t";
		} while (dr1->left || dr1->right);
		dr1 = st->d;
		st1 = st->s;
		delete(st);
		st = st1;
		if (dr1->right) pr = 0;
	}
}*/