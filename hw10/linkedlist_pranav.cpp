#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

#include "linkedlist_pranav.h"

LinkedList::LinkedList()
{
	//empty body
}

//destructor

LinkedList::~LinkedList()
{
	//empty body for the destructor
}

void LinkedList::addtoStart(Node* newPtr)
{
	if (mySize == 0)
		myHead = myTail = newPtr;

	else
	{
		newPtr->next = myHead;
		myHead = newPtr;
	}

	mySize++;
}

void LinkedList::addtoEnd(Node* newPtr)
{
	if (mySize == 0) {
		myTail = myHead = newPtr;
	}
	else {
		myTail->next = newPtr;
		myTail = newPtr;
	}
	mySize++;

	
}

bool LinkedList::removefromStart()
{
	if (mySize == 0)
	{
		cout << "The list is empty." << endl << endl;
		return false;
	}

	else
	{
		if (myHead == myTail)
		{
			myHead = myTail = 0;
			mySize--;
		}

		else
		{
			myHead = myHead->next;
		}
		mySize--;

		return true;
	}
}

bool LinkedList::removefromEnd()
{
	if (mySize == 0)
	{
		cout << "The list is empty." << endl << endl;
		return false;
	}

	else
	{
		if (myHead == myTail)
		{
			myHead = myTail = 0;
			mySize--;
		}

		else
		{
			Node* current = myHead;
			while (current->next != myTail)
			{
				current = current->next;
			}

			myTail = current;
			current->next = 0;
			mySize--;
		}

		return true;
	}
}

void LinkedList::removeNodefromList(int number)
{
	if (mySize == 0)
	{
		cout << "The list is empty." << endl << endl;
	}

	else
	{
		Node* current = myHead;
		while (current != 0 && current->N != number)
		{
			current = current->next;
		}

		if (myHead == current && mySize != 1)
		{
			myHead->Name = myHead->next->Name;
			myHead->N = myHead->next->N;
			current = myHead->next;
			myHead->next = myHead->next->next;
			mySize--;
			return;
		}

		if (mySize == 1)
		{
			if (myHead->N == number)
			{
				myHead = myTail = 0;
				mySize--;
				cout << "The list is empty." << endl;
				return;
			}
		}

		Node* prev = myHead;

		while (prev->next != NULL && prev->next != current)
			prev = prev->next;

		if (prev->next == NULL)
		{
			cout << "The item is not found." << endl << endl;
			return;
		}

		prev->next = prev->next->next;
		mySize--;
	}
}

void LinkedList::removeNodefromList(string name)
{
	if (mySize == 0)
	{
		cout << "The list is empty." << endl << endl;
	}

	else
	{
		Node* current = myHead;
		while (current != 0 && current->Name.compare(name) != 0)
		{
			current = current->next;
		}

		if (myHead == current && mySize != 1)
		{
			myHead->Name = myHead->next->Name;
			myHead->N = myHead->next->N;
			current = myHead->next;
			myHead->next = myHead->next->next;
			mySize--;
			return;
		}

		if (mySize == 1)
		{
			if (myHead->Name == name)
			{
				myHead = myTail = 0;
				mySize--;
				cout << "The list is empty." << endl;
				return;
			}
		}

		Node* prev = myHead;

		while (prev->next != NULL && prev->next != current)
			prev = prev->next;

		if (prev->next == NULL)
		{
			cout << "The item is not found." << endl << endl;
			return;
		}

		prev->next = prev->next->next;
		mySize--;
	}
}

void LinkedList::printList()
{
	if (mySize > 0)
	{
		cout << "Printing the list...." << endl << endl;
		cout << "Your list is: " << endl << endl;
		cout << "Item Number" <<"  " << "Item Name" << endl;
		Node* current = myHead;
		while (current != nullptr)
		{
			cout << current->N << "        " << current->Name << endl;
			current = current->next;
		}
	}

	cout << endl;
}
