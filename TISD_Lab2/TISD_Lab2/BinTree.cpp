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

Node *BinTree::Search(Node *head, int temp)
{
	while (head != NULL)
	{
		if (temp == head->inf)
			return head;
		head = (temp < head->inf ? head->left : head->right);
	}
}

void BinTree::PreOrderWalk(Node *head)
{
	if (head != NULL)
	{
		cout << head->inf << "\t";
		PreOrderWalk(head->left);
		PreOrderWalk(head->right);
	}
}

void BinTree::PostOrderWalk(Node *head)
{
	if (head != NULL)
	{
		PostOrderWalk(head->left);
		PostOrderWalk(head->right);
		cout << head->inf << "\t";
	}
}

void BinTree::InOrderWalk(Node * head)
{
	if (head != NULL)
	{
		InOrderWalk(head->left);
		cout << head->inf << "\t";
		InOrderWalk(head->right);
	}
}

Node *BinTree::ReadOutFile(char* dataFile, ifstream &outStream, BinTree *temp)
{
	outStream.open(dataFile);
	
	if (outStream.is_open())
	{
		int buf;
		outStream >> buf;
		Node *head = temp->InsertNode(buf);

		while (!outStream.eof())
		{
			outStream >> buf;
			temp->InsertNode(buf);
		}

		outStream.close();
		cout << "Yeear!!" << endl;
	}
	return head;
}
