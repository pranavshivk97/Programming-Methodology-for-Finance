/*Name: Pranav Shivkumar
Title: Program to print out a triangular formation*/
#include<iostream>
using namespace std;
int main()
{
	int i, j, n;
	cout << "Enter the number of lines in the shape:";
	cin >> n;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
	return(0);
}