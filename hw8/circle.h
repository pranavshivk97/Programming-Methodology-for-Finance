#ifndef circle_h
#define circle_h

#include "twod.h"

class circle : public TwoDimensionalShape			//deriving public class circle from class TwoDimensionalShape
{
public:
	circle();			//default constructor
	void setrad(double);		//member function to set the radius
	double getrad() const;		//member function to return the input

	double getarea() const;			//member functon to calculate the area

	void print() const;			//member function to print the area of the shape

private:
	double rad;
};
#endif
