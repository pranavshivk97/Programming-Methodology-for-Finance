#include<iostream>
#include<math.h>

using namespace std;

#include "tetrahedron.h"			//including the defined header file

tetrahedron::tetrahedron()			//default constructor
{
	setlen(len);
}

void tetrahedron::setlen(double lval)			//set teh length to be positive else print 0
{
	len = (lval < 0.0 ? 0.0 : lval);
}

double tetrahedron::getlen() const
{
	return len;					//return thr input
}

double tetrahedron::getarea() const
{
	return sqrt(3) * len * len;			//formula for surface area of a tetrahedron
}

double tetrahedron::getvol() const
{
	return len * len * len / (6 * sqrt(2));			//formula for volume of a tetrahedron
}

void tetrahedron::print() const		//print the resulting values
{
	cout << "The length of the regular tetrahedron with center [" << getx() << ", " << gety() << ", " << getz() << "]" << " is: " << len << endl;
	cout << "The surface area of the regular terahedron is: " << getarea() << endl;
	cout << "The volume of the regular tetrahedron is: " << getvol() << endl;
}