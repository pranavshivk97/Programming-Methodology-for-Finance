#include<iostream>
#include<math.h>

using namespace std;

#include "sphere.h"		//including the defined header file

sphere::sphere()		//defult constructor definition
{
	setrad(rad);
}

void sphere::setrad(double radval)
{
	rad = (radval < 0.0 ? 0.0 : radval);		//set the radius to be positive, else print 0
}

double sphere::getrad() const
{
	return rad;		//return the value 
}

double sphere::getarea() const
{
	return 4 * 3.14159 * rad * rad;		//formula for surface area of a sphere
}

double sphere::getvol() const
{
	return 4 * 3.14159 * rad * rad * rad / 3;		//formula for volume of a sphere
}

void sphere::print() const			//print the values
{
	cout << "The radius of the sphere with center [" << getx() << ", " << gety() << ", " << getz() << "]" << " is: " << rad << endl;
	cout << "The surface area of the sphere is: " << getarea() << endl;
	cout << "The volume of the sphere is: " << getvol() << endl << endl;
}