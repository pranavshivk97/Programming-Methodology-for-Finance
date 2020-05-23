#include<iostream>
#include<iomanip>

#include"Booklist_lastname.h"

int main()
{
	int arr[20];
	int n = 0, loc = 0, ele = 0;
	int val;
	int pos = 0;
	
	booklist b;		//instantiating object of the class "booklist"

	//continuously display the menu
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
			b.insert(arr, n, ele);
			break;

		case 2: cout << "You have chosen to add an element at a particular location in the list." << endl;
			b.insloc(arr, n, loc, ele);
			break;

		case 3: cout << "You have chosen to search for an element using the linear search algorothm." << endl;
			cout << "Enter the ISBN number to be searched for: ";
			cin >> ele;
			b.lin(arr, n, ele);
			break;

		case 4: cout << "You have chosen to search for an element using the binary search algorithm." << endl;
			b.bin(arr, n, ele);
			break;

		case 5: cout << "You have chosen to delete an element from the list using its position." << endl;
			cout << "Enter the position of the element to be deleted from the list: ";
			cin >> loc;
			b.delloc(arr, n, loc);
			break;

		case 6: cout << "You have chosen to delete an element from the list using the ISBN number." << endl;
			cout << "Enter the ISBN number to be deleted from the list: ";
			cin >> ele;
			b.delnum(arr, n, ele);
			break;

		case 7: cout << "You have chosen to sort the list using the selection sort algorithm." << endl;
			b.selsort(arr, n);
			break;

		case 8: cout << "You have chosen to sort the list using the bubble sort algorithm." << endl;
			b.bubsort(arr, n);
			cout << "The sorted list is: " << endl << endl;
			b.print(arr, n);
			break;

		case 9: cout << "You have chosen to print the list." << endl;
			cout << "Your list is: " << endl;
			b.print(arr, n);
			break;

		case 10: exit(0);
			break;

		default: cout << "Invalid choice. Please choose again." << endl;
			break;
		}
	}

}