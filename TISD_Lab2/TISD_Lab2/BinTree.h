#ifndef _BinTree
#define _BinTree
#include <fstream>
using namespace std;

struct Node
{
	int inf;
	Node *left, *right, *parent;
};

class BinTree
{
public:
	BinTree();
	~BinTree();
	Node *InsertNode(int);
	void PrintBinTree(Node *, int);
	Node *BinSearch(Node *, int);
	void PreOrderWalk(Node *head);
	void PostOrderWalk(Node *head);
	void InOrderWalk(Node *head);
	void PreOrderSearch(Node *, int&);
	void PostOrderSearch(Node *, int&);
	void InOrderSearch(Node *, int&);
	Node *ReadOutFile(char*, ifstream&, BinTree*);
private:
	Node *head;
	int CountOfNodes;
};

#endif

