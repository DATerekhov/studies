#include "BinTree.h"
#include <iostream>
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

	/*if ((int)head->inf != temp)
	{
		if ((int)temp > head->inf)
		{
			Search(head->right, temp);
		}
		if ((int)temp < head->inf)
		{
			Search(head->left, temp);
		}
	}
	else{
		return head;
	}*/

	while (head != NULL)
	{
		if (temp == head->inf)
			return head;
		head = (temp < head->inf ? head->left : head->right);
	}
}
