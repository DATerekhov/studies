#include "BinTree.h"
#include <iostream>
#include <time.h>
using namespace std;

BinTree::BinTree(int temp)
{
	head = CreateBinTree(temp);
	CountOfNodes = temp;
	Nodes = new int *[temp];
	for (int i = 0; i < temp; i++)
	{
		Nodes[i] = new int[temp];
	}
	for (int i = 0; i < temp; i++)
	{
		for (int j = 0; j < temp; j++)
		{
			Nodes[i, j] = 0;
		}
	}
}
BinTree::BinTree()
{
}

BinTree::~BinTree()
{
}

Node *BinTree::CreateBinTree(int temp)
{
	int nl, nr;
	Node *head;
	if (temp > 0)
	{
		srand(time(NULL));
		nl = temp / 2;
		nr = temp - nl - 1;
		head = new Node;
		head->inf = rand() % 99 + 1;
		head->left = CreateBinTree(nl);
		head->right = CreateBinTree(nr);
	}
	else { head = NULL; }
	return head;
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
