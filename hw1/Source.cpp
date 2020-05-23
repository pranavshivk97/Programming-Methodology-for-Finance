/*Name: Pranav Shivkumar
Submission Deadline: September 13th, 2019
Comparison of 5 numbers and display the maximum and minimum*/

#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, max, min;
	cout << "Enter any 5 numbers:" << endl;
	cin >> a >> b >> c >> d >> e;
	
	if ((a > b) && (a > c) && (a > d) && (a > e))
		max = a;
	else if ((b > c) && (b > d) && (b > e) && (b > a))
		max = b;
	else if ((c > d) && (c > e) && (c > a) && (c > b))
		max = c;
	else if ((d > e) && (d > a) && (d > b) && (d > c))
		max = d;
	else
		max = e;

	if ((a < b) && (a < c) && (a < d) && (a < e))
		min = a;
	else if ((b < c) && (b < d) && (b < e) && (b < a))
		min = b;
	else if ((c < d) && (c < e) && (c < a) && (c < b))
		min = c;
	else if ((d < e) && (d < a) && (d < b) && (d < c))
		min = d;
	else
		min = e;

	cout << "The maximum of the 5 numbers is:" << max << endl;
	cout << "The minimum of the 5 numbers is:" << min << endl;
}