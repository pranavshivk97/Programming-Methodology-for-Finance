#ifndef linkedList_pranav_h
#define linkedList_pranav_h

#include<string>

#include "node_pranav.h"

using namespace std;

class LinkedList
{
public:
	friend class Node;
	LinkedList();
	~LinkedList();
	void addtoStart(Node* );
	void addtoEnd(Node* newPtr);
	bool removefromStart();
	bool removefromEnd();
	void removeNodefromList(int);
	void removeNodefromList(string);
	void printList();

private:
	Node* myHead;
	Node* myTail;

	int mySize = 0;
};

#endif