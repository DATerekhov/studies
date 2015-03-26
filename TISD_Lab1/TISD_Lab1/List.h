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
	void ReadListOutFile(char* nameDataFile, char* nameErrorFile, ifstream &streamOut, ofstream &streamIn);
};

#endif
