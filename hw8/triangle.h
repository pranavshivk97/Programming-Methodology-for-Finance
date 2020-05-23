#ifndef triangle_h
#define triangle_h

#include "twod.h"

class triangle : public TwoDimensionalShape				//deriving public class triangle from class TwoDimensionalShape
{
public:
	triangle();			//default constructor
	void setlen(double);			//set the length of the triangle
	double getlen() const;			//return the value

	double getarea() const;			//calculate the area of the triangle

	void print() const;			//print the corresponding values

private:
	double len;			//private member for length
};
#endif

