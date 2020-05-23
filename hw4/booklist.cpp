/*Name: Pranav Shivkumar
Title: Book List*/

#include<iostream>
#include<iomanip>

using namespace std;

int a[20];

//Function Prototypes
void insert(int a[], int &n, int ele);
void insloc(int a[], int &n, int loc, int ele);
int lin(int a[], int &n, int ele);
int bin(int a[], int &n, int ele);
void delloc(int a[], int &n, int loc);
void delnum(int a[], int &n, int ele);
void selsort(int *a, int &n);
void bubsort(int *a, int &n);
void print(int a[], int &n);

void insert(int a[], int &n, int ele)
{
	cout << "Enter the element to be inserted in the list: ";
	cin >> ele;

	//Check if the array size is zero, as in the first case
	if (n == 0)
	{
		a[0] = ele;
		n++;
	}
	else
	{
		int j = 0;

		while (j < n)
			j++;	//counter to count until the end of the array
		int loc = j;
		 
		for (int i = n; i > n; i--)
			a[i] = a[i - 1];	//move all the array elements

		a[loc] = ele;
		n++;
	}

	cout << "The updated list is: " << endl;
	print(a, n);
	cout << endl << endl;
}

void insloc(int a[], int &n, int loc, int ele)
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
			a[i] = a[i - 1];	//move all the array elements

		a[loc] = ele;

		cout << "The updated list is: " << endl;
		print(a, n);
		cout << endl << endl;
	}
	else
		cout << "Invalid position." << endl << endl;
	
	return;
}

int lin(int a[], int &n, int ele)
{
	int i;
	int pos;
	

	for (i = 0; i < n; i++)
	{
		if (a[i] == ele)
		{
			cout << "The element " << ele << " is found at position " << i << endl;
			pos = i;
			return pos;
		}
	}
	return -1;
}

int bin(int a[], int& n, int ele)
{
	int high = n - 1;
	int low = 0;
	int mid;

	cout << "Enter the ISBN number to be searched for: ";
	cin >> ele;

	bubsort(a, n);

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (ele == a[mid])
		{
			cout << "The element " << ele << " is found at position " << mid << endl << endl;
			return mid;
		}
		else
			if (ele < a[mid])
				high = mid - 1;
			else
				if (ele > a[mid])
					low = mid + 1;
				else
					cout << "The element is not found." << endl << endl;
	}
}

void delloc(int a[], int &n, int loc)
{
	int i;

	for (i = loc; i < n; i++)
		a[i] = a[i + 1];

	n--;
	cout << "The updated list is: " << endl << endl;
	print(a, n);
}

void delnum(int a[], int &n, int ele)
{
	int pos = lin(a, n, ele);
	delloc(a, n, pos);
}

void selsort(int *a, int &n)
{
	int j;
	for (int i = 0; i < n - 1; i++)
	{
		int sm = i;
		for (j = i + 1; j < n; j++)
		{
			if (*(a + j) < *(a + sm))	//comparing smallest value with all elements of the list
			{
				int temp = *(a + j);	//swapping the values
				*(a + j) = *(a + sm);
				*(a + sm) = temp;
			}
		}
		
	}

	cout << "The sorted list is: " << endl;
	print(a, n);
}

void bubsort(int *a, int& n)	//pointer to the array a
{
	int i;

	for (i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (*(a + j) > *(a + j + 1))
			{
				int temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
		}
	}
	cout << "The sorted list is: " << endl << endl;
	print(a, n);
}

void print(int a[], int &n)
{
	for (int i = 0; i < n; i++)
			cout << setw(4) << i + 1 << ".\t" << a[i] << endl;
}

int main()
{
	int val;
	int n = 0, element = 0, loc = 0, pos = 0;
	cout << "Welcome to the Book List Program." << endl;

	while (1)
	{
		cout << "What would you like to do?" << endl;
		cout << setw(4) << "1. Add an element to the end of the list." << endl;
		cout << setw(4) << "2. Add an element at a location in the list." << endl;
		cout << setw(4) << "3. Find an element by the ISBN number. (Linear Search)" << endl;
		cout << setw(4) << "4. Find an element by the ISBN number (Binary Search)." << endl;
		cout << setw(4) << "5. Delete an element at the position." << endl;
		cout << setw(4) << "6. Delete an element by ISBN number." << endl;
		cout << setw(4) << "7. Sort the list. (using selection sort)" << endl;
		cout << setw(4) << "8. Sort the list. (using bubble sort)" << endl;
		cout << setw(4) << "9. Print the list." << endl;
		cout << setw(4) << "10. Exit." << endl;
		cout << "Enter your choice: ";
		cin >> val;

		switch (val)
		{
		case 1: cout << "You have chosen to add an element at the end of the list." << endl;
			insert(a, n, element);
			break;

		case 2: cout << "You have chosen to add an element at a particular location in the list." << endl;
			insloc(a, n, loc, element);
			break;

		case 3: cout << "You have chosen to search for an element using the linear search algorothm." << endl;
			cout << "Enter the ISBN number to be searched for: ";
			cin >> element;
			lin(a, n, element);
			break;

		case 4: cout << "You have chosen to search for an element using the binary search algorithm." << endl;
			bin(a, n, element);
			break;

		case 5: cout << "You have chosen to delete an element from the list using its position." << endl;
			cout << "Enter the position of the element to be deleted from the list: ";
			cin >> loc;
			delloc(a, n, loc);
			break;

		case 6: cout << "You have chosen to delete an element from the list using the ISBN number." << endl;
			cout << "Enter the ISBN number to be deleted from the list: ";
			cin >> element;
			delnum(a, n, element);
			break;

		case 7: cout << "You have chosen to sort the list using the selection sort algorithm." << endl;
			selsort(a, n);
			break;

		case 8: cout << "You have chosen to sort the list using the bubble sort algorithm." << endl;
			bubsort(a, n);
			break;

		case 9: cout << "You have chosen to print the list." << endl;
			cout << "Your list is: " << endl;
			print(a, n);
			break;

		case 10: exit(0);
			break;

		default: cout << "Invalid choice. Please choose again." << endl;
			break;
		}
	}

	return 0;
}