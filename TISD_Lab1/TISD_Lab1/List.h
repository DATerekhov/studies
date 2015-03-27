#ifndef _List
#define _List
#include <fstream>
using namespace std;

class List
{
	struct Tlist
	{
		char inf;
		Tlist *next;
	};
private:
	Tlist *top;
public:
	List(void);
	List(ifstream&);
	virtual ~List(void);
	void PushBack(char);
	void Insert(int, char);
	void PushFront(char);
	void ShowAll();
	int GetLength();
	void DeleteList();
	int Calculate();
	bool FindNextElement(char);
	void ReadListOutFile(char*, char*, ifstream &, ofstream &);
	void WriteListInFile(int, char*, char*, ofstream &);
};

#endif
