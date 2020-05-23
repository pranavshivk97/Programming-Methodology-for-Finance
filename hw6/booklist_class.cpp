/*Name: Pranav Shivkumar
Title: Booklist using Classes*/

#include<iostream>
#include<iomanip>

//Including the defined header file
#include "Booklist_lastname.h"

using namespace std;

booklist::booklist()
{
	n = 0;
	ele = 0;
	loc = 0;	//initializing a default constructor to predefine all values to 0
}

void booklist::insert(int arr[], int& n, int ele)
{
	cout << "Enter the element to be inserted in the list: ";
	cin >> ele;

	//Check if the array size is zero, as in the first case
	if (n == 0)
	{
		arr[0] = ele;
		n++;
	}

	else
	{
		int j = 0;

		while (j < n)
			j++;	//counter to count until the end of the array
		int loc = j;

		for (int i = n; i > n; i--)
			arr[i] = arr[i - 1];	//move all the array elements

		arr[loc] = ele;
		n++;
	}

	cout << "The updated list is: " << endl;
	print(arr, n);
	cout << endl << endl;
}

void booklist::insloc(int arr[], int& n, int loc, int ele)
{
	int i;
	cout << "Enter the position to enter the element: ";
	cin >> loc;

	if (loc < n)
	{
		cout << "Enter the element to be inserted: ";
		cin >> ele;

		n++;	//increase size of array to accomodate the extra element

		for (i = n; i > loc; i--)
			arr[i] = arr[i - 1];	//move all the array elements

		arr[loc] = ele;

		cout << "The updated list is: " << endl;
		print(arr, n);
		cout << endl << endl;
	}
	else
		cout << "Invalid position." << endl << endl;

	return;
}

int booklist::lin(int arr[], int& n, int ele)
{
	int i;
	int pos;


	for (i = 0; i < n; i++)
	{
		if (arr[i] == ele)	//searching for the element in the array
		{
			cout << "The element " << ele << " is found at position " << i << endl;
			pos = i;
			return pos;	//return the position to main
		}
	}
	return -1;
}

int booklist::bin(int arr[], int& n, int ele)
{
	int high = n - 1;	//max limit
	int low = 0;	//min limit
	int mid;

	bubsort(arr, n);	//sort the array if required

	cout << "Enter the ISBN number to be searched for: ";
	cin >> ele;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (ele == arr[mid])
		{
			cout << "The element " << ele << " is found at position " << mid << endl << endl;
			return mid;
		}
		else
			if (ele < arr[mid])
				high = mid - 1;
			else
				if (ele > arr[mid])
					low = mid + 1;
				else
					cout << "The element is not found." << endl << endl;
	}
}

void booklist::delloc(int arr[], int& n, int loc)
{

	for (int i = loc; i < n; i++)
		arr[i] = arr[i + 1];

	n--;
	cout << "The updated list is: " << endl << endl;
	print(arr, n);
}

void booklist::delnum(int arr[], int& n, int ele)
{
	int pos = lin(arr, n, ele);
	delloc(arr, n, pos);
}

void booklist::selsort(int* arr, int& n)
{
	int j;
	for (int i = 0; i < n - 1; i++)
	{
		int sm = i;
		for (j = i + 1; j < n; j++)
		{
			if (*(arr + j) < *(arr + sm))	//comparing smallest value with all elements of the list
			{
				int temp = *(arr + j);	//swapping the values
				*(arr + j) = *(arr + sm);
				*(arr + sm) = temp;
			}
		}

	}

	cout << "The sorted list is: " << endl;
	print(arr, n);
}

void booklist::bubsort(int* arr, int& n)
{
	int i;

	for (i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (*(arr + j) > * (arr + j + 1))	//search consecutive  elements 
			{
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
	
}

void booklist::print(int arr[], int &n)
{
	for (int i = 0; i < n; i++)	//print te array
		cout << setw(4) << i + 1 << ".\t" << arr[i] << endl;
}