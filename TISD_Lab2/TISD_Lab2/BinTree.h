#ifndef _BinTree
#define _BinTree

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
	virtual ~BinTree();
private:
	Node *head;
	int **Nodes;
	int CountOfNodes;
};

#endif

