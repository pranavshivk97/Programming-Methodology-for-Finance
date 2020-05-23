/*Name: Pranav Shivkumar
Title: Shape - Class 2D*/

#ifndef twod_h
#define twod_h

#include<iostream>

using namespace std;

#include "shape.h"

class TwoDimensionalShape : public shape	//derived class TwoDimensionalShape inherited publically from base class Shape
{
public:
	TwoDimensionalShape();	//constructor

	void setrad(double);	//set the radius
	double getrad() const;	//return radius

	void setlen(double);		//input length
	double getlen() const;		//return the input


private:					//private members for radius and length
	double rad;
	double len;
};

#endif