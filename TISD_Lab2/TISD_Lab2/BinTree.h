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
	Node *InsertNode(int);
	void PrintBinTree(Node *, int);
	Node *Search(Node *, int);
	void PreOrderWalk(Node *head);
	void PostOrderWalk(Node *head);
	void InOrderWalk(Node *head);
	Node *ReadOutFile(char*, ifstream&, BinTree*);
	virtual ~BinTree();
private:
	Node *head;
	int **Nodes;
	int CountOfNodes;
};

#endif

