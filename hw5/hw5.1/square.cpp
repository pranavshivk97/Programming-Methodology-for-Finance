/*Name: Pranav Shivkumar
Title: Square of Numbers*/

#include<iostream>
using namespace std;

int n;

//Function Prototype
int square(int n, int m);	//m is the indicator to print in decreasing or ascending order
int square1(int n);

//Function Definition
int square(int n, int m)
{
	//if input is 1, square is 1
	if (n == 1)
		return 1;

	//if the input is even, decrement once and print square. Recurse until n = 1.
	if (n % 2 == 0)
	{
		if (m == 0)
		{
			n--;
			cout << n * n << ", ";
			return square(n - 2, m);
		}
	}

	//If the input is odd, print square and recurse until n = 1.
	else
	{
		if (m == 0)
		{
			cout << n * n << ", ";
			return square(n - 2, m);
		}
	}

	//if indicator is 1, print even squares
	if (m == 1)
	{
		m++;
		while (m < n)
		{
			cout << m * m << ", ";
			m += 2;
			return square1(m);
		}
	}

	return 0;
}

int square1(int n)
{
	//at the end, add square of the number. If even, print directly otherwise decrement and print
	if (n % 2 == 0)	
	{
		return n * n;
	}
	else
	{
		n--;
		return n * n;
	}
}

int main()
{
	cout << "Enter the value of n: ";
	cin >> n;
	cout << square(n, 0);
	cout << ", ";
	cout << square(n, 1) << ", " << square1(n);
	cout << endl;

	return 0;
}