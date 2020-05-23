/*Name: Pranav Shivkumar
Title: Polynomial Class Main Function*/

#include<iostream>
#include<iomanip>

using namespace std;

#include "polynomial_pranav.h"		//including the defined header file 

int main()
{
	polynomial p1, p2, p3;			//instantiating objects of the class polynomial

	//entering the parameters for the polynomials
	cout << "Enter the first polynomial: " << endl;
	p1.input();			//inputting the 1st polynomial

	cout << "Enter the second polynomial: " << endl;
	p2.input();			//inputting the 2nd polynomial
	
	cout << endl;

	//printing the polynomials
	cout << "The first polynomial is: ";
	cout << p1 << endl;
	cout << endl;

	cout << "The second polynomial is: ";
	cout << p2 << endl;
	cout << endl;

	cout << "The sum of the polynomials (+) is: ";
	p3 = p1 + p2;
	cout << p3 << endl;			//printing the sum of the polynomials inputted by the user
	cout << endl;

	cout << "The difference of the polynomials is: ";
	p3 = p1 - p2;
	cout << p3 << endl;			//printing the difference of the polynomials inputted by the user
	cout << endl;

	cout << "+= gives: ";
	cout << (p1 += p2) << endl;
	cout << endl;

	cout << "-= gives: ";
	cout << (p1 -= p2) << endl;
	cout << endl;

	cout << "The product of the polynomials is: ";
	p3 = p1 * p2;
	cout << p3 << endl;			//printing the product of the polynomials inputted by the user
	cout << endl;

	cout << "*= gives: ";
	cout << (p1 *= p2) << endl;
	cout << endl;

	return 0;
} 