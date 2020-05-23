#ifndef Booklist_lastname_h
#define Booklist_lastname_h

using namespace std;

class booklist
{
public:
	//declaring all member functions of the class

	booklist();		//declaring a default constructor
	void insert(int arr[], int& n, int ele);
	void insloc(int arr[], int& n, int loc, int ele);
	int lin(int arr[], int& n, int ele);
	int bin(int arr[], int& n, int ele);
	void delloc(int arr[], int& n, int loc);
	void delnum(int arr[], int& n, int ele);
	void selsort(int* arr, int& n);
	void bubsort(int* arr, int& n);
	void print(int arr[], int &n);

private:
	int n, ele, loc;

};

#endif