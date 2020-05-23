/*Name: Pranav Shivkumar
Title: Shape - Class 2D Definition*/

#include <iostream>

using namespace std;

#include "twod.h"

TwoDimensionalShape::TwoDimensionalShape()			//defining the default constructor
{
	setrad(rad);
	setlen(len);
}

void TwoDimensionalShape::setrad(double radval)
{
	rad = (radval < 0.0 ? 0.0 : radval);		//ensure radius is a non-negative value
}

double TwoDimensionalShape::getrad() const
{
	return rad;					//return the value (positive else 0) to main  
}

void TwoDimensionalShape::setlen(double lval)
{
	len = (lval < 0.0 ? 0.0 : lval);		//ensure radius is a non-negative value
}

double TwoDimensionalShape::getlen() const
{
	return len;						//return the value (positive else 0) to main  
}