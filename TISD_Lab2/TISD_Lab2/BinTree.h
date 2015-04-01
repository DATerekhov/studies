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
	BinTree(int);
	Node *CreateBinTree(int);
	Node *InsertNode(int);
	void PrintBinTree(Node *, int);
	void PrintByNode();
	~BinTree();
private:
	Node *head;
	int **Nodes;
	int CountOfNodes;
};

#endif

