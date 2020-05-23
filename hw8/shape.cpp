/*Name: Pranav Shivkumar
Title: Shape - Class Definition*/

#include<iostream>

using namespace std;

#include "shape.h"

shape::shape()			//defining the default constructor
{
	x = y = z = 0;
}

void shape::setx(int xval)			//getting the value of the x-coordinate from the user (input)
{
	cout << "Enter the x-coordinate: ";
	cin >> xval;
	x = xval;
}

int shape::getx() const				//returns the input value to the main function
{
	return x;
}

void shape::sety(int yval)			//getting the value of the y-coordinate from the user (input)
{
	cout << "Enter the y-coordinate: ";
	cin >> yval;
	y = yval;
}

int shape::gety() const				//returns the input value to the main function
{
	return y;
}

void shape::setz(int zval)			//getting the value of the z-coordinate from the user (input) (used for 3D coordinates only)
{
	cout << "Enter the z-coordinate: ";
	cin >> zval;
	z = zval;
}

int shape::getz() const				//returns the input value to the main function
{
	return z;
}





