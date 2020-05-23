#ifndef threed_h
#define threed_h

#include "shape.h"

class ThreeDimensionalShape : public shape		//derived public class ThreeDimensionalShape from base class Sphere
{
public: 
	ThreeDimensionalShape();	//constructor

	void setrad(double);	//set the radius
	double getrad() const;	//return radius

	void setlen(double);		//input length
	double getlen() const;		//return the input

private:
	double rad;
	double len;
};
#endif