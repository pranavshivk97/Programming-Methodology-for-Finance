#include<iostream>
#include<math.h>

using namespace std;

#include "triangle.h"

triangle::triangle()		//default constructor
{
	setlen(len);
}

void triangle ::setlen(double lval)
{
	len = (lval < 0.0 ? 0.0 : lval);			//set the length to a positive value else print 0
}

double triangle::getlen() const
{
	return len;			//return the resulting value
}

double triangle::getarea() const
{
	return sqrt(3) * len * len / 4;		//formula to calculate the area of the triangle (assuming equilateral)
}

void triangle::print() const		//print the final results
{
	cout << "The length of the triangle with center [" << getx() << ", " << gety() << "]" << " is: " << len << endl;
	cout << "The area of the triangle is: " << getarea() << endl << endl;
}