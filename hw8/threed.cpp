/*Name: Pranav Shivkumar
Title: Shape - Class 2D Definition*/

#include <iostream>

using namespace std;

#include "threed.h"

ThreeDimensionalShape::ThreeDimensionalShape()		//defining the default constructor
{
	setrad(rad);
	setlen(len);
}

void ThreeDimensionalShape::setrad(double radval)
{
	rad = (radval < 0.0 ? 0.0 : radval);		//ensure radius is a non-negative value
}

double ThreeDimensionalShape::getrad() const
{
	return rad;							//return the value (positive else 0) to main  
}

void ThreeDimensionalShape::setlen(double lval)
{
	len = (lval < 0.0 ? 0.0 : lval);		//ensure length is a non-negative value
}

double ThreeDimensionalShape::getlen() const
{
	return len;								//return the value (positive else 0) to main 
}