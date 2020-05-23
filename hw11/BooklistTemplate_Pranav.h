#pragma once
#ifndef BooklistTemplate_Pranav_h
#define BooklistTemplate_Pranav_h

#include<iostream>
#include<iomanip>
using namespace std;

template <class B>
class Booklist
{
public:
	//declaring all member functions of the class

	Booklist(B arr[20], int n); //declaring a default constructor
	void insert(B arr[], int& n, B ele);
	void insloc(B arr[], int& n, int loc, B ele);
	int lin(B arr[], int& n, B ele);
	int bin(B arr[], int& n, B ele);
	void delloc(B arr[], int& n, int loc);
	void delnum(B arr[], int& n, B ele);
	void selsort(B arr[], int& n);
	void bubsort(B arr[], int& n);
	void print(B arr[], int& n);

	bool arrsort(B arr[], int& n); //member function that checks if the list is sorted or not

private:
	int n, loc;
	B arr[20];
	B ele;

};

template<class B>
Booklist<B>::Booklist(B arr[20], int n)
{
	n = loc = 0;

	for (int i = 0; i < 20; i++)
		arr[i] = { 0 };
}

template <class B>
void Booklist<B>::insert(B arr[], int& n, B ele)
{
	cout << "Enter the element to be inserted in the list: ";
	cin >> ele;
	arr[n] = ele;
	n++;

	cout << "The updated list is: " << endl;
	print(arr, n);
	cout << endl << endl;
}

template <class B>
void Booklist<B>::insloc(B arr[], int& n, int loc, B ele)
{
	int i;
	cout << "Enter the position to enter the element: ";
	cin >> loc;

	if (loc < n)
	{
		cout << "Enter the element to be inserted: ";
		cin >> ele;

		n++; //increase size of array to accomodate the extra element

		for (i = n; i > loc - 1; i--)
			arr[i] = arr[i - 1]; //move all the array elements

		arr[loc - 1] = ele;

		cout << "The updated list is: " << endl;
		print(arr, n);
		cout << endl << endl;
	}
	else
		cout << "Invalid position." << endl << endl;

	return;
}

template <class B>
int Booklist<B>::lin(B arr[], int& n, B ele)
{
	int i;
	int pos;

	for (i = 0; i < n; i++)
	{
		if (arr[i] == ele) //searching for the element in the array
		{
			cout << "The element " << ele << " is found at position " << i + 1 << endl;
			pos = i + 1;
			return pos; //return the position to main
		}

		else
			pos = -1;
	}

	if (pos == -1)
		cout << "Not found in list" << endl << endl;

	return -1;
}

template <class B>
int Booklist<B>::bin(B arr[], int& n, B ele)
{
	int high = n - 1; //max limit
	int low = 0; //min limit
	int mid;
	int l = n;

	cout << "Enter the string to be searched for: ";
	cin >> ele;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ele == arr[mid])
			return mid;

		else if (ele < arr[mid])
			high = mid - 1;
		else if (ele > arr[mid])
			low = mid + 1;

	}

	return -1;
}

template <class B>
void Booklist<B>::delloc(B arr[], int& n, int loc)
{
	if (loc > n)
		cout << "Invalid position" << endl << endl;
	else
	{
		for (int i = loc - 1; i < n; i++)
			arr[i] = arr[i + 1];

		n--;
		cout << "The updated list is: " << endl << endl;
		print(arr, n);
	}
}

template <class B>
void Booklist<B>::delnum(B arr[], int& n, B ele)
{
	int pos = lin(arr, n, ele);

	if (pos == -1)
		return;
	else
		delloc(arr, n, pos);
}

template <class B>
void Booklist<B>::selsort(B arr[], int& n)
{
	B temp;

	for (int i = 0; i < n - 1; i++)
	{
		int sm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[sm]) //comparing smallest value with all elements of the list
			{
				temp = arr[j]; //swapping the values
				arr[j] = arr[sm];
				arr[sm] = temp;
			}
		}
	}

	cout << "The sorted list is: " << endl;
	print(arr, n);
}

template <class B>
void Booklist<B>::bubsort(B arr[], int& n)
{
	B temp;

	if (arrsort(arr, n))
		cout << "The array is already sorted" << endl;

	else
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
			{
				if (arr[j] > arr[j + 1]) //search consecutive  elements
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}

template <class B>
void Booklist<B>::print(B arr[], int& n)
{
	for (int i = 0; i < n; i++) //print te array
		cout << setw(4) << i + 1 << ".\t" << arr[i] << endl;
}

template <class B>
bool Booklist<B>::arrsort(B arr[], int& n)
{
	if (n == 1 || n == 0)
		return true;

	for (int i = 1; i < n; i++)
		if (arr[i - 1] > arr[i])
			return false;

	return true;
}

#endif