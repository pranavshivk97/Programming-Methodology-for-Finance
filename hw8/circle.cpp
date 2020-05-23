#include<iostream>

using namespace std;

#include "circle.h"

circle::circle()
{
	setrad(rad);
}

void circle::setrad(double radval)
{
	rad = (radval < 0.0 ? 0.0 : radval);		//set the radius so that the value is positive. otherwise, print 0
}

double circle::getrad() const
{
	return rad;					//return the resulting value
}

double circle::getarea() const
{
	return 3.14159 * rad * rad;		//formula to calculate area of a circle
}

void circle::print() const			//print the final values
{
	cout << "The radius of the circle with center [" << getx() << ", " << gety() << "]" << " is: " << rad << endl;
	cout << "The area of the circle is: " << getarea() << endl << endl;
}